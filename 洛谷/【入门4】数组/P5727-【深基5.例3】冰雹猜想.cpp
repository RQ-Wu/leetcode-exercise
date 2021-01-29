#include<cstdio>
#include<stack>

using namespace std;

int main(){
    stack<int> pipeline;
    int num;
    scanf("%d", &num);
    pipeline.push(num);

    while(num > 1){
        if (num % 2 == 1){
            num = num * 3 + 1;
            pipeline.push(num);
        }
        else
        {
            num = num / 2;
            pipeline.push(num);
        }
    }

    int length = pipeline.size();
    for (int i = 0; i < length; i++)
    {
        if(i == 0){
            printf("%d", pipeline.top());
            pipeline.pop();
        }
        else
        {
            printf(" %d", pipeline.top());
            pipeline.pop();
        }
    }
    
    
}