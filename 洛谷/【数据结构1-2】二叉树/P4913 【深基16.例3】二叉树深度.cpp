#include<iostream>
#include<algorithm>

using namespace std;


typedef struct treeNode{
    int left;
    int right;
}treeNode;

treeNode t[100005];
int n;
int maxdepth = 0;

void treeDepth(int node, int depth){
    if(node == 0) return;
    else{
        treeDepth(t[node].left, depth+1);
        treeDepth(t[node].right, depth+1);
        maxdepth = max(maxdepth, depth);
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> t[i].left >> t[i].right;
    }

    treeDepth(1, 1);
    cout << maxdepth;
}
