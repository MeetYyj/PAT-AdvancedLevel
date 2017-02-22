#include <iostream>
#include <vector>

using namespace std;
int num;
vector<int> invec, cmpvec;
vector<int> heapvec;
bool insertsort(){
    bool flg = false;
    vector<int> insertv = invec;
    int i = 1;
    for (; i < num; ++i) {
        int tmp = insertv[i];
        int j = i - 1;
        for (; j >= 0 && tmp < insertv[j]; --j) {
            insertv[j + 1] = insertv[j];
        }
        insertv[j + 1] = tmp;
        if(insertv == cmpvec){
            flg = true;
            break;
        }
    }
    if(flg){
        printf("Insertion Sort\n");
        int tmp = insertv[++i];
        int j = i - 1;
        for (; j >= 0 && tmp < insertv[j]; --j) {
            insertv[j + 1] = insertv[j];
        }
        insertv[j + 1] = tmp;
        for (int k = 0; k < insertv.size(); ++k) {
            if(k != 0)
                printf(" ");
            printf("%d", insertv[k]);
        }
    }
    return flg;
}

void perdown(int i, int n){
    int tmp = heapvec[i];
    int child;
    int parent;
    for (parent = i; (parent * 2 + 1) < n; parent = child) {
        child = parent * 2 + 1;
        if((child != n - 1) && (heapvec[child + 1] > heapvec[child])){
            child++;
        }
        if(heapvec[child] > tmp){
            heapvec[parent] =  heapvec[child];
        }else{
            break;
        }
    }
    heapvec[parent] = tmp;
}

void heapsort(){
    heapvec = invec;
    int i;
    for (i = (int)heapvec.size()/2 - 1; i >= 0 ; --i) {
        perdown(i, (int)heapvec.size());
    }
    for (i = (int)heapvec.size() - 1; i > 0 ; --i) {
        if(heapvec == cmpvec){
            break;
        }
        swap(heapvec[0], heapvec[i]);
        perdown(0, i);
    }
    printf("Heap Sort\n");
    swap(heapvec[0], heapvec[i]);
    perdown(0, i);
    for (int k = 0; k < heapvec.size(); ++k) {
        if(k != 0)
            printf(" ");
        printf("%d", heapvec[k]);
    }
}

int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1098/in1098a", "r", stdin);
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
    bool isinsert = insertsort();
    if(!isinsert){
        heapsort();
    }



    return 0;
}