#include <iostream>
#include <string>
using namespace std;
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1073/in1073", "r", stdin);
    string s;
    cin >> s;
    int posE = (int)s.find_first_of('E');
    int posdot = (int)s.find_first_of('.');
    int digitlen = posE - posdot - 1;
    int pos_ = posE + 1;
    string sexp(s.begin()+pos_, s.end());
    int exp = stoi(sexp);
    if(s[0] == '-'){
        printf("-");
    }
    if(exp > 0){
        printf("%c", s[1]);
        if(digitlen <= exp){
            string subs(s.begin()+posdot+1, s.begin()+ posE);
            cout << subs;
            int tmp = exp - digitlen;
            while(tmp != 0){
                printf("0");
                tmp--;
            }
        }else{
            string subs(s.begin()+posdot+1, s.begin()+posdot+exp+1);
            cout << subs;
            cout << ".";
            string subs2(s.begin()+posdot+exp+1, s.begin()+posE);
            cout << subs2;
        }
    }else if(exp == 0){
        string subs(s.begin()+1, s.begin()+posE);
        cout << subs;
    }else{
        printf("0.");
        exp++;
        while(exp != 0){
            printf("0");
            exp++;
        }
        printf("%c", s[1]);
        string subs(s.begin()+posdot+1, s.begin()+posE);
        cout << subs;

    }
    return 0;
}