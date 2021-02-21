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