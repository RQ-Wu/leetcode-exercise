// 本题要处理一个长度为2e9的数轴，但是只对其中不多于3e5的位置进行操作
// 所以我们不需要暴力的开2e9的数组，而是将-1e9~1e9个下标中用到的3e5个下标进行处理
// 我们将用到的下标在-1e9~1e9范围内映射到0~3e5的范围内

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 300010;
int n, m, a[N], s[N];

// alls 用来存储所有用到的下标(加的下标和查询的下标)
// add用来存储所有的加操作， query用来存储所有的查操作
vector<int> alls;
vector<pair<int, int>> add, query;

int find(int pos){
    int l = 0, r = alls.size() - 1;
    while(l < r){
        int mid = l + r >> 1;
        if(alls[mid] >= pos) r = mid;
        else l = mid + 1;
    }
    return r + 1; // 下标从1开始
}

int main(){
    cin >> n >> m;

    // 处理加操作
    for (int i = 0; i < n; i++){
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        
        alls.push_back(x);
    }
    
    // 处理查询操作
    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});

        alls.push_back(l);
        alls.push_back(r);
    }

    // 排序并去重，得到的alls就是数轴中使用过的下标的离散化表示
    // 离散化后 alls[x] 表示数轴上的 alls[x] 坐标离散化后为 x
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
 
    for(auto item : add){
        int pos = find(item.first);
        a[pos] += item.second;
    }

    for(int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];

    for(auto item : query) cout << s[find(item.second)] - s[find(item.first) - 1] << endl; 
}