#include <iostream>
using namespace std;
string sn[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int main() {
    string nums;
    cin >> nums;
    if(stoi(nums) == 0){
        printf("ling");
        return 0;
    }
    if(nums[0] == '-'){
        printf("Fu ");
        nums = nums.substr(1);
    }
    int len = (int)nums.length();
    int cnt = 0;
    if(len == 9){
        cout << sn[nums[cnt] - '0'] << " Yi";
        cnt++;
    }
    for (int i = 0; i < len - 1; ++i) {
        if(nums[i] == '0' && nums[i + 1] == '0'){
            nums[i] = '#';
        }
    }
//    cout << nums << endl;
    while(cnt < len){
        if(nums[cnt] != '#'){
            if(nums[cnt] == '0' && (len - cnt == 1 || len - cnt == 5)){
                ;
            }else{
                if(cnt){
                    printf(" ");
                }
                cout << sn[nums[cnt] - '0'];
            }
            bool zeroflg = true;
            if(nums[cnt] == '0'){
                zeroflg = false;
            }
            cnt++;
            if((len - cnt == 7 || len - cnt == 3) && zeroflg){
                printf(" Qian");
            }
            if((len - cnt == 6 || len - cnt == 2) && zeroflg){
                printf(" Bai");
            }
            if((len - cnt == 5 || len - cnt == 1) && zeroflg){
                printf(" Shi");
            }
        }else{
            cnt++;
        }
        if(len - cnt == 4){
            printf(" Wan");
        }
    }
    return 0;
}