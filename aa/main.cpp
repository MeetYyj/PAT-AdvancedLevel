#include <iostream>
#include <vector>
using namespace std;
void func(vector<int> &a){
    a.push_back(1);
}
int main() {
    vector<int> a;
    func(a);
    cout << a << endl;
    return 0;
}