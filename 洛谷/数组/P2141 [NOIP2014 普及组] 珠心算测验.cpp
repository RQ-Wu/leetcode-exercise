#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int main(){
    vector<int> num;
    set<int> res;
    int  n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        num.push_back(temp);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = num[i] + num[j];
            vector<int>::iterator it = find(num.begin(), num.end(), sum);
            if (it != num.end()){
                res.insert(sum);
            }
        }
    }

    printf("%d", res.size());
}