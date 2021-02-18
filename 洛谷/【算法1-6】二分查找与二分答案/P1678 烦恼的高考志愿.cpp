#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int m, n;
    int school[100005];
    int student[100005];

    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) scanf("%d", &school[i]);
    for (int i = 0; i < n; i++) scanf("%d", &student[i]);

    sort(school, school + m);

    for (int i = 0; i < n; i++){
        
    }
}