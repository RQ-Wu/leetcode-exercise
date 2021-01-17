#include<cstdio>

int main(){
    // init
    int n = 0;
    scanf("%d",&n);
    int num[n] = {0};
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    // less cute
    int lessCute[n] = {0};
    for (int i = 0; i < n; i++){
        for (int j = i-1; j >= 0; j--){
            if (num[j] < num[i]) lessCute[i]++;
        }
    }
    // output
    for (int i = 0; i < n; i++){
        if (i == 0) printf("%d", lessCute[i]);
        else printf(" %d", lessCute[i]);
    }
}