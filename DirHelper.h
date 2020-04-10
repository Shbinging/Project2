#ifndef _DIRHLEPER_
#define _DIRHELPER_
#include "diag.h"

struct fileNode{
    fileNode(){
        file = NULL;
        name = "";
        fileType = 0;
        r = 0;
        w = 0;
        x = 0;
    }
    fileNode(struct stat tmp, const char* st, int dep = 0){
        if (S_ISDIR(tmp.st_mode)) fileType = 1;
        else fileType = 0;
        r = tmp.st_mode & S_IRUSR;
        w = tmp.st_mode & S_IWUSR;
        x = tmp.st_mode & S_IXUSR;
        name = st;
        file = fopen(st, "rb");
        time = tmp.st_mtime;
        depth = dep;
    }
    string name;
    bool fileType;//0 file 1 dir
    bool r, w, x;// read write excute
    FILE* file;  
    time_t time;  
    int depth;
};

class Dir{
public:
    Dir();
    vector<fileNode> fileTree;
    bool setpath(string path = ".");//original the shell's location
    bool ispathExsist(string path);//1 Exsist 0 not Exsist
    bool isFile(string path);//1 file 0 dir
    void initPath();
    void printdir(const char*, int);
    vector<fileNode>& getfileTree(string path);
    fileNode getfile(string path);
    int MAXN;
    char oriPath[3000];
    bool makeDir(string);
    void makeFileTree(vector<fileNode>&, string);
    bool makeDir(fileNode);//V1.1 is to add time and root check
    bool makeFile(fileNode);
};
extern Dir dir;
#endif