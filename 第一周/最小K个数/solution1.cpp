class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> minK(k,0);
        if(k == 0) return minK;
        else{
            priority_queue<int> Q;
            //将前k个数放进优先队列中
            for(int i = 0; i < k; i++){
                Q.push(arr[i]);
            }
            //去掉优先队列中最大的值
            for(int i = k; i < (int)arr.size(); i++){
                if(arr[i] < Q.top()){
                    Q.pop();
                    Q.push(arr[i]);
                }
            }
            //将队列中最终的值赋给vector
            for(int i = 0; i < k; i++){
                minK[i] = Q.top();
                Q.pop();
            }
        }
        return minK;
    }
};