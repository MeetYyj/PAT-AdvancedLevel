#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define maxx 26 * 26 * 26 * 10 + 1
using namespace std;

int hashN(char* c){
    return (c[0] - 'A') * 26 * 26 * 10 +
            (c[1] - 'A') * 26 * 10+
            (c[2] - 'A') * 10 +
            (c[3] - '0');
}

int main(){
    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1039/in1039", "r", stdin);
    int numstu, numcourse;
    scanf("%d %d\n", &numstu, &numcourse);
    vector<vector<int>> vec(maxx);
    for (int i = 0; i < numcourse; ++i) {
        int indexcou, stunum;
        scanf("%d %d\n", &indexcou, &stunum);
//        cout << indexcou << " " << stunum << endl;
        for (int j = 0; j < stunum; ++j) {
            char name[5];
            scanf("%s", name);
            int hashname = hashN(name);
            vec[hashname].push_back(indexcou);
        }
    }
    for (int i = 0; i < numstu; ++i) {
        char name[5];
        scanf("%s", name);
        int hashname = hashN(name);
        printf("%s %d", name, vec[hashname].size());
        if(vec[hashname].size() == 0){
            printf("\n");
        } else{
            sort(vec[hashname].begin(), vec[hashname].end());
            for (int j = 0; j < vec[hashname].size(); ++j) {
                printf(" %d", vec[hashname][j]);
            }
            printf("\n");
        }
    }
    return 0;
}


//struct stu{
//    vector<int> cou;
//};
//bool sort1(const int &a, const int &b){
//    return a < b;
//}
//
//int main() {
//    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1039/in1039", "r", stdin);
//    int numstu, numcourse;
//    scanf("%d %d\n", &numstu, &numcourse);
////    cout << numstu << " " << numcourse << endl;
//    map<string, stu> map1;
//    for (int i = 0; i < numcourse; ++i) {
//        int indexcou, stunum;
//        scanf("%d %d\n", &indexcou, &stunum);
////        cout << indexcou << " " << stunum << endl;
//        for (int j = 0; j < stunum; ++j) {
//            string str;
//            char tmpc[5];
//            scanf("%s", tmpc);
//            str = tmpc;
//            map1[str].cou.push_back(indexcou);
//        }
////        getchar();
//    }
//    for (int i = 0; i < numstu; ++i) {
//        string str;
//        char tmpc[5];
//        scanf("%s", tmpc);
//        str = tmpc;
//        sort(map1[str].cou.begin(), map1[str].cou.end(), sort1);
//        printf("%s %d", tmpc, map1[str].cou.size());
////        cout << str << " " << map1[str].cou.size();
//        if (map1[str].cou.size() == 0){
//            ;
//        } else{
//            for (int j = 0; j < map1[str].cou.size(); ++j) {
//                printf(" %d", map1[str].cou[j]);
//            }
//        }
//        printf("\n");
//    }
//    return 0;
//}