#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct station{
    double price;
    double miles;
};
double tank, allmiles, davg;
int stanum;
int currentstation = 0;
double currenttank = 0;
double cost = 0;
double milefinal = 0;
vector<station> vecp;
bool sort1(const station &a, const station &b){
    return a.miles < b.miles;
}

void findnext(){
    while(1){
        int minsta = currentstation;
        double minprice = vecp[currentstation].price;
        int i;
        bool canarrive = false;
        for (i = currentstation + 1; vecp[i].miles - vecp[currentstation].miles <= tank * davg; ++i) {
            canarrive = true;
            if(vecp[i].price <= minprice){
                minsta = i;
                break;
            }
        }
        if(canarrive){
            //if we find a cheaper station
            if(minsta != currentstation){
                if(currenttank * davg < vecp[minsta].miles - vecp[currentstation].miles){
                    cost += ((vecp[minsta].miles - vecp[currentstation].miles) / davg - currenttank)* vecp[currentstation].price;
//                cout << "mile2:" << vecp[minsta].miles << " mile1:" << vecp[currentstation].miles << " davg:" << davg << " tank:" << currenttank << " p:"<< vecp[currentstation].price << endl;
                    currenttank = 0;
                } else{
                    currenttank -= (vecp[minsta].miles - vecp[currentstation].miles) / davg;
                }
                currentstation = minsta;
            }
                //if not
            else{
                cost += (tank - currenttank) * vecp[currentstation].price;
                currenttank = tank - (vecp[currentstation + 1].miles - vecp[currentstation].miles) / davg;
                currentstation++;
            }
            if(i == vecp.size()){
                return;
            }
        } else {
            milefinal = vecp[currentstation].miles + tank * davg;
            return;
        }
//        cout << "tank:" << currenttank << " sta:" << currentstation << " cost:" << cost << endl;
    }


}

int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1033/in1033b", "r", stdin);
    scanf("%lf %lf %lf %d\n", &tank , &allmiles, &davg, &stanum);
    for (int i = 0; i < stanum; ++i) {
        station tmp;
        scanf("%lf %lf", &tmp.price, &tmp.miles);
//        if(tmp.miles == allmiles)
//            continue;
        vecp.push_back(tmp);
    }
    station tmp;
    tmp.miles = allmiles;
    tmp.price = 0;
    vecp.push_back(tmp);
    sort(vecp.begin(), vecp.end(), sort1);

    findnext();
    if(vecp[0].miles != 0){
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    if(milefinal){
        printf("The maximum travel distance = %.2lf", milefinal);
    }else{
        printf("%.2lf", cost);
    }
//    for (int i = 0; i < vecp.size(); ++i) {
//        cout << vecp[i].price << " " << vecp[i].miles << endl;
//    }
    return 0;
}