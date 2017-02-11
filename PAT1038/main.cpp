#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const string &a, const string &b){
    long long aint = stoi(a), bint = stoi(b);
    long long apb = 0, bpa = 0;
    apb = bint + aint * pow(10, b.size());
    bpa = aint + bint * pow(10, a.size());
    return apb < bpa;
}
int main() {
//    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1038/in1038", "r", stdin);
    int num;
    scanf("%d", &num);
    vector<string> vec;
    for (int i = 0; i < num; ++i) {
        string str;
        cin >> str;
        vec.push_back(str);
    }
    sort(vec.begin(), vec.end(), cmp);
    int index = 0;
    int flg0 = true;
    for (int i = 0; i < vec.size(); ++i) {
        if(i == index){
            if(stoi(vec[i]) == 0){
                index++;
            } else{
                flg0 = false;
            }
            bool flg = true;
            for (int j = 0; j < vec[i].size(); ++j) {
                if(flg){
                    if (vec[i][j] == '0'){
                        ;
                    } else {
                        flg = false;
                        cout << vec[i][j];
                    }
                } else{
                    cout << vec[i][j];
                }
            }
        } else{
            cout << vec[i];
        }
    }
    if(flg0){
        cout << 0;
    }
    return 0;
}

//#include <string>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//bool cmp0(string a, string b) {
//    return a + b < b + a;
//}
//string str[10010];
//int main() {
//    int n;
//    scanf("%d", &n);
//    for(int i = 0; i < n; i++)
//        cin >> str[i];
//    sort(str, str + n, cmp0);
//    string s;
//    for(int i = 0; i < n; i++)
//        s += str[i];
//    while(s.length() != 0 && s[0] == '0')
//        s.erase(s.begin());
//    if(s.length() == 0)
//        cout << 0;
//    else
//        cout << s;
//    return 0;
//}