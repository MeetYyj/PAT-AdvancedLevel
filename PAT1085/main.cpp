#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> vec;
long long binarysearch(long long a){
    long long left = 0, right = (long long)vec.size();
    long long mid = (left + right) / 2;
    while(left < right){
        if(vec[mid] > a){
            right = mid;
        } else{
            left = mid + 1;
        }
        mid = (left + right) / 2;
    }
    return left;
}
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1085/in1085c", "r", stdin);
    long long num, p;
    scanf("%lld%lld", &num, &p);
    for (long long i = 0; i < num; ++i) {
        long long tmp;
        scanf("%lld", &tmp);
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    long long res = 0;
    for (long long i = 0; i < vec.size(); ++i) {
        long long maxx = vec[i] * p;
        long long indexmax = binarysearch(maxx);
//        cout << indexmax << " " << i << " " << indexmax - i << endl;
        if(indexmax - i > res){
            res = indexmax - i;
        }
    }
    cout << res;
    return 0;
}