#include<iostream>

using namespace std;

int main(){
    int k = 0;
    cin >> k;
    int num[k] = {0};
    int sum[k] = {0};   //以第k位置为结尾的和最大的子串
    int res = -100000;
    int max_index = -1;
    for(int i = 0; i < k; i++){
        cin >> num[i];
    }
    sum[0] = num[0];
    res = sum[0];
    if(k == 1 && res > 0){
        cout << res << " " << res << " " << res;
        return 0;
    }
    for(int i = 1; i < k; i++){
        if(sum[i - 1] < 0){
            sum[i] = num[i];
        } else{
            sum[i] = sum[i - 1] + num[i];
        }
        if(res < sum[i]){
            res = sum[i];
            max_index = i;
        }
    }
    if(max_index == -1){
        cout << 0 << " " << num[0] << " " << num[k - 1];
        return 0;
    }
    cout << res <<" ";
    for(int i = max_index; i >= 0; i--){
        res -= num[i];
        if(res == 0){
            cout << num[i] <<" ";
            break;
        }
    }
    cout << num[max_index];
    return 0;
}