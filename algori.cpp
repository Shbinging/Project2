#include"algori.h"

vector<string> st_split(string st, char opt1, char opt2){
    vector<string> a;
    st += opt1;
    string st1 = "";
    bool f = 1;
    For(i, 0, int(st.length()) - 1){
        if (st[i] != opt1 && st[i] != opt2 && st[i] != '\r' && st[i] != '\n'){
            if (f == 1){
                f = 0;
                st1 = "";
            }
            st1 += st[i];
        }else{
            if (f == 0){
                f = 1;
                a.push_back(st1);
            }
        }
    }
    return a;
}

string st_edit(string st){
    string tmp = "";
    for (int i = 0; i < st.length(); i++){
        if (st[i] != '\r' && st[i] != '\n') tmp += st[i];
    }
    return tmp;
}