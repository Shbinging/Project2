#include "DirHelper.h"



Dir::Dir(string path){
    MAXN = 3000;
    if (path == "."){
        getcwd(homePath, MAXN);
    }
    else{
        strcpy(homePath, path.c_str());
        setpath1(path);
    }
}


void Dir::setHome(){
    chdir(homePath);
}

void Dir::setOri(){
    chdir(oriPath);
}

string Dir::getPath(){
    char pwd[MAXN];
	getcwd(pwd, MAXN);
	string tmp = pwd;
    return tmp;
}

bool Dir::setpath1(string path){
    if (chdir(path.c_str()) == 0){
        getcwd(homePath, MAXN);
        return 1;
    }
    else return 0;
}
bool Dir::setpath(string path){//original the shell's location 1 exceed 0 fail
    if (chdir(path.c_str()) == 0){
        return 1;
    }
    else return 0;
}

bool Dir::ispathExsist(string path){//1 Exsist 0 not Exsist
    struct stat statbuf;
    if (stat(path.c_str(), &statbuf) == 0) return 1;
    else return 0;
}

void Dir::printdir(const char *dir, int depth, int depMax)//run all over the dir
{
    if (depth > depMax) return;
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
    	if ((dp = opendir(dir)) == NULL) {
		return ;
	}
    chdir(dir);
	while ((entry = readdir(dp)) != NULL) {
		lstat(entry->d_name, &statbuf);
		if (S_ISDIR(statbuf.st_mode)) {
			if (strcmp(entry->d_name, ".") == 0 || 
				strcmp(entry->d_name, "..") == 0 )  
				continue;	
			fileTree.push_back(fileNode(statbuf, entry->d_name, depth+1));
			printdir(entry->d_name, depth+1, depMax);
		} 
        else
			fileTree.push_back(fileNode(statbuf, entry->d_name, depth+1));
	}
	chdir("..");
	closedir(dp);	
}

bool Dir::isFile(string path){//1 file 0 dir
    struct stat statbuf;
    stat(path.c_str(), &statbuf);
    if (S_ISDIR(statbuf.st_mode)) return 0;
    else return 1;
}

void Dir::closeFileTree(){
    For(i, 0, int(fileTree.size()) - 1){
        if (fileTree[i].file != NULL) fclose(fileTree[i].file);
        if (fileTree[i].file1 != NULL) fclose(fileTree[i].file1);
    }
    fileTree.clear();
}

vector<fileNode>& Dir::getfileTree(string path, int depMax){
    closeFileTree();
    printdir(path.c_str(), 0, depMax);
    setHome();
    return fileTree;
}

bool Dir::makeFile(fileNode tmp){
    FILE* fout = fopen(tmp.name.c_str(), "wb");
    FILE* fin = tmp.file;
    if (fin == NULL|| fout == NULL) {fclose(fout);return 0;}
    char ch;
    fread(&ch, sizeof(char), 1, fin);
    while(!feof(fin)){
        fwrite(&ch, sizeof(char), 1, fout);
        fread(&ch, sizeof(char), 1, fin);
    }
    fclose(fout);
    rewind(fin);
    return 1;
}

bool Dir::makeDir(fileNode tmp){
    if (!ispathExsist(tmp.name)){
        if (mkdir(tmp.name.c_str(), 0777) != -1) return 1;
        else return 0;
    }
    else return 0;
}

bool Dir::makeDir(string path){
    if (!ispathExsist(path)){
        fileNode a;
        a.fileType = 1;
        a.name = path;
        return makeDir(a);
    }
    else return 0;
}

int Dir::makeFileTree(vector<fileNode>& fileTree, string path){
    setHome();
    setpath(path);
    int depth = 1;
    For(i, 0, int(fileTree.size()) - 1){
        fileNode tmp = fileTree[i];
        if (tmp.fileType == 1){
                depth += 1;
                if (!makeDir(tmp)) return 0;
                setpath(tmp.name);
        }
        else{
            if (tmp.depth < depth){
                depth--;
                setpath("..");
            }
            if (!makeFile(tmp)) return 0;
        }
    }
    setHome();
    return 1;
}

fileNode Dir::getfile(string path){
    struct stat statbuf;
    stat(path.c_str(), &statbuf);
    return fileNode(statbuf, path.c_str());
}

vector<string>& Dir::getfileContent(string path){
    FILE* fin = getfile(path).file;
    fileContent.clear();
    if (fin == NULL){
        fileContent.push_back("NULL");
        return fileContent;
    }
    int MAXN = 100000;
    char ch1[MAXN];
    while(fgets(ch1, MAXN, fin) != NULL){
        string st = ch1;
        string st1 = "";
        fileContent.push_back(st);
    }
    fclose(fin);
    return fileContent;
}

char Dir::oriPath[3000];