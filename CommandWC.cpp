#include"CommandWC.h"

int CommandWC::run(string st){
    vector<string> a = st_split(st);
    if (a.size() != 3) return 2;
    string path = a[2];
    if (!dir.ispathExsist(a[2])) return 10;
    if (!dir.isFile(a[2])) return 11;
    vector<int> b = calc(dir.getfile(path), path);
    if (b[0] == -1) return 16;
    if (a[1] == "-c"){
        printf("number of byte is %d\n", b[0]);
    }
    else 
    if (a[1] == "-w"){
        printf("number of word is %d\n", b[1]);
    }
    else
    if (a[1] == "-l"){
        printf("number of line is %d\n", b[2]);
    }
    else return 17;
    return 14;
}

vector<int> CommandWC::calc(fileNode tmp, string path){
    FILE* fin = tmp.file;
    vector<int> ans;
    if (fin == NULL){
        ans.push_back(-1);
        return ans;
    }
    char ch;
    int s = 0;
    fread(&ch, sizeof(char), 1, fin);
    while(!feof(fin)){
        s += 1 ;
        fread(&ch, sizeof(char), 1, fin);
    }
    rewind(fin);
    ans.push_back(s);
    int MAXN = 100000;
    char ch1[MAXN];
    vector<string> & b = dir.getfileContent(path);
    int ls = 0;
    s = 0;
    For(i, 0, int(b.size()) -1){
        string st = b[i];
        vector<string>  a = st_split(st);
        s += a.size();
        if (st != "") ls++;
    }
    ans.push_back(s);
    ans.push_back(ls);
    return ans;
}
