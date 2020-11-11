#include<iostream>
#include<stack>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b ;
    int sum = a + b;
    
    stack<char> number;
    if(sum > -1000 && sum < 1000){
        cout << sum;
        return 0;
    }
    if(sum < 0){
        cout << "-";
        sum = - sum;
    }
    int i = 0;
    while(sum){
        if(i % 3 == 0 && i != 0) number.push(',');
        char temp = (sum % 10) + '0';
        number.push(temp);
        i++;
        sum = sum / 10;
    }
    int length = number.size();
    for(int i = 0; i < length; i++){
        cout << number.top();
        number.pop();
    }
}