#include<bits/stdc++.h>
#define tin int//个人习惯防手滑 
#define itn int
#define tni int
#define nit int
#define nti int
#define pritnf printf
#define scnaf scanf
#define ll long long
using namespace std;
#define maxa 504

itn i,sa,sb,m;//sa是a的长度，我们（划掉）sb是b的长度，m是a与b中的较大长度 
short x[maxa]={0},y[maxa]={0};//强迫症省空间，开short。x为较长加数，y为剩下那个。x[1]、y[1]为个位，x[2]、y[2]为十位，以此类推。 
string a,b;

itn main()
{
	cin>>a>>b;//cin是string最好的搭档
	sa=a.size();//为以后方便取a的长度
	sb=b.size();//为以后方便取b的长度
	m=max(sa,sb);//为以后方便取a、b较长长度
	//
	if(sa>sb)//如果a是较长加数 
	{
		for(i=1;i<=sa;++i)//把a遍历一遍 
		{
			x[i]=a[sa-i]-48;//把a赋给x 
		}
		for(i=1;i<=sb;++i)//把较短加数一位一位加上 
		{
			x[i]+=b[sb-i]-48;//a一位一位加上b 
		}
	}
	else//上面反过来 
	{
		for(i=1;i<=sb;++i)
		{
			x[i]=b[sb-i]-48;
		}
		for(i=1;i<=sa;++i) 
		{
			x[i]+=a[sa-i]-48;
		}
	}
	//
	for(i=1;i<=m;++i)//十进制处理 
	{
		if(x[i]>=10)//如果需要进位 
		{
			x[i]-=10;//这一位留个位 
			++x[i+1];//下一位进一 
		}
	}
	//聪明的孩子会发现此时如999+1情况比最高位高一位的地方有个1输出时将被忽略 
	if(x[m+1]>0)//最高位进位特判 
	{
		++m;//多输出一位，这样输出时就把最高处孤独的1考虑到了 
	}
	//
	for(i=m;i>=1;--i)//反着输出，注意现在的m有可能已经加1,999+1不会输出000。 
	{
		cout<<x[i];//一位一位
	}
	return 0;
}//本代码已进行防抄袭处理·^v·^ 