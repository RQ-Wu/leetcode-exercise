#include<iostream>
#include<string>

using namespace std;

string first;
string mid;
string end;
int idx = 0;
typedef struct treeNode{
    char left = '#';
    char right = '#';
}treeNode;
treeNode t[26];

string getLeftPart(char key, string s){
    int pos = s.find(key);
    return s.substr(0, pos);
}

string getRightPart(char key, string s){
    int pos = s.find(key);
    return s.substr(pos, s.size());
}

void print(string s){
    int tmp = idx;
    idx ++;
    if(s.size() == 1){
        cout << first[tmp] << " ";
        return;
    }
    else{
        print(getLeftPart(first[tmp], s));
        print(getRightPart(first[tmp], s));
        cout << first[tmp] << " ";
        return;
    }
}

int main(){
    cin >> mid >> first;
    print(mid);
}