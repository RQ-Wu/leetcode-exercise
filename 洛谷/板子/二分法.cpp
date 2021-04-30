#include<iostream>

using namespace std;

//输入数组，左右位置，输出下标
int halfFind(int a[], int left, int right, int target){
    int res = -1;
    while(left<=right){//二分模板
		int mid=(left+right)>>1;//位运算貌似会节省时间
		if(a[mid] == target){
            res = mid;
            break;
        }
        else if (a[mid] < target) left = mid + 1;
        else right = mid - 1; 
	}
    return res;
}

//寻找下界
int halfFind(int a[], int left, int right, int target){
    while(left <= right){
        int mid = left + right >> 1;
        if (a[mid] <= target) left = mid + 1;
        else right = mid - 1;
    }
    return right; 
    // a[right] == target 就是找到了
    // a[right] == target 就是不存在 
}

//寻找上界
int halfFind(int a[], int left, int right, int target){
    while(left < right){
        int mid = left + right >> 1;
        if (a[mid] < left) left = mid + 1;
        else right = mid;
    }
    return left;
    // a[left] == target 就是找到了
    // a[left] != target 就是不存在
}