#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int booknum;
int requestnum;
struct book{
    int id;
    char title[81];
    char author[81];
    vector<string> keywords;
    char publisher[81];
    int year;
}books[10001];

void inputbookinfo(int index){
    //input id
    scanf("%d\n", &books[index].id);
    char tmpc;
    int i = 0;
    //input tilte
    while((tmpc = getchar()) != '\n'){
        books[index].title[i] = tmpc;
        i++;
    }
    books[index].title[i] = '\0';
    //input auhtor
    i = 0;
    while((tmpc = getchar()) != '\n'){
        books[index].author[i] = tmpc;
        i++;
    }
    books[index].author[i] = '\0';
    //input kewords
    char tmpkeywords[11];
    i = 0;
    while((tmpc = getchar()) != '\n'){
        if(tmpc != ' '){
            tmpkeywords[i] = tmpc;
            i++;
        } else{
            tmpkeywords[i] = '\0';
            string tmps = tmpkeywords;
            books[index].keywords.push_back(tmps);
            i = 0;
        }
    }
    tmpkeywords[i] = '\0';
    string tmps = tmpkeywords;
    books[index].keywords.push_back(tmps);
    //input publisher
    i = 0;
    while((tmpc = getchar()) != '\n'){
        books[index].publisher[i] = tmpc;
        i++;
    }
    books[index].publisher[i] = '\0';
    //input year
    scanf("%d\n", &books[index].year);
}

void titlefunc(string str){
    vector<int> ivec;
    for (int i = 0; i < booknum; ++i) {
        string strtitle = books[i].title;
        if(strtitle == str){
            ivec.push_back(books[i].id);
        }
    }
    cout << "1: " << str << endl;
    if(ivec.empty()){
        printf("Not Found\n");
    }else{
        sort(ivec.begin(), ivec.end());
        for (int j = 0; j < ivec.size(); ++j) {
            printf("%07d\n", ivec[j]);
        }
    }
}

void authorfunc(string str){
    vector<int> ivec;
    for (int i = 0; i < booknum; ++i) {
        string strauthor = books[i].author;
        if(strauthor == str){
            ivec.push_back(books[i].id);
        }
    }
    cout << "2: " << str << endl;
    if(ivec.empty()){
        printf("Not Found\n");
    }else{
        sort(ivec.begin(), ivec.end());
        for (int j = 0; j < ivec.size(); ++j) {
            printf("%07d\n", ivec[j]);
        }
    }
}

void keywordsfunc(string str){
    vector<int> ivec;
    for (int i = 0; i < booknum; ++i) {
        for (int j = 0; j < books[i].keywords.size(); ++j) {
            string strkeywords = books[i].keywords[j];
            if(strkeywords == str){
                ivec.push_back(books[i].id);
            }
        }
    }
    cout << "3: " << str << endl;
    if(ivec.empty()){
        printf("Not Found\n");
    }else{
        sort(ivec.begin(), ivec.end());
        for (int j = 0; j < ivec.size(); ++j) {
            printf("%07d\n", ivec[j]);
        }
    }
}

void publisherfunc(string str){
    vector<int> ivec;
    for (int i = 0; i < booknum; ++i) {
        string strpublisher = books[i].publisher;
        if(strpublisher == str){
            ivec.push_back(books[i].id);
        }
    }
    cout << "4: " << str << endl;
    if(ivec.empty()){
        printf("Not Found\n");
    }else{
        sort(ivec.begin(), ivec.end());
        for (int j = 0; j < ivec.size(); ++j) {
            printf("%07d\n", ivec[j]);
        }
    }
}

void yearfunc(string str){
    vector<int> ivec;
    int yeartmp = stoi(str);
    for (int i = 0; i < booknum; ++i) {
        if(books[i].year == yeartmp){
            ivec.push_back(books[i].id);
        }
    }
    cout << "5: " << str << endl;
    if(ivec.empty()){
        printf("Not Found\n");
    }else{
        sort(ivec.begin(), ivec.end());
        for (int j = 0; j < ivec.size(); ++j) {
            printf("%07d\n", ivec[j]);
        }
    }
}

void searchfunc(){
    int asknum;
    scanf("%d: ", &asknum);
    char tmpc;
    char tmpcm[81];
    string tmps;
    int i = 0;
    while((tmpc = getchar()) != '\n'){
        tmpcm[i] = tmpc;
        i++;
    }
    tmpcm[i] = '\0';
    tmps = tmpcm;
    switch (asknum){
        case 1:
            titlefunc(tmps);
            break;
        case 2:
            authorfunc(tmps);
            break;
        case 3:
            keywordsfunc(tmps);
            break;
        case 4:
            publisherfunc(tmps);
            break;
        case 5:
            yearfunc(tmps);
            break;
        default:
            break;
    }
}

int main() {
    freopen("/home/yyj/Code/PAT-AdvancedLevel/PAT1022/in1022", "r", stdin);
    scanf("%d\n", &booknum);
    for (int i = 0; i < booknum; ++i) {
        inputbookinfo(i);
    }
//    for (int i = 0; i < booknum; ++i) {
//        cout << books[i].keywords.size() << " ";
//        for (int j = 0; j < books[i].keywords.size(); ++j) {
//            cout << books[i].keywords[j] << ":";
//        }
//        cout << endl;
//    }
    scanf("%d\n", &requestnum);
    for (int j = 0; j < requestnum; ++j) {
        searchfunc();
    }
    return 0;
}

//#include <iostream>
//#include <cstdio>
//#include <map>
//#include <set>
//using namespace std;
//map<string, set<int> > title, author, key, pub, year;
//void query(map< string, set<int> > &m, string &str) {
//    if(m.find(str) != m.end()) {
//        for(set<int>::iterator it = m[str].begin(); it != m[str].end(); it++)
//            printf("%07d\n", *it);
//    } else
//        cout << "Not Found\n";
//}
//int main() {
//    int n, m, id, num;
//    scanf("%d", &n);
//    string ttitle, tauthor, tkey, tpub, tyear;
//    for(int i = 0; i < n; i++) {
//        scanf("%d", &id);
//        getchar();
//        getline(cin, ttitle);
//        title[ttitle].insert(id);
//        getline(cin, tauthor);
//        author[tauthor].insert(id);
//        while(cin >> tkey) {
//            key[tkey].insert(id);
//            char c;
//            c = getchar();
//            if(c == '\n') break;
//        }
//        getline(cin, tpub);
//        pub[tpub].insert(id);
//        getline(cin, tyear);
//        year[tyear].insert(id);
//    }
//    scanf("%d", &m);
//    for(int i = 0; i < m; i++) {
//        scanf("%d: ", &num);
//        string temp;
//        getline(cin, temp);
//        cout << num << ": " << temp << "\n";
//        if(num == 1) query(title, temp);
//        else if(num == 2) query(author, temp);
//        else if(num == 3) query(key, temp);
//        else if(num == 4) query(pub,temp);
//        else if(num ==5) query(year, temp);
//    }
//    return 0;
//}