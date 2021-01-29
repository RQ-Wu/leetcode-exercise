#include<cstdio>

using namespace std;

int lossAndWin[5][5]={  {0,0,1,1,0},
                        {1,0,0,1,0},
                        {0,1,0,0,1},
                        {0,0,1,0,1},
                        {1,1,0,0,0}  };
int A[200];
int B[200];

int main(){
    int N, Na, Nb = 0;
    int scoreA, scoreB = 0;
    scanf("%d %d %d", &N, &Na, &Nb);
    for (int i = 0; i < Na; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < Nb; i++)
    {
        scanf("%d", &B[i]);
    }

    for(int i = 0; i < N; i++){
        int ai = i % Na;
        int bi = i % Nb;

        scoreA += lossAndWin[A[ai]][B[bi]];
        scoreB += lossAndWin[B[bi]][A[ai]];
    }

    printf("%d %d", scoreA, scoreB);

    return 0;
}