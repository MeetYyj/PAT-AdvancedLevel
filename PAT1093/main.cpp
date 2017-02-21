#include <iostream>
using namespace std;
int main() {
    int cntp = 0, cntpa = 0, cntpat = 0;
    char tmpc;
    while((tmpc = getchar()) != '\n'){
        switch(tmpc){
            case 'P':
                cntp++;
                break;
            case 'A':
                cntpa += cntp;
                break;
            case 'T':
                cntpat += cntpa;
                cntpat %= 1000000007;
                break;
            default:
                break;
        }
    }
    cout << cntpat;
    return 0;
}