#include<bits/stdc++.h>
using namespace std;
inline int read(){//快速读入 
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	} 
	return x*f;
}
int a[5000005];
int n,k;
int main(){
	n=read();
	k=read();
	for(register int i=0;i<n;++i)a[i]=read();//register和++i防卡常 
	sort(a,a+n);
	printf("%d",a[k]);
	return 0;
}