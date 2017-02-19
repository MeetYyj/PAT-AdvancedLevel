#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1071/in1071", "r", stdin);
    char tmp;
    string s;
    map<string, int> map1;
    vector<string> vs;
    int cntmax = 0;
    while((tmp = getchar()) != '\n'){
        if(('0' <= tmp && tmp <= '9') || ('A' <= tmp && tmp <= 'Z') || ('a' <= tmp && tmp <= 'z')){
            if('A' <= tmp && tmp <= 'Z')
                tmp = tmp - 'A' + 'a';
            s.push_back(tmp);
        } else{
            if(!s.empty()) {
                int cnttmp = ++map1[s];
                if(cnttmp > cntmax){
                    cntmax = cnttmp;
                }
                s.clear();
            }
        }
    }
    if(!s.empty()) {
        int cnttmp = ++map1[s];
        if(cnttmp > cntmax){
            cntmax = cnttmp;
        }
        s.clear();
    }
    auto map_it = map1.begin();
    for (;map_it != map1.end(); ++map_it) {
        if((*map_it).second == cntmax)
            vs.push_back((*map_it).first);
    }
    sort(vs.begin(), vs.end());
    cout << vs[0] << " " << cntmax << endl;
    return 0;
}