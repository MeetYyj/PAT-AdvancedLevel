#include <iostream>
#include <stack>
using namespace std;
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1051/in1051", "r", stdin);
    int m, n, k;
    scanf("%d%d%d", &m, &n, &k);
    for (int i = 0; i < k; ++i) {
        stack<int> s;
        bool flg = true;
        int maxn;
        int g = 0;
        for (; g < n; ++g) {
            int tmp;
            scanf("%d", &tmp);
//            cout << tmp << ":";
            if(g == 0){
                if(tmp > m){
                    flg = false;
                    break;
                } else{
                    for (int j = 1; j <= tmp; ++j) {
                        s.push(j);
                    }
                    maxn = tmp;
                    s.pop();
                }
            } else {
                if(tmp > maxn){
                    for (int j = maxn + 1; j <= tmp; ++j) {
                        s.push(j);
                    }
                    maxn = tmp;
                    if(s.size() > m){
                        flg = false;
                        break;
                    }
                    s.pop();
                } else if(tmp == s.top()){
                    s.pop();
                } else{
                    flg = false;
                    break;
                }
            }
        }
        if(flg){
            printf("YES\n");
        }else{
            printf("NO\n");
            for (; g + 1 < n; ++g) {
                int tmp;
                scanf("%d", &tmp);
//                cout << tmp << ":";
            }
        }

//        cout << endl;
    }
    return 0;
}

//#include <cstdio>
//#include <stack>
//#include <vector>
//using namespace std;
//int main() {
//    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1051/in1051", "r", stdin);
//
//    int m, n, k;
//    scanf("%d %d %d", &m, &n, &k);
//    for(int i = 0; i < k; i++) {
//        bool flag = false;
//        stack<int> s;
//        vector<int> v(n + 1);
//        for(int j = 1; j <= n; j++)
//            scanf("%d", &v[j]);
//        int current = 1;
//        for(int j = 1; j <= n; j++) {
//            s.push(j);
//            if(s.size() > m) break;
//            while(!s.empty() && s.top() == v[current]) {
//                s.pop();
//                current++;
//            }
//        }
//        if(current == n + 1) flag = true;
//        if(flag) printf("YES\n");
//        else printf("NO\n");
//    }
//    return 0;
//}