/* 快速排序模板 */
#include<cstdio>
#include<iostream>

using namespace std;

void quickSort(int a[], int low, int high){
    if(low >= high) return;
    int base = a[low];
    int i = low, j = high;
    while(i != j){
        while (j > i && a[j] >= base) j--;
        while (i < j && a[i] <= base) i++;
        if(i<j){
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    a[low] = a[i];
    a[i] = base;
    quickSort(a, low, i - 1);
    quickSort(a, j+1, high);    
}

int main(){
    int a[1000001];
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quickSort(a, 0, n -1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    
}