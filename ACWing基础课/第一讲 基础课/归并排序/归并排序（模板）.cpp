#include<iostream>

using namespace std;

void merge_sort(int q[], int l, int r){
    if (l >= r) return;     //递归终止

    // 第一步，选取分界点
    int mid = l + r >> 1;
    // 第二步，递归排序左右两边
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);

    // 第三步，双指针思想合并两个部分
    int k = 0, i = l, j = mid+1;
    int tmp[r - l + 1]; 
    while (i <= mid && j <= r)
        if(q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];
    for(k = 0, i = l; i <= r; k++, i++) q[i] = tmp[k];
}

int main(){
    int q[100005];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> q[i];
    }
    merge_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++){
        cout << q[i] << " ";
    }
}