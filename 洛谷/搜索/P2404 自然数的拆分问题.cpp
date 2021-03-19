#include<cstdio>
#include<vector>

using namespace std;

int n = 0;
vector<int> s;
int sum = 0;

void print(vector<int> s){
    printf("%d", s[0]);
    for(int i = 1; i < s.size(); i++){
        printf("+%d", s[i]);
    }
    printf("\n");
}

void dfs(int n, int start){
    if (sum == n){
        print(s);
        return ;
    }
    else if(sum > n){
        return ; 
    }
    else{
        for(int i = start; i < n; i++){
            sum += i;
            s.push_back(i);
            dfs(n, i);
            sum -= i;
            s.pop_back();
        }
        return ;
    }
}

int main(){
    scanf("%d", &n);
    dfs(n, 1);
}