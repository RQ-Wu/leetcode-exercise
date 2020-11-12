#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n = 0;
    int floor = 0;
    int time = 0;
    cin >> n;
    vector<int> request(n,0);
    for(int i = 0; i < n; i++){
        cin >> request[i];
        if(request[i] > floor){
            time = time + 6 * (request[i] - floor) + 5;
            floor = request[i];
        }
        else{
            time = time + 4 * (floor-request[i]) + 5;
            floor = request[i];
        }
    }
    cout << time;
    
    return 0;
}