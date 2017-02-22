#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> vecall;
vector<int> vtmp;
void calfunc(int n, int k, int p, int s){
    if(n == 0){

    }else if(k == 1){
        int sq = (int)sqrt(n);
        vtmp.push_back(sq);
        if(pow(sq, p) == n && sq <= s){
            vecall.push_back(vtmp);
        }
        vtmp.pop_back();
    } else{
        for (int i = s; i >= 1 ; --i) {
            int tmpn = n - pow(i, p);
            int tmps = (int)sqrt(tmpn) < i ? (int)sqrt(tmpn) : i;
            vtmp.push_back(i);
            calfunc(tmpn, k - 1, p , tmps);
            vtmp.pop_back();
        }
    }
}

bool sort1(const vector<int> &a, const vector<int> &b){
    int suma = 0, sumb = 0;
    for (int i = 0; i < a.size(); ++i) {
        suma += a[i];
        sumb += b[i];
    }
    if(suma != sumb){
        return suma > sumb;
    }else{
        return a > b;
    };
}

int main() {
//    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1103/in1103", "r", stdin);
    int n, k, p;
    scanf("%d%d%d", &n, &k, &p);
    int s = (int)sqrt(n);
    calfunc(n, k, p, s);
//    for (int i = 0; i < vecall.size(); ++i) {
//        for (int j = 0; j < vecall[i].size(); ++j) {
//            cout << vecall[i][j] << " ";
//        }
//        cout << endl;
//    }
    //169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2
    if(vecall.size() == 0){
        printf("Impossible");
    }else{
        sort(vecall.begin(), vecall.end(), sort1);
        printf("%d = ", n);
        for (int i = 0; i < k; ++i) {
            if(i){
                printf(" + ");
            }
            printf("%d^%d", vecall[0][i], p);
        }
    }

    return 0;
}