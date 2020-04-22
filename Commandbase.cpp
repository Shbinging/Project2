#include"Commandbase.h"

void CommandBase::help(string path){
    dir.setOri();
    vector<string>& b = dir.getfileContent(path);
    For(i, 0, int(b.size()) - 1){
        cout << b[i];
    }
    cout << endl;
    dir.setHome();
}

CommandBase::CommandBase(Dir& tmp):dir(tmp){

}