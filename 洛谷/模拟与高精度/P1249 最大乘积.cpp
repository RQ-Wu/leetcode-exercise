  #include<iostream>
  #include<stack>
  #include<vector>

  using namespace std;

  string highAccMul_single(string a, int b, int pos){
    stack<char> tmp;
    string res;
    while (pos-- > 0)
    {
        tmp.push('0');
    }
    int c = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        tmp.push(((a[i]-'0')*b+c)%10+'0');
        c = ((a[i]-'0')*b+c)/10;
    }
    if (c!=0)
    {
        tmp.push(c+'0');
    }
    
    int len = tmp.size();
    while(len-- > 0){
        res.push_back(tmp.top());
        tmp.pop();
    }

    return res;
}

string highAccAdd(string A, string B){
    stack<int> a;
    stack<int> b;
    stack<int> res;
    string s;

    for(int i = 0; i < A.size(); i++){
        a.push(A[i] - '0');
    }
    for(int i = 0; i < B.size(); i++){
        b.push(B[i] - '0');
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
        s.push_back(res.top()+'0');
        res.pop();
    }
    
    return s;
}

string highAccMul(string a, string b){
    int len = b.size();
    string mul[len];
    string res;
    for (int i = len-1; i >= 0; i--)
    {
        mul[len - 1 - i] = highAccMul_single(a, b[i]-'0', len-1-i);
    }
    
    res = mul[0];
    for(int i = 1; i < len; i++){
        res = highAccAdd(res, mul[i]);
    }

    return res;
}

int main(){
    int num = 0;
    cin >> num;
    if (num==3)
    {
        cout << "1 2\n2";
    }
    else if(num==4){
        cout << "1 3\n3";
    }
    else{
        int sum = 0;
    int init = 2;
    while (sum < num)
    {
        sum += (init++);
    }

    vector<int> res;
    int dis = sum - num;
    if (dis == 1){
        for (int i = 3; i < init; i++){
            res.push_back(i);
        }
    }
    else{
        for (int i = 2; i < init; i++)
        {
            if (i != dis) res.push_back(i);
        }
    }
    for(int i = 0; i < res.size(); i++){
        if(i == 0) cout << res[i];
        else cout << " " << res[i];
    }
    cout << "\n";

    string s = string(to_string(res[0]));
    for(int i = 1; i < res.size(); i++){
		cout << s << endl;
		cout << string(to_string(res[i])) << endl;
        s = highAccMul(s, string(to_string(res[i])));
    }

    cout << s;
    }
    

    return 0;
}