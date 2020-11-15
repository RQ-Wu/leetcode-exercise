#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct people{
    int level = 0;
    vector<int> children;
}people;
vector<people> family(100);    //存储家谱
vector<int> leaves(100);
int maxLevel = 0;

int transID2Int(string ID){
    return (ID[0] - '0') * 10 + (ID[1] - '0') - 1;
}

void dfs(int p, int depth){
    if(family[p].children.size() == 0){
        maxLevel = max(depth,maxLevel);
        leaves[depth] ++;
        return;
    }
    else{
        family[p].level += depth;
        depth ++;
        for(int i = 0; i < family[p].children.size(); i++){
            dfs(family[p].children[i],depth);
        }
    }
}
int main(){
    int n, m, k;
    string parent, child;
    cin >> n >> m;
    //建立家谱
    for(int i = 0; i < m; i++){
        cin >> parent >> k;
        for(int j = 0; j < k; j++){
            cin >> child;
            int childNum = transID2Int(child);
            family[transID2Int(parent)].children.push_back(childNum);
        }
    }
    dfs(0,0);
    
    cout<<leaves[0];
    for(int i=1;i<=maxLevel;i++){
        cout<<" "<<leaves[i];
    }
    
    return 0;
}