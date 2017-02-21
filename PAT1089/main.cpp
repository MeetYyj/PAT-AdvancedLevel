#include <iostream>
#include <vector>
using namespace std;
vector<int> invec;
vector<int> cmpvec;
vector<int> insertvec;
vector<int> mergevec;
vector<int> tmpvec;
bool insertflg;
void insertsort(){
    insertvec = invec;
    int i = 1;
    for (; i < insertvec.size(); ++i) {
        int tmp = insertvec[i];
        int j = i - 1;
        for (; j >= 0 && tmp < insertvec[j] ; --j) {
            insertvec[j + 1] = insertvec[j];
        }
        insertvec[j + 1] = tmp;
//        for (int j = 0; j < i; ++j) {
//            if(tmp < insertvec[j]){
//                for (int k = i; k > j; --k) {
//                    insertvec[k] = insertvec[k - 1];
//                }
//                insertvec[j] = tmp;
//                break;
//            }
//        }
        if(insertvec == cmpvec){
            insertflg = true;
            break;
        }
    }

    if(insertflg){
        int tmp = insertvec[++i];
        int j = i - 1;
        for (; j >= 0 && tmp < insertvec[j] ; --j) {
            insertvec[j + 1] = insertvec[j];
        }
        insertvec[j + 1] = tmp;
//        for (int j = 0; j < i; ++j) {
//            if(tmp < insertvec[j]){
//                for (int k = i; k > j; --k) {
//                    insertvec[k] = insertvec[k - 1];
//                }
//                insertvec[j] = tmp;
//                break;
//            }
//        }
        printf("Insertion Sort\n");
        for (int k = 0; k < insertvec.size(); ++k) {
            if(k != 0)
                printf(" ");
            printf("%d", insertvec[k]);
        }
    }
}


void merge(int s1, int e1, int s2, int e2){
//    cout << s1 << " " << e1 << " " << s2 << " " << e2 << endl;
    tmpvec = mergevec;
    int index1 = s1, index2 = s2, index = s1;
    for (;index1 <= e1 && index2 <= e2;) {
        if(mergevec[index1] <= mergevec[index2]){
            tmpvec[index++] = mergevec[index1++];
        }else{
            tmpvec[index++] = mergevec[index2++];
        }
    }
    if(index1 > e1){
        for (int i = index2; i <= e2 ; ++i) {
            tmpvec[index++] = mergevec[i];
        }
    }else{
        for (int i = index1; i <= e1 ; ++i) {
            tmpvec[index++] = mergevec[i];
        }
    }
    mergevec = tmpvec;
}

void mergesort(int radix, int flg){
//    cout << radix << endl;
    if(flg != 0){
        int length = (int)mergevec.size();
        int cnt = 0;
        int s1, e1, s2, e2;
        while(length >= 2 * radix){
            s1 = cnt * 2 * radix;
            e1 = cnt * 2 * radix + radix - 1;
            s2 = cnt * 2 * radix + radix;
            e2 = cnt * 2 * radix + 2 * radix - 1;
            merge(s1, e1, s2, e2);
            length -= 2 * radix;
            cnt++;
        }
        if(length > radix){
            s1 = cnt * 2 * radix;
            e1 = cnt * 2 * radix + radix - 1;
            s2 = cnt * 2 * radix + radix;
            e2 = cnt * 2 * radix + length - 1;
            merge(s1, e1, s2, e2);
            cnt++;
            length = 0;
        }
        if(cmpvec == mergevec){
            flg = 2;
        }
        if(radix < mergevec.size()){
            mergesort(radix * 2, flg - 1);
        }
    }

}



int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1089/in1089", "r", stdin);
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; ++i) {
        int tmp;
        scanf("%d", &tmp);
        invec.push_back(tmp);
    }
    for (int i = 0; i < num; ++i) {
        int tmp;
        scanf("%d", &tmp);
        cmpvec.push_back(tmp);
    }
    insertsort();
    if(insertflg){
        ;
    }else{
        printf("Merge Sort\n");
        mergevec = invec;
        mergesort(1, -1);
        for (int j = 0; j < mergevec.size(); ++j) {
            if(j != 0)
                printf(" ");
            printf("%d", mergevec[j]);
        }
    }
    return 0;
}