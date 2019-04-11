class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        multiset<int, greater<int> > kres;
        if(input.empty() || k==0 || input.size()<k)
            return res;
        kres.insert(input.front());
        for(int i = 1; i < input.size(); ++i){
            if(kres.size() < k)
                kres.insert(input[i]);
            else if(kres.size() == k){
                if(*kres.begin() > input[i]){
                    kres.erase(kres.begin());
                    kres.insert(input[i]);
                }
            }
        }
        for(multiset<int, greater<int> >::iterator iter = kres.begin(); iter != kres.end(); ++iter)
            res.push_back(*iter);
        return res;
    }
};
