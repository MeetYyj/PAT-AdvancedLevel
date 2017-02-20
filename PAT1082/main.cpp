#include <iostream>
using namespace std;
string sn[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int main() {
    string nums;
    cin >> nums;
    if(nums[0] == '-'){
        cout << "Fu ";
        nums = nums.substr(1);
    }
    int len = (int)nums.length();
    bool spaceflg = false;
    int cnt = 0;
    return 0;
}