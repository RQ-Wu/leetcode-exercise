#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

typedef struct student{
    char ID[10];
    int dScore,cScore,sum;
    int flag;   //学生类别
    /*
    flag == 0 : 德才均高于H
    flag == 1 : 德达线H，才不达线H
    flag == 2 : 均不到H，但是德大于才
    flag == 3 : 其它大于L的
    flag == 4 : 未达线
    */    
}student;

bool cmp(student a, student b){
    if (a.flag != b.flag) return a.flag < b.flag;
    else if (a.sum != b.sum) return a.sum > b.sum;
    else if (a.dScore != b.dScore) return a.dScore > b.dScore;
    else return strcmp(a.ID, b.ID) < 0;
}

int main(){
    int N, L, H;    //学生数量，录取线，优先录取线
    student stu[100010];
    scanf("%d%d%d", &N, &L, &H);
    int M = N;
    for (int i = 0; i < N; i++)
    {
        scanf("%s%d%d", stu[i].ID, &stu[i].dScore, &stu[i].cScore);
        stu[i].sum = stu[i].dScore + stu[i].cScore;
        if (stu[i].cScore >= H && stu[i].dScore >= H) stu[i].flag = 0;
        else if (stu[i].dScore >= H && stu[i].cScore >= L && stu[i].cScore < H) stu[i].flag = 1;
        else if (stu[i].dScore >= stu[i].cScore && stu[i].cScore >= L && 
        stu[i].cScore < H && stu[i].dScore >= L && stu[i].dScore < H) stu[i].flag = 2;
        else if (stu[i].dScore < L || stu[i].cScore < L) {
            stu[i].flag = 4;
            M--;
        }
        else stu[i].flag = 3;  
    }
    sort(stu, stu+N, cmp);
    printf("%d\n", M);
    for (int i = 0; i < M; i++)
    {
        printf("%s %d %d\n", stu[i].ID, stu[i].dScore, stu[i].cScore);
    }
    
    return 0;
}