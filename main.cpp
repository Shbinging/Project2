#include "DirHelper.h"
#include "CommandCP.h"
int main(){
    //char pwd[500];
	/* getcwd(pwd, 500);
	printf("\ngetcwd pwd is %s\n",pwd);*/
    
    /* getcwd(pwd, 500);
	printf("\ngetcwd pwd is %s\n",pwd);*/
    /* For(i, 0, int(fileTree.size() - 1)){
      For(j, 1, fileTree[i].depth) cout << "\t";
        cout << fileTree[i].name;
        if (fileTree[i].fileType == 1) cout << "/";
        cout << endl;
    }*/
    //printf("%d\n", isFile(".."));
    /* vector<fileNode> & fileTree = dir.getfileTree(".");
    cout << dir.makeDir("../test1") << endl;
    dir.makeFileTree(fileTree, "../test1");
    dir.setpath(dir.oriPath);
    fileTree = dir.getfileTree("../test1");
    */
   /* For(i, 0, int(fileTree.size() - 1)){
      For(j, 1, fileTree[i].depth) cout << "\t";
        cout << fileTree[i].name;
        if (fileTree[i].fileType == 1) cout << "/";
        cout << endl;
    }*/
    string st;
    getline(cin, st);
    CommandCP a;
    cout << a.run(st);
    return 0;
}