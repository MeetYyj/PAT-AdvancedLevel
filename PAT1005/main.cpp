#include <iostream>
#include <vector>

using namespace std;
string a[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    char tmp;
    int sum = 0;
    while((tmp = getchar()) != '\n'){
        sum += tmp - '0';
    }
    vector<int> iv;
    if (sum == 0){
        iv.push_back(0);
    }
    while(sum != 0){
        iv.push_back(sum%10);
        sum/=10;
    }
    for (int i = 0; i < iv.size(); ++i) {
        if(i != 0){
            cout << " ";
        }
        cout << a[iv[iv.size() - i - 1]];
    }
    return 0;
}