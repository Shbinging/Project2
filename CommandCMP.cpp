#include"CommandCMP.h"

int CommandCMP::run(string st){
    vector<string> a = st_split(st);
    if (a.size() != 3) return 2;
    if (!dir.ispathExsist(a[1])) return 10;
    if (!dir.isFile(a[1])) return 11;
    if (!dir.ispathExsist(a[2])) return 10;
    if (!dir.isFile(a[2])) return 11;
    FILE* fin1 = dir.getfile(a[1]).file1;
    FILE* fin2 = dir.getfile(a[2]).file1;
    if (fin1 == NULL && fin2 == NULL) return 16;
    int MAXN = 10000;
    char ch1[MAXN], ch2[MAXN];
    bool eq = 1;
    For(i, 1, 2){
        int s = 0;
    while(fgets(ch1, MAXN, fin1) != NULL){
        s++;
        if (fgets(ch2, MAXN, fin2) == NULL){
            printf("not equal!\n");
            printf("line:%d Column:%d\n", s, 1);
            eq = 0;
            break;
        }else{
            if (strlen(ch1) != strlen(ch2)){
                    printf("not equal!\n");
                    printf("line:%d Column:%d\n", s, min(strlen(ch1), strlen(ch2)) + 1);
                    eq = 0;
                    break;
            }
            else{ 
                int k;
                For(i, 0, int(strlen(ch1)) - 1){
                    k++;
                    if (ch1[i] != ch2[i]){
                    printf("not equal!\n");
                    printf("line:%d Column:%d\n", s, k);
                    eq = 0;
                    break;
                    }
                }
                if (!eq) break;
            }
        }
    }
    if (!eq) break;
    rewind(fin1);
    rewind(fin2);
    swap(fin1, fin2);
    }
    if (eq) printf("equal!\n");
    fclose(fin1);
    fclose(fin2);
    return 14;
}
