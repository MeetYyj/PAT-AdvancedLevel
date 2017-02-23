#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
struct person{
    char name[9];
    int height;
};

bool sort1(const person &a, const person &b){
    if(a.height != b.height){
        return a.height > b.height;
    }else{
        return strcmp(a.name, b.name) < 0;
    }
}

int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1109/in1109a", "r", stdin);
    int num, line;
    scanf("%d %d\n", &num, &line);
    vector<person> vec;
    for (int i = 0; i < num; ++i) {
        person tmpp;
        scanf("%s %d\n", tmpp.name, &tmpp.height);
        vec.push_back(tmpp);
    }

    sort(vec.begin(), vec.end(), sort1);
    int normalnum = num / line;
    int lastnum = num / line + num % line;
    int cnt = 0;
    vector<person> vout(lastnum);
    for (int i = 0; i < lastnum; ++i) {
        if(i%2){
            vout[lastnum/2 - 1 -  i/2] = vec[cnt];
            cnt++;
        }else{
            vout[lastnum/2 + i/2] = vec[cnt];
            cnt++;
        }
    }
    for (int i = 0; i < lastnum; ++i) {
        if(i)
            printf(" ");
        printf("%s", vout[i].name);
    }
    printf("\n");

    for (int j = 0; j < line - 1; ++j) {
        vout.resize(normalnum);
        for (int i = 0; i < normalnum; ++i) {
            if(i%2){
                vout[normalnum/2 - 1 -  i/2] = vec[cnt];
                cnt++;
            }else{
                vout[normalnum/2 + i/2] = vec[cnt];
                cnt++;
            }
        }
        for (int i = 0; i < normalnum; ++i) {
            if(i)
                printf(" ");
            printf("%s", vout[i].name);
        }
        printf("\n");
    }


//    for (int i = 0; i < vec.size(); ++i) {
//        cout << vec[i].name << " " << vec[i].height << endl;
//    }
    return 0;
}