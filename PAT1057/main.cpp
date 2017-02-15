#include <iostream>
#include <stack>
#define maxn 100010
using namespace std;
int c[maxn];

int lowbit(int a){
    return a&(-a);
}

void update(int i, int f){
    while(i < maxn){
        c[i] += f;
        i += lowbit(i);
    }
}

int getsum(int i){
    int sum = 0;
    while(i){
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}

int peekmedian(int k){
    int left = 0, right = maxn, mid;
    while(left < right){
        mid = (left + right)/2;
//        if(getsum(mid) == k){
//            return mid;
//        }else if(getsum(mid) > k){
//            right = mid - 1;
//        }else{
//            left = mid + 1;
//        }
        if(getsum(mid) >= k){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return left;
}

int main(){
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1057/in1057", "r", stdin);
    int num;
    scanf("%d", &num);
    stack<int> s;
    for (int i = 0; i < num; ++i) {
        char ctmp[11];
        scanf("%s", ctmp);
        if(ctmp[1] == 'u'){
            int itmp;
            scanf("%d", &itmp);
            s.push(itmp);
            update(itmp, 1);
        }else if(ctmp[1] == 'o'){
            if(s.empty()){
                printf("Invalid\n");
            }else{
                update(s.top(), -1);
                printf("%d\n", s.top());
                s.pop();
            }
        }else{
            if(s.empty()){
                printf("Invalid\n");
            }else{
                int k = (int)(s.size() + 1 )/ 2;
                int r = peekmedian(k);
                printf("%d\n", r);
            }
        }
    }
    return 0;
}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct node{
//    int data;
//    node *pre = NULL;
//    node *next = NULL;
//    node *lastinsert = NULL;
//};
//node *startn = NULL, *endn = NULL, *lastn = NULL;
//int length = 0;
//void func(int oper){
//    switch (oper){
//        case 1:
//            int tmp;
//            scanf("%d", &tmp);
//            if(!startn){
//                node *tmpnode = new node;
//                startn = tmpnode;
//                tmpnode->data = tmp;
//                endn = tmpnode;
//                lastn = tmpnode;
//                length++;
//            }else{
//                node *i = startn;
//                for (; i ; i = i->next) {
//                    if(tmp < i->data){
//                        node *tmpnode = new node;
//                        if(i != startn){
//                            tmpnode->pre = i->pre;
//                            tmpnode->next = i;
//                            tmpnode->data = tmp;
//                            tmpnode->lastinsert = endn;
//                            endn = tmpnode;
//                            i->pre->next = tmpnode;
//                            i->pre = tmpnode;
//                        } else{
//                            tmpnode->pre = i->pre;
//                            tmpnode->next = i;
//                            tmpnode->data = tmp;
//                            tmpnode->lastinsert = endn;
//                            endn = tmpnode;
//                            i->pre = tmpnode;
//                            startn = tmpnode;
//                        }
//
//                        break;
//                    }
//                    if(!i->next){
//                        node *tmpnode = new node;
//                        tmpnode->pre = i;
//                        tmpnode->next = NULL;
//                        tmpnode->data = tmp;
//                        tmpnode->lastinsert = endn;
//                        endn = tmpnode;
//                        i->next = tmpnode;
//                        lastn = tmpnode;
//                        break;
//                    }
//                }
//                length++;
//            }
//            break;
//        case 2:
//            if(length){
//                printf("%d\n", endn->data);
//                if(endn == startn){
//                    startn = startn->next;
//                    node *tmpnode = endn;
//                    endn = endn->lastinsert;
//                    if(length != 1){
//                        tmpnode->next->pre = tmpnode->pre;
//                    }
//                } else if(endn == lastn){
//                    node *tmpnode = endn;
//                    endn = endn->lastinsert;
//                    tmpnode->pre->next = tmpnode->next;
//                } else{
//                    node *tmpnode = endn;
//                    endn = endn->lastinsert;
//                    tmpnode->next->pre = tmpnode->pre;
//                    tmpnode->pre->next = tmpnode->next;
//                }
//                length--;
//            }else{
//                printf("Invalid\n");
//            }
//            break;
//        case 3:
//            if(!length){
//                printf("Invalid\n");
//            }else{
//                node *s = startn;
//                int cnto;
//                if(length%2){
//                    cnto = (length+1)/2 - 1;
//                }else{
//                    cnto = length/2 - 1;
//                }
//                for (int j = 0; j < cnto; ++j) {
//                    s = s->next;
//                }
//                printf("%d\n", s->data);
//            }
//            break;
//        default:
//            break;
//    }
//------------------
//    cout << "len:" << length << endl;
//    for (node *i = startn; i; i = i->next) {
//        cout << i->data << " ";
//    }
//    cout << ":::::" << endl;
//------------------
//}
//int main() {
//    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1057/in1057", "r", stdin);
//    int num;
//    scanf("%d", &num);
//    for (int i = 0; i < num; ++i) {
//        char ctmp[11];
//        int oper;
//        scanf("%s", ctmp);
//        if(ctmp[1] == 'u'){
//            oper = 1;
//        }else if(ctmp[1] == 'o'){
//            oper = 2;
//        }else{
//            oper = 3;
//        }
//        func(oper);
//    }
//    return 0;
//}