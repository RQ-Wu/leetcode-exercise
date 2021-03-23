#include<iostream>
#include<map>
#include<string>

using namespace std;

map<string, int> students;
int n;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        int menu;
        cin >> menu;
        if(menu == 1){
            string student_name;
            int score;
            cin >> student_name >> score;
            students.insert(pair<string, int>(student_name, score));
            cout << "OK" << endl;
        }
        else if(menu == 2){
            string student_name;
            cin >> student_name;
            map<string, int>::iterator it = students.find(student_name);
            if(it == students.end()) cout << "Not found" << endl;
            else cout << it->second << endl;
        }
        else if(menu == 3){
            string student_name;
            cin >> student_name;
            map<string, int>::iterator it = students.find(student_name);
            if(it == students.end()) cout << "Not found" << endl;
            else{
                cout << "Deleted successfully" << endl;
                students.erase(student_name);
            }
        }
        else if(menu == 4){
            cout << students.size() << endl;
        }
    }
}