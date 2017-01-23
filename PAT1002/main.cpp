#include <iostream>
#include <vector>

using namespace std;
struct term{
    int exponent;
    double coefficient;
};
int main() {
    freopen("/home/yyj/ClionProjects/AdvancedPat/PAT1002/in1002", "r", stdin);
    int firstTerm, secondTerm;
    scanf("%d", &firstTerm);
    vector<struct term> v1;
    for (int i = 0; i < firstTerm; ++i) {
        term tmp;
        scanf("%d %lf", &tmp.exponent, &tmp.coefficient);
        v1.push_back(tmp);
    }



    scanf("%d", &secondTerm);
    vector<struct term> v2;
    for (int i = 0; i < secondTerm; ++i) {
        term tmp;
        scanf("%d %lf", &tmp.exponent, &tmp.coefficient);
        v2.push_back(tmp);
    }

//    for (int j = 0; j < v2.size(); ++j) {
//        printf(" %d %.1lf", v2[j].exponent, v2[j].coefficient);
//    }
//    cout << endl;

    int index1 = 0, index2 = 0;
    vector<struct term> resultv;
    while(index1 < firstTerm && index2 < secondTerm){
        if(v1[index1].exponent > v2[index2].exponent){
            resultv.push_back(v1[index1]);
            index1++;
        } else if (v1[index1].exponent == v2[index2].exponent){
            term tmp;
            tmp.exponent = v1[index1].exponent;
            tmp.coefficient = v1[index1].coefficient + v2[index2].coefficient;
            if(tmp.coefficient != 0){
                resultv.push_back(tmp);
            }
            index1++;
            index2++;
        } else {
            resultv.push_back(v2[index2]);
            index2++;
        }
    }
    if(index1 == firstTerm){
        for (index2; index2 < secondTerm; ++index2) {
            resultv.push_back(v2[index2]);
        }
    } else {
        for (index1; index1 < firstTerm; ++index1) {
            resultv.push_back(v1[index1]);
        }
    }
    cout << resultv.size();
    for (int j = 0; j < resultv.size(); ++j) {
        printf(" %d %.1lf", resultv[j].exponent, resultv[j].coefficient);
    }
    return 0;
}