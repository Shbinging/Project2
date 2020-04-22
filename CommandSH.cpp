#include"CommandSH.h"
#include"UI.h"
int CommandSH::run(string st){
    vector<string> a = st_split(st);
    if (a.size() != 2) return 2;
    string path = a[1];
    if (!dir.ispathExsist(path)) return 10;
    vector<string>& b = dir.getfileContent(path);
    if (path.rfind("/") != string::npos){
        path.erase(path.begin() + path.rfind("/"), path.end());
    }
    else path = ".";
    if (b[0] == "NULL") return 16;
    else{
        UI a(path);
        for(int i = 0; i < b.size(); i++){
            string st = st_edit(b[i]);
            if (st.empty()) continue;
            cout<< st<<endl;
            if (st[0] == '#') continue;
            int rt = a.running(st);
            if (rt != 14) cout << a.wrongCode[rt] << endl;
        }
        return 14;
    }
}
