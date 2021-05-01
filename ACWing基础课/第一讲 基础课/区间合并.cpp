#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,int>> nums;
int n;
int res;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        nums.push_back({l, r});
    }
    sort(nums.begin(), nums.end());

    int sd = -1e9, ed = -1e9;
    for (int i = 0; i < n; i++){
        if(nums[i].first > ed){
            res ++;
            sd = nums[i].first;
        }
        ed = max(nums[i].second, ed);
    }
    cout << res;
}