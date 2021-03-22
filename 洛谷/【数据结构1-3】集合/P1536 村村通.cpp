#include<iostream>

using namespace std;

int find(int fa[], int x){
    if (fa[x] == x) return x;
    else{
        return find(fa, fa[x]);
    }
}

bool unite(int fa[], int a, int b){
    int faA = find(fa, a);
    int faB = find(fa, b);
    if(faA == faB) return false;
    else{
        fa[faB] = faA;
        return true;
    }
}

int main(){
    while(true){
        int setNum = 0;
        int  n = 0, m = 0;;
        cin >> n >> m;
        int fa[1005];
        for(int i = 1; i <= n; i++){
            fa[i] = i;
        }
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            if(unite(fa, a, b)){
                setNum++;
            }
        }
        cout << setNum - 1 << endl;
    }
}