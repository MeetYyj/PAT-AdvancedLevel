#include <iostream>
using namespace std;
void simplefunc(long &a, long &b){
    if(a == 0){
        b = 1;
        return;
    }
    long tmpa = abs(a), tmpb = abs(b), tmp;
    while(tmpa % tmpb){
        tmp = tmpa % tmpb;
        tmpa = tmpb;
        tmpb = tmp;
    }
    a /= tmpb;
    b /= tmpb;
}

void print(long a, long b){
    if(abs(a)/(b)){
        if(a<0){
            if(abs(a)%b){
                printf("(%ld %ld/%ld)", a/b, abs(a)%b, b);
            }else{
                printf("(%ld)", a/b);
            }
        }else{
            if(abs(a)%b){
                printf("%ld %ld/%ld", a/b, abs(a)%b, b);
            }else{
                printf("%ld", a/b);
            }
        }
    } else{
        if(a<0){
            printf("(%ld/%ld)", a, b);
        }else if(a == 0){
            printf("0");
        }else{
            printf("%ld/%ld", a, b);
        }
    }
}

int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1088/in1088b", "r", stdin);
    long a1, a2, b1, b2;
    scanf("%ld/%ld %ld/%ld", &a1, &a2, &b1, &b2);
    simplefunc(a1, a2);
//    cout << a1 << " " << a2 << endl;
    simplefunc(b1, b2);
//    cout << b1 << " " << b2 << endl;
    long add1, add2, diff1, diff2, prod1, prod2, quo1, quo2;
    add1 = a1 * b2 + a2 * b1;
    add2 = a2 * b2;
    simplefunc(add1, add2);
    print(a1, a2);
    printf(" + ");
    print(b1, b2);
    printf(" = ");
    print(add1, add2);
    printf("\n");

//    cout << add1 << " " << add2 << endl;
    diff1 = a1 * b2 - a2 * b1;
    diff2 = a2 * b2;
    simplefunc(diff1, diff2);
    print(a1, a2);
    printf(" - ");
    print(b1, b2);
    printf(" = ");
    print(diff1, diff2);
    printf("\n");
//    cout << diff1 << " " << diff2 << endl;
    prod1 = a1 * b1;
    prod2 = a2 * b2;
    simplefunc(prod1, prod2);
    print(a1, a2);
    printf(" * ");
    print(b1, b2);
    printf(" = ");
    print(prod1, prod2);
    printf("\n");
    quo1 = a1 * b2;
    quo2 = a2 * b1;
    print(a1, a2);
    printf(" / ");
    print(b1, b2);
    printf(" = ");
    if(quo2 == 0){
        printf("Inf");
    }else{
        if(quo2 < 0){
            quo2 = -quo2;
            quo1 = -quo1;
        }
        simplefunc(quo1, quo2);
        print(quo1, quo2);
    }
    printf("\n");

//    cout << prod1 << " " << prod2 << endl;



    return 0;
}