#include<cstdio>
#include<vector>

using namespace std;

typedef struct score{
    int hh = 0;
    int competitor = 0;
}score;

int main(){
    vector<char> game;

    //input until get 'E' or other letter
    while (true)
    {
        char temp;
        scanf("%c", &temp);
        if (temp == 'W' || temp == 'L')
        {
            game.push_back(temp);
        }
        else if (temp == 'E') break;
        else continue;
    }

    //11分制
    score s;
    for (char res:game)
    {
        if (res == 'W') s.hh++;
        else if(res == 'L') s.competitor++;
        if (s.hh >= 11 || s.competitor >=11)    // someone score is beyond 11
        {
            int sub = s.hh - s.competitor;
            if (sub >= 2 || sub <= -2)  //the difference between two person must bigger than 2
            {
                printf("%d:%d\n", s.hh, s.competitor);
                s.hh = 0;
                s.competitor = 0;
            }
        }
    }
    printf("%d:%d\n", s.hh, s.competitor);
    printf("\n");
    s.hh = 0;
    s.competitor = 0;

    //21分制
    for (char res:game)
    {
        if (res == 'W') s.hh++;
        else if(res == 'L') s.competitor++;
        if (s.hh >= 21 || s.competitor >=21)    // someone score is beyond 11
        {
            int sub = s.hh - s.competitor;
            if (sub >= 2 || sub <= -2)  //the difference between two person must bigger than 2
            {
                printf("%d:%d\n", s.hh, s.competitor);
                s.hh = 0;
                s.competitor = 0;
            }
        }
    }
    printf("%d:%d", s.hh, s.competitor);
    s.hh = 0;
    s.competitor = 0;
}