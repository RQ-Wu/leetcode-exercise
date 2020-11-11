#include <iostream>
#include <string>
using namespace std;
 
int main(){
	int a, b;
	cin >> a >> b;
	int sum = a + b;	
	if (sum < 0)
		cout << "-";
	string s = to_string(abs(sum));
	int i = s.size() % 3 ? s.size() % 3 : 3;
	cout << s.substr(0, i);
	for (; i < s.size(); i += 3){
		cout << "," << s.substr(i, 3);
	}
 
	return 0;
}
