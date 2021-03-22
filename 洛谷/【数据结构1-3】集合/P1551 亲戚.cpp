#include<iostream>

using namespace std;

int person[5005] = {0};
int n, m, p;

void combine(int a, int b, int n){
    int targeta = person[a];
    int targetb = person[b];
    for (int i = 1; i <= n; i++){
        if(person[i] == targetb)
            person[i] = targeta;
    }
}

int main(){
    cin >> n >> m >> p;
    // init
    for (int i = 1; i <= n; i++){
        person[i] = i;
    }
    // combine
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        combine(a, b, n);
    }
    // ask
    for(int i = 0; i < p; i++){
        int a, b;
        cin >> a >> b;
        if(person[a] == person[b]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}