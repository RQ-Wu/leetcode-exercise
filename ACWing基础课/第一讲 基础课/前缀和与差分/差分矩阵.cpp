#include<iostream>

using namespace std;

int n, m, q, temp, a[1005][1005] = {0};
int x1, y1, x2, y2, c;

void insert(int x1, int y1, int x2, int y2, int c){
    a[x1][y1] += c;
    a[x1][y2 + 1] -= c;
    a[x2 + 1][y1] -= c;
    a[x2 + 1][y2 + 1] += c;
}

int main(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> temp;
            insert(i,j,i,j,temp);
        }
    }
    for(int i = 0; i < q; i++){
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            a[i][j] = a[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            if(j == m) cout << a[i][j] << endl;
            else cout << a[i][j] << " ";
        }
    }
}