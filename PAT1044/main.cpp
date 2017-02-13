//#include <iostream>
//#include <vector>
//using namespace std;
//int main() {
//    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1044/in1044a", "r", stdin);
//    int num, cost;
//    scanf("%d %d\n", &num, &cost);
//    vector<int> vec;
//    for (int i = 0; i < num; ++i) {
//        int tmp;
//        scanf("%d", &tmp);
//        vec.push_back(tmp);
//    }
//    vector<vector<int>> vout;
//    int mincost = 100000001;
//    for (int i = 0; i < vec.size(); ++i) {
//        int sum = 0;
//        for (int j = i; j < vec.size() && sum < cost;++j) {
//            sum += vec[j];
//            if(sum >= cost && sum < mincost){
//                mincost = sum;
//                vector<int> vtmp;
//                vtmp.push_back(i);
//                vtmp.push_back(j);
//                vout.resize(0);
//                vout.push_back(vtmp);
//                break;
//            } else if(sum == mincost){
//                vector<int> vtmp;
//                vtmp.push_back(i);
//                vtmp.push_back(j);
//                vout.push_back(vtmp);
//                break;
//            }
//        }
//    }
//    for (int i = 0; i < vout.size(); ++i) {
//        printf("%d-%d\n", vout[i][0]+1, vout[i][1]+1);
//    }
//    return 0;
//}
#include <iostream>
#include <vector>
int sum[100001];
using namespace std;
int num, cost;
int mincost = 100000001;
int righttmp;
vector<vector<int>> vout;
int bs(int i){
    int left = i + 1, right = num;
    int mid;
    while(left < right){
        mid = (left + right) / 2;
        if(sum[mid] - sum[i] >= cost){
            right = mid;
        } else{
            left = mid + 1;
        }
    }
    righttmp = right;
    return sum[right] - sum[i];

};
int main(){
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1044/in1044", "r", stdin);
    scanf("%d %d\n", &num, &cost);
    for (int i = 0; i < num; ++i) {
        scanf("%d", &sum[i + 1]);
        sum[i + 1] += sum[i];
    }

    for (int i = 0; i < num; ++i) {
        int costtmp = bs(i);
        if(costtmp < cost){
            break;
        }else if(costtmp < mincost){
            vector<int> vectmp;
            vectmp.push_back(i+1);
            vectmp.push_back(righttmp);
            mincost = costtmp;
            vout.clear();
            vout.push_back(vectmp);
        } else if(costtmp == mincost){
            vector<int> vectmp;
            vectmp.push_back(i+1);
            vectmp.push_back(righttmp);
            vout.push_back(vectmp);
        }
    }
    for (int i = 0; i < vout.size(); ++i) {
        printf("%d-%d\n", vout[i][0], vout[i][1]);
    }
    return 0;
}