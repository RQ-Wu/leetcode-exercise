#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 1000001
#define ll long long

using namespace std;

int n, m;
// tree is the data structrue for segment tree
// lazy is a list of flags shows the delta information on father node
ll tree[MAX<<2], lazy[MAX<<2];

// get left child for segment tree node
inline int ls(int x){
    // x<<1 equals to x*2, but is much faster
    return x<<1;
}

// get right child for segment tree node
inline int rs(int x){
    // x<<1|1 equals to x*2+1, but is much faster
    return x<<1|1;
}

inline void push_down(int p, int l, int r){
    int mid = (l + r) >> 1;
    // deal with left child
    lazy[ls(p)] += lazy[p];
    tree[ls(p)] = tree[ls(p)] + lazy[p] * (mid - l + 1);
    // deal with right child
    lazy[rs(p)] += lazy[p];
    tree[rs(p)] = tree[rs(p)] + lazy[p] * (r - mid);
    lazy[p] = 0;
}

// build the segment tree with add operation
// segment tree can also used for max/min/multiply operation
void build(int node, int l, int r){
    if(l == r){
        scanf("%lld", &tree[node]);
        return;
    }
    int mid = (l + r) >> 1;
    build(ls(node), l, mid);
    build(rs(node), mid+1, r);
    // you can replace the code below such as max/min operation
    tree[node] = tree[ls(node)] + tree[rs(node)];
}

inline void update(int ul, int ur, int l, int r, int p, ll k){
    if(ul <= l && ur >= r){
        tree[p] += k * (r - l + 1);
        lazy[p] += k;
        return ;
    }
    int mid = (l + r) >> 1;
    push_down(p, l, r);
    if(ul <= mid) update(ul, ur, l, mid, ls(p), k);
    if(ur > mid) update(ul, ur, mid+1, r, rs(p), k);
    tree[p] = tree[ls(p)] + tree[rs(p)];
}

ll query(int ql, int qr, int l, int r, int p){
    ll res = 0;
    if(ql <= l && qr >= r) return tree[p];
    int mid = (l + r) >> 1;
    push_down(p, l, r);
    if(ql <= mid) res+=query(ql, qr, l, mid, ls(p));
    if(qr > mid) res+=query(ql, qr, mid+1, r, rs(p));
    
    return res;
}

int main(){
    cin >> n >> m;
    build(1, 1, n);
    while (m--)
    {
        int op, x, y;
        ll k;
        scanf("%d", &op);
        switch(op)
        {
            case 1:{
                scanf("%d %d %lld", &x, &y, &k);
                update(x, y, 1, n, 1, k);
                break;
            }
            case 2:{
                scanf("%d %d", &x, &y);
                printf("%lld\n", query(x, y, 1, n, 1));
                break;
            }
        }
    }
    
}