#ifndef _dir_
#define _dir_
#include "diag.h"

struct fileNode{
    fileNode(){
        file = NULL;
        file1 = NULL;
        name = "";
        fileType = 0;
        r = 0;
        w = 0;
        x = 0;
    }
    fileNode(struct stat tmp, const char* st, int dep = 1){
        if (S_ISDIR(tmp.st_mode)) fileType = 1;
        else fileType = 0;
        r = tmp.st_mode & S_IRUSR;
        w = tmp.st_mode & S_IWUSR;
        x = tmp.st_mode & S_IXUSR;
        name = st;
        file = fopen(st, "rb");
        file1 = fopen(st, "r");
        time = tmp.st_mtime;
        depth = dep;
    }
    string name;
    bool fileType;//0 file 1 dir
    bool r, w, x;// read write excute
    FILE* file, *file1;  
    time_t time;  
    int depth;
};

class Dir{
public:
    Dir();
    vector<string> fileContent;
    vector<fileNode> fileTree;//dirctory list
    char oriPath[3000];//homepath
    char homePath[3000];

    bool setpath(string path = ".");//original the shell's location
    bool setpath1(string path = ".");
    void setHome();
    void setOri();

    string getPath();
    bool ispathExsist(string path);//1 Exsist 0 not Exsist
    bool isFile(string path);//1 file 0 dir
    
    void closeFileTree();

    vector<fileNode>& getfileTree(string path, int depMax = 1000000000);
    vector<string>& getfileContent(string path);

    fileNode getfile(string path);

    bool makeDir(string);//1 ok 0 dirfail
    int makeFileTree(vector<fileNode>&, string);//1 ok 0 fail
    bool makeDir(fileNode);//V1.1 is to add time and root check
    bool makeFile(fileNode);

    private:
        int MAXN;
        void initPath();
        void printdir(const char*, int, int);

};
extern Dir dir;
#endif