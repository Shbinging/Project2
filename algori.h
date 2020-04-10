#ifndef _algori_
#define _algori_
#include"diag.h"

vector<string> st_split(string st, char opt = ' '){
    vector<string> a;
    st += opt;
    string st1 = "";
    bool f = 0;
    For(i, 0, int(st.length()) - 1){
        if (st[i] != opt){
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
#endif