// 高精度加法
#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<int> a;
    stack<int> b;
    stack<int> res;

    //input
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        a.push(s[i] - '0');
    }
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        b.push(s[i] - '0');
    }

    //calculate
    int lena = a.size();
    int lenb = b.size();
    int maxlen = max(lena, lenb);
    int minlen = min(lena, lenb);

    int more = 0;
    for (int i = 0; i < maxlen; i++)
    {
        if (i < minlen)
        {
            int numa = a.top();
            int numb = b.top();
            a.pop();
            b.pop();

            int numres = ( numa + numb + more) % 10;
            more = ( numa + numb + more ) / 10;
            res.push(numres);
        }
        else if(lena == minlen)
        {
            int numb = b.top();
            b.pop();

            int numres = ( numb + more) % 10;
            more = ( numb + more) / 10;
            res.push(numres);
        }
        else{
            int numa = a.top();
            a.pop();

            int numres = ( numa + more) % 10;
            more =  (numa + more) / 10;
            res.push(numres);
        }
    }
    if(more != 0) res.push(more);
    int lenres = res.size();
    for (int i = 0; i < lenres; i++)
    {
        cout<<res.top();
        res.pop();
    }
    
    return 0;
}