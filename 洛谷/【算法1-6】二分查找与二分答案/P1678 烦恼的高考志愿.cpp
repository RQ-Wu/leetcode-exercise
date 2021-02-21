#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int m, n;
    long long res = 0;
    int school[100005];
    int student[100005];

    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) scanf("%d", &school[i]);
    for (int i = 0; i < n; i++) scanf("%d", &student[i]);

    sort(school, school + m);

    for (int i = 0; i < n; i++){
        int lowpos = lower_bound(school, school+m, student[i]) - school;
        int tmp;
        if(lowpos != m && lowpos != 0){
            tmp = min(student[i] - school[lowpos - 1], school[lowpos] - student[i]);
        }
        else if(lowpos == 0){
            tmp = school[0] - student[i];
        }
        else{
            tmp = student[i] - school[lowpos - 1];
        }
        res += tmp;
    }

    printf("%lld", res);
}