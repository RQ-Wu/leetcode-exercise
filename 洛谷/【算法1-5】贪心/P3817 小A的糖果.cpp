/*
P3817 小A的糖果
解决不算太难，贪心算法
自己改进了一下，不需要开100000的数组了
*/

#include<cstdio>    //快一点
int main(){
    int n;
    long maxnum; //不需要long long，用long就行了
    long eat = 0;
    long candy[2]; //从头到尾遍历，存储最近的两盘糖果
    scanf("%d %ld %ld", &n, &maxnum, &candy[0]);
    for(int i = 1; i < n; i++){
        scanf("%ld", &candy[1]);
        long sum = candy[0] + candy[1];
        if (sum > maxnum){   // 超过限制
            long sub = sum - maxnum;    //要吃多少个
            // 只吃后面一盘的
            // 前面的一盘不用管，反正也要吃掉sub个糖果，下次遍历也用不到前面的糖果了
            if (sub > candy[1]) candy[1] = 0;
            else candy[1] -= sub;
            eat += sub;     // 吃糖
        }
        candy[0] = candy[1];  
    }
    printf("%ld", eat);
}