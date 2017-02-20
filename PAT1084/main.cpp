#include <iostream>
#include <vector>
using namespace std;
bool checked[256];
int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1084/in1084", "r", stdin);
    string instr, outstr;
    cin >> instr >> outstr;
    vector<char> vecc;
    int index = 0;
    for (int i = 0; i < instr.length(); ++i) {
        if(instr[i] != outstr[index]){
            vecc.push_back(instr[i]);
        } else{
            index++;
        }
    }
    for (int i = 0; i < vecc.size(); ++i) {
        if('a' <= vecc[i] && vecc[i] <= 'z'){
            vecc[i] = vecc[i] - 'a' + 'A';
        }
        if(!checked[vecc[i]]){
            printf("%c", vecc[i]);
            checked[vecc[i]] = true;
        }
    }

    return 0;
}
//#include <iostream>
//using namespace std;
//bool checked[37];
//int main() {
//    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1084/in1084", "r", stdin);
//    string instr, outstr;
//    cin >> instr >> outstr;
//    int index = 0;
//    for (int i = 0; i < instr.length(); ++i) {
//        if(instr[i] != outstr[index]){
//            if('a' <= instr[i] && instr[i] <= 'z'){
//                if(!checked[instr[i] - 'a' + 10]){
//                    printf("%c", instr[i] - 'a' + 'A');
//                }
//                checked[instr[i] - 'a' + 10] = true;
//            } else if('A' <= instr[i] && instr[i] <= 'Z'){
//                if(!checked[instr[i] - 'A' + 10]){
//                    printf("%c", instr[i]);
//                }
//                checked[instr[i] - 'A' + 10] = true;
//            } else if('0' <= instr[i] && instr[i] <= '9'){
//                if(!checked[instr[i] - '0']){
//                    printf("%c", instr[i]);
//                }
//                checked[instr[i] - '0'] = true;
//            }else{
//                if(!checked[36]){
//                    printf("_");
//                }
//                checked[36] = true;
//            }
//        } else{
//            index++;
//        }
//    }
//
//
//    return 0;
//}