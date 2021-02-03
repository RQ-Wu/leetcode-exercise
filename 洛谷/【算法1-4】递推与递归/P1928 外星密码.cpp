#include<iostream>
#include<stack>

using namespace std;

string trans(string code){
    string transRes;
    int times = 0;
    int codeSize = code.size();
    int i = 1;
    for(i=1; i<codeSize; i++){
        if (code[i]>='0'&&code[i]<='9')
        {
            times = times * 10 + (code[i] - '0');
        }
        else break;
        
    }
    code = code.substr(i, codeSize - 1);
    for (int i = 0; i < times; i++)
    {
        transRes += code;
    }

    return transRes;
}
int main(){
    string code;
    cin >> code;
    stack<char> resStack;
    string res;
    for (int i = 0; i < code.size(); i++)
    {
        char letter = code[i];
        if(letter != ']'){
            resStack.push(letter);
        }
        else{
            string temp;
            while(resStack.top() != '['){
                temp = resStack.top() + temp;
                resStack.pop();
            }
            resStack.pop();
            temp = "[" + temp;
            temp = trans(temp);
            int sizeTemp = temp.size();
            for(int i = 0; i < sizeTemp; i++){
                resStack.push(temp[i]);
            }
        }
    }
    int stackSize = resStack.size();
    for (int i = 0; i < stackSize; i++)
    {
        res = resStack.top() + res;
        resStack.pop();
    }
    cout << res;
}