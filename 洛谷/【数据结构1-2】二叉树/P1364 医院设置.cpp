#include<iostream>
#include<algorithm>

using namespace std;

typedef struct treeNode{
    int father = -1;
    int left;
    int right;
    int num;
    int depth;
}treeNode;

treeNode tree[105];
int n;

void dfs(int i, int depth){
    if (i == 0) return;
    else{
        tree[i].depth = depth;
        dfs(tree[i].left, depth + 1);
        dfs(tree[i].right, depth + 1);
    }
    return ;
}

int getDistance(int a, int b){
    int step = 0;
    int maxNode = tree[a].depth > tree[b].depth ? a : b;
    int minNode = maxNode == a ? b : a;
    for(int i = 0; i < tree[maxNode].depth - tree[minNode].depth; i++){
        maxNode = tree[maxNode].father;
    }
    if (maxNode != minNode){
        for(int i = 0; i < tree[minNode].depth; i++){
            step ++;
            maxNode = tree[maxNode].father;
            minNode = tree[minNode].father;
            if(maxNode == minNode) break;
        }
    }
    return tree[maxNode].depth - tree[minNode].depth + step * 2;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> tree[i].num >> tree[i].left >> tree[i].right;
        if (tree[i].left != 0)
            tree[tree[i].left].father = i;
        if(tree[i].right != 0)
            tree[tree[i].right].father = i; 
    }
    dfs(1, 1);
    int mindis = 10000000;
    for(int i = 1; i <= n; i++){
        int dis = 0;
        for(int j = 1; j <= n; j++){
            if(j != i){
                dis += tree[j].num * getDistance(i, j);
            }
        }
        mindis = min(mindis, dis);
    }
    cout << mindis;
    
}