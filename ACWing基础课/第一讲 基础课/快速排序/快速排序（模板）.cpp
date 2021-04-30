#include<iostream>

using namespace std;

// void quick_sort(int q[], int l, int r)
// {
//     //递归的终止情况
//     if(l >= r) return;
//     //第一步：分成子问题
//     int i = l - 1, j = r + 1, x = q[l + r >> 1];
//     while(i < j)
//     {
//         do i++; while(q[i] < x);
//         do j--; while(q[j] > x);
//         if(i < j) swap(q[i], q[j]);
//     }
//     //第二步：递归处理子问题
//     quick_sort(q, l, j), quick_sort(q, j + 1, r);
//     //第三步：子问题合并.快排这一步不需要操作，但归并排序的核心在这一步骤
// }

void quick_sort(int q[], int l, int r){
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while(i < j){
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }

    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}

int main(){
    int n;
    int q[100005];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> q[i];
    }
    quick_sort(q, 0, n-1);
    for (int i = 0; i < n; i++){
        cout << q[i] << " ";
    }
    return 0;
}