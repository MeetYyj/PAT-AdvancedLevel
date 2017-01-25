#include <iostream>
#include <vector>

using namespace std;
double res[2001];
bool isExist[2001];
int cnt = 0;
struct node{
    int exp = 0;
    double coef = 0;
};

int main() {
    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1009/in1009", "r", stdin);
    fill(res, res+2000, 0);
    fill(isExist, isExist+2000, false);
    vector<node> v1, v2;
    int num1, num2;
    scanf("%d", &num1);
    for (int i = 0; i < num1; ++i) {
        node tmp;
        scanf(" %d %lf", &tmp.exp, &tmp.coef);
        v1.push_back(tmp);
    }
    scanf("%d", &num2);
    for (int i = 0; i < num2; ++i) {
        node tmp;
        scanf(" %d %lf", &tmp.exp, &tmp.coef);
        v2.push_back(tmp);
    }

//    cout << v1[1].coef << v2[1].coef << endl;

    for (int i = 0; i < v1.size(); ++i) {
        for (int j = 0; j < v2.size(); ++j) {
            res[v1[i].exp + v2[j].exp] += v1[i].coef * v2[j].coef;
            isExist[v1[i].exp + v2[j].exp] = (bool)res[v1[i].exp + v2[j].exp];
        }
    }
    for (int i = 0; i < 2001; ++i) {
        if(isExist[i])
            cnt++;
    }
    printf("%d", cnt);
    for (int i = 2000; i >= 0; --i) {
        if(isExist[i]){
            printf(" %d %.1lf", i, res[i]);
        }
    }
    return 0;
}