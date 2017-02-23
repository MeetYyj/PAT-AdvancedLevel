#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1105/in1105", "r", stdin);
    int num;
    scanf("%d", &num);
    vector<int> vec;
    for (int i = 0; i < num; ++i) {
        int tmp;
        scanf("%d", &tmp);
        vec.push_back(tmp);
    }
    sort(vec.rbegin(), vec.rend());
    int m, n;
    m = (int)sqrt(num);
    if(num == m * m){
        n = m;
    }else{
        m++;
        while(num % m){
            m++;
        }
        n = num / m;
    }
    int vout[m][n];
    int left = 0, right = n - 1, up = 0, down = m - 1;
    bool flg = false;
    int cnt = 0;
    while(cnt != num){
        for (int i = left; i <= right && !flg; ++i) {
            vout[up][i] = vec[cnt++];
            if(cnt == num){
                flg = true;
                break;
            }
        }
        up++;

        for (int i = up; i <= down && !flg ; ++i) {
            vout[i][right] = vec[cnt++];
            if(cnt == num){
                flg = true;
                break;
            }
        }
        right--;

        for (int i = right; i >= left && !flg; --i) {
            vout[down][i] = vec[cnt++];
            if(cnt == num){
                flg = true;
                break;
            }
        }
        down--;
        for (int i = down; i >= up && !flg; --i) {
            vout[i][left] = vec[cnt++];
            if(cnt == num){
                flg = true;
                break;
            }
        }
        left++;
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(j)
                printf(" ");
            printf("%d", vout[i][j]);
        }
        printf("\n");
    }
    return 0;
}