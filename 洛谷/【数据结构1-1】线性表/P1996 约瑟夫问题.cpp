#include<iostream>

using namespace std;

typedef struct person{
    int num;
    person *next;
}person;

int n, m;
int idx = 1;
person plist[105];

void initList(int n){
    for (int i = 0; i < n; i++)
    {
        plist[i].num = i + 1;
        if(i < n - 1){
            plist[i].next = &plist[i + 1];
        }
        else{
            plist[i].next = &plist[0];
        }
    }
}
int main(){
    cin >> n >> m;
    initList(n);
    person *phead = plist;
    while(true){
        person ptmp = *phead->next;
        if(ptmp.num == phead->num){
            cout << ptmp.num << " ";
            break;
        }
        if(idx == m - 1){
            cout << ptmp.num << " ";
            phead->next = ptmp.next;
            phead = phead->next;
            idx = 1;
        }
        else{
            idx ++;
            phead = phead->next;
        }
    }
}
