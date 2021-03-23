#include<iostream>
#include<map>

using namespace std;

int n;
map<int, int> m;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        int op, l;
        cin >> op >> l;
        if(op == 1){
            if(m.count(l)) cout << "Already Exist" << endl;
            else m[l] = 1;
        }
        else{
            if(m.count(l)){
                m.erase(l);
                cout << l << endl;
            }
            else if(m.empty()) cout << "Empty" << endl;
            else{
                m[l] = 1;
                auto it = m.find(l);
                if(it == --m.end()){
                    cout << (--it)->first << endl;
                    m.erase(it);
                }
                else if(it == m.begin()){
                    cout << (++it)->first << endl;
                    m.erase(it);
                }
                else{
                    auto it2 = it;
                    it ++;
                    if(l - (--it2)->first > it->first - l){
                        cout << it->first << endl;
                        m.erase(it);
                    }
                    else{
                        cout << it2->first << endl;
                        m.erase(it2);
                    }
                }
                m.erase(l);
            }
        }
    }   
}