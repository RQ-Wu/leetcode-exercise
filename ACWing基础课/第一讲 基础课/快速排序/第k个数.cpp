#include<iostream>

using namespace std;

int quick_sort(int q[], int l, int r, int k){
    if (l >= r) return q[r];

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while(i < j){
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }

    int sl = j - l + 1;
    if (k <= sl) return quick_sort(q, l, j, k);
    else return quick_sort(q, j + 1, r, k - sl);
}

int main(){
    int n, k;
    int q[100005];

    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> q[i];
    }

    cout << quick_sort(q, 0, n - 1, k);
}