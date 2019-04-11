class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int max = -1;
        for(int i = 0; i < array.size(); ++i){
            int tp = 0;
            for(int j = i; j < array.size(); ++j){
                tp += array[j];
                if(tp > max)
                    max = tp;
            }
        }
        return max;
    }
};
