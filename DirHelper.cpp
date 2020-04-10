#include "DirHelper.h"

vector<fileNode> fileTree;

Dir::Dir(){
    MAXN = 3000;
    initPath();
}
void Dir::initPath(){
    getcwd(oriPath, MAXN);
}

bool Dir::setpath(string path){//original the shell's location 1 exceed 0 fail
    if (chdir(path.c_str()) == 0) return 1;
    else return 0;
}

bool Dir::ispathExsist(string path){//1 Exsist 0 not Exsist
    struct stat statbuf;
    if (stat(path.c_str(), &statbuf) == 0) return 1;
    else return 0;
}

void Dir::printdir(const char *dir, int depth)//run all over the dir
{
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
    	if ((dp = opendir(dir)) == NULL) {
		fprintf(stderr, "Can`t open directory %s\n", dir);
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
			printdir(entry->d_name, depth+1);
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

vector<fileNode>& Dir::getfileTree(string path){
    fileTree.clear();
    printdir(path.c_str(), 0);
    setpath(oriPath);
    return fileTree;
}

bool Dir::makeFile(fileNode tmp){
    FILE* fout = fopen(tmp.name.c_str(), "bw");
    FILE* fin = tmp.file;
    if (fin == NULL|| fout == NULL) return 0;
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
        makeDir(a);
        return 1;
    }
    else return 0;
}

void Dir::makeFileTree(vector<fileNode>& fileTree, string path){
    setpath(oriPath);
    setpath(path);
    int depth = 1;
    For(i, 0, int(fileTree.size()) - 1){
        fileNode tmp = fileTree[i];
     char pwd[500];
	getcwd(pwd, 500);
	printf("\ngetcwd pwd is %s\n",pwd);
        if (tmp.fileType == 1){
                depth += 1;
                setpath(tmp.name);
        }
        else{
            if (tmp.depth < depth){
                depth--;
                setpath("..");
            }
            makeFile(tmp);
        }
    }
}

fileNode Dir::getfile(string path){
    struct stat statbuf;
    stat(path.c_str(), &statbuf);
    return fileNode(statbuf, path.c_str());
}

Dir dir;