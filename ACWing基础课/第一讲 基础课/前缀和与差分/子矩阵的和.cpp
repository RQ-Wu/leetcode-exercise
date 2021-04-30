#include<iostream>

using namespace std;

int n, m, x1, x2, y1, y2, q;
int num[1005][1005] = {0};
int temp;

int main(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> temp;
            num[i][j] = num[i - 1][j] + num[i][j - 1] - num[i - 1][j - 1] + temp;
        }
    }
    for(int i = 0; i < q; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << num[x2][y2] - num[x1 -1][y2] - num[x2][y1 - 1] + num[x1 - 1][y1 - 1] << endl;
    }
}