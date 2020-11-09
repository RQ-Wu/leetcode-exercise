class Solution {
public:
    int split(vector<int> &arr, int low, int high){
        int x = arr[low]; //比较基准就是数组的第一个值
        int split_position = low; //比较基准所在位置

        for(int i = low + 1; i <= high; i++){
            if (arr[i] <= x)
            {
                split_position ++;
                swap(arr[split_position], arr[i]);
            }
        }
        if(low != split_position){
            swap(arr[low], arr[split_position]);    //把基准放到合适的位置
        }
        return split_position;
    }

    void quick_sort(vector<int> &arr, int low, int high, int k){
        if(low < high){
            int split_position = split(arr, low, high);
            if (split_position - low + 1 < k){
                quick_sort(arr, split_position + 1, high, k - split_position + low -1);
            }
            else if (split_position - low + 1 > k)
            {
                quick_sort(arr, low, split_position - 1, k);
            }
            else if (split_position - low + 1 == k){
                return ;
            }
        }
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> minK(k,0);
        quick_sort(arr, 0, arr.size() - 1, k);
        for(int i = 0; i < k; i++){
            minK[i] = arr[i];
        }
        return minK;
    }
};