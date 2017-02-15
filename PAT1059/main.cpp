#include <iostream>
#include <map>
using namespace std;
int main() {
    long int a, ra;
    scanf("%ld", &a);
    ra = a;
    if(a == 1){
        printf("1=1");
        return 0;
    }
    map<long int,int> ma;
    long int cnt = 2;
    while(a != 1){
        for (long int i = cnt; i <= a; ++i) {
            if(!(a%i)){
                a/=i;
                ma[i]++;
                cnt = i;
                break;
            }
        }
    }
    printf("%ld=",ra);
    auto map_it = ma.cbegin();
    while(map_it != ma.cend()){
        if(map_it != ma.cbegin()){
            printf("*");
        }
        if(map_it->second != 1){
            printf("%ld^%d", map_it->first, map_it->second);
        } else {
            printf("%ld", map_it->first);
        }
        ++map_it;
    }
    return 0;
}