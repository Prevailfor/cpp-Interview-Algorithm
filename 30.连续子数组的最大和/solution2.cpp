class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int res = 0xffffffff;
        int tempSum = -1;
        for(int i = 0; i < array.size(); ++i){
            if(tempSum <= 0)
                tempSum = array[i];
            else 
                tempSum += array[i];
            if(tempSum > res)
                res = tempSum;
        }
        return res;
    }
};
