#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool isprime(int a){
    if (a <= 1)
        return false;
    if (a == 2)
        return true;
    for (int i = 2; i < sqrt(a) + 1; ++i) {
        if((a % i)== 0)
            return false;
    }
    return true;
}

int main() {
//    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1015/in1015", "r", stdin);
    while (1){
        int innum;
        scanf("%d", &innum);
        if(innum < 0){
            return 0;
        }
        else{
            int radix;
            scanf("%d", &radix);
            if(isprime(innum)){
                vector<int> ivec;
                while (innum != 0){
                    ivec.push_back(innum % radix);
                    innum /= radix;
                }
                int tmp = 0;
                for (int i = 0; i < ivec.size(); ++i) {
                    tmp += ivec[i] * pow(radix, ivec.size() - i - 1);
                }
                if (isprime(tmp)){
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            } else {
                cout << "No" << endl;
            }

        }
    }
    return 0;
}

//int isPrime(int n){
//    int i;
//    if(n<2) return 0;
//    for(i=2;i*i<=n;i++){
//        if(n%i==0) return 0;
//    }
//    return 1;
//}
//int change(int n,int d){
//    int i,j,b[100],cnt=0;
//    while(n){
//        b[cnt]=n%d;
//        cnt++;
//        n=n/d;
//    }
//    int ans=0;
//    for(i=cnt-1;i>=0;i--){
//        int tmp=1;
//        for(j=0;j<cnt-1-i;j++){
//            tmp=tmp*d;
//        }
//        ans=ans+b[i]*tmp;
//    }
//    return ans;
//}
//int main(){
//    int i,j,n,d;
//    while(scanf("%d",&n)){
//        if(n<0) break;
//        scanf("%d",&d);
//        int rn=change(n,d);
//        if(isPrime(n)&&isPrime(rn))
//            printf("Yes\n");\
//        else
//            printf("No\n");
//
//    }
//    return 0;
//} 