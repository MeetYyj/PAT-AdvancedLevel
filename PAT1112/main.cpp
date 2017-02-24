#include <iostream>
#include <vector>
using namespace std;
bool isgood[256];
bool isexit[256];
int main() {
//    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1112/in1112", "r", stdin);
    int num;
    string str;
    scanf("%d\n", &num);
    cin >> str;
    vector<char> vec;
    for (int i = 0; i < (str.length() - num + 1); ++i) {
        int flg = true;
        if(!isexit[str[i]])
            vec.push_back(str[i]);
        isexit[str[i]] = true;
        for (int j = i + 1; j < i + num; ++j) {
            if(str[j] != str[i]){
                flg = false;
                isgood[str[i]] = true;
                break;
            }
        }
        if(flg){
            i += num - 1;
        }
    }
    for (int i = 0; i < vec.size(); ++i) {
        if(!isgood[vec[i]]){
            printf("%c", vec[i]);
        }
    }
    printf("\n");
    for (int i = 0; i < str.length(); ++i) {
        if(isgood[str[i]]){
            printf("%c", str[i]);
        }else{
            printf("%c", str[i]);
            i += num - 1;
        }
    }

    return 0;
}