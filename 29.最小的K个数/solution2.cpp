class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
       vector<int> res;
       if(input.empty() || k==0 || k>input.size())
           return res;
        int s = 0, e = input.size()-1;
        int index = Partition(input, s, e);
        while(index != k){
            if(index < k) 
                s = index + 1;
            else if(index > k)
                e = index - 1;
            index = Partition(input, s, e);
        }
        for(int i = 0; i < k; ++i)
            res.push_back(input[i]);
        return res;
    }
    int Partition(vector<int> &dat, int s, int e){
        int i = s, j = e;
        int temp = dat[s];
        while(i < j){
            while(i<j && dat[j]>=temp)j--;
            dat[i] = dat[j];
            while(i<j && dat[i]<=temp)i++;
            dat[j] = dat[i];
        }
        dat[i] = temp;
        return i;
    }
};
