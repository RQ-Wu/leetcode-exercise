#include<cstdio>
#include<algorithm>

using namespace std;

typedef struct people{
    int num;
    int score;
}people;

bool cmp(people p1, people p2){
    if(p1.score > p2.score) return true;
    else if (p1.score == p2.score && p1.num < p2.num) return true;
    else return false;
}
int main(){
    int n, m;
    people p[5000];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &p[i].num, &p[i].score);
    }

    sort(p, p+n, cmp);
    int linep = int(m * 1.5);
    int linescore = p[linep-1].score;
    int lineperson = linep;
    for (int i = linep; i < n; i++)
    {
        if(p[i].score == linescore) lineperson++;
    }
    
    printf("%d %d\n", linescore, lineperson);
    for (int i = 0; i < lineperson; i++)
    {
        printf("%d %d\n", p[i].num, p[i].score);
    }

    return 0;
    
    
}