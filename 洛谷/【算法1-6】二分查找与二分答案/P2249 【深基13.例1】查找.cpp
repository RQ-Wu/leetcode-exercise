	#include<cstdio>

	int findPos(int a[], int num, int low, int high){
		int target = (low + high) / 2;
		if(low == high){
			if (a[low] == num) return low;
			else return -2;
		}
		if (a[target] < num)
		{
			return findPos(a, num, target+1, high);
		}
		else if(a[target] >= num){
			return findPos(a, num, low, target);
		}
	}

	int main(){
		int n, m;
		scanf("%d %d", &n, &m);
		int a[n];
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < m; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			printf("%d ", findPos(a, tmp, 0, n - 1) + 1);
		}
	}