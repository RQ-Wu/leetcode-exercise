#include<iostream>
#include<cstdlib>

using namespace std;

// typedef struct person{
//     int num;
//     person *next;
// }person;

// person* phead = (struct person*)malloc(sizeof(struct person));
// int n, m;

// int main(){
//     cin >> n;
//     // init person list
//     phead->num = 1;
//     phead->next = NULL;
//     // input person list
//     for(int i = 2; i <= n; i++){
//         int pos, dir;
//         person *tmp = (struct person*)malloc(sizeof(struct person));
//         tmp->num = i;
//         tmp->next = NULL;
//         cin >> pos >> dir;
//         // cout << tmp->num;
//         // put on right side
//         if (dir == 1){
//             person *p = phead;
//             while(p->num != pos){
//                 p = p->next;
//             }
//             if(p->next) tmp->next = p->next;
//             p->next = tmp;
//         }
//         // put on left side
//         else if (dir == 0){
//             if (phead->num == pos){
//                 tmp->next = phead;
//                 phead = tmp;
//             }
//             else{
//                 person *p = phead;
//                 while(p->next->num != pos){
//                     p = p->next;
//                 }
//                 tmp->next = p->next;
//                 p->next = tmp;
//             }
//         }
//     }
//     // delete the list
//     cin >> m;
//     for(int i = 0; i < m; i++){
//         int delNum = 0;
//         cin >> delNum;
//         person *p = phead;
//         if (p->num == delNum){
//             phead = phead->next;
//         }
//         else{
//             while(p->next && p->next->num != delNum){
//                 if(p->next) p = p->next;
//                 else break;
//             }
//             if(p->next){
//                 p->next = p->next->next;
//             }
//         }
//     }
//     // output the list
//     person *p = phead;
//     for(int i = 1; i <= n; i++){
//         cout << p->num << " ";
//         if(p->next) p = p->next;
//     }
// }

int n, m;
typedef struct person{
    int left = 0;
    int right = 0;
}person;
person p[100005];
int flag[100005] = {0};

int main(){
    cin >> n;
    int head = 1;
    // input the list
    for(int i = 2; i <= n; i++){
        int pos, dir;
        cin >> pos >> dir;
        if (pos == head && dir == 0){
            p[i].right = head;
            p[head].left = i;
            head = i;
        }
        else{
            if(dir == 0){
                p[i].right = pos;
                p[i].left = p[pos].left;
                p[p[pos].left].right = i;
                p[pos].left = i;
            } 
            else if(dir == 1){
                p[i].left = pos;
                p[i].right = p[pos].right;
                if(p[pos].right)
                    p[p[pos].right].left = i;
                p[pos].right = i;
            }
        }
    }
    // delete the list
    cin >> m;
    for(int i = 0; i < m; i++){
        int delNum;
        cin >> delNum;
        if(flag[delNum] == 1) continue;
        if(delNum == head) {
            // p[head].right = 0;
            p[delNum].left = 0;
            head = p[delNum].right;
        }
        else{
            p[p[delNum].left].right = p[delNum].right; 
            p[p[delNum].right].left = p[delNum].left;
            
        }
        flag[delNum] = 1;
    }
    // output the list
    int idx = head;
    cout << idx << " ";

    while(p[idx].right){
        cout << p[idx].right << " ";
        idx = p[idx].right;
    }
}