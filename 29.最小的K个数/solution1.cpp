class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        set<int> st;
        vector<int> res;
        if(input.size()==0 || k == 0 || k > input.size())
            return res;
        for(int i = 0; i < input.size(); ++i)
            st.insert(input[i]);
        int t = 0;

        for(set<int>::iterator iter = st.begin(); t < k && iter != st.end(); ++t, ++iter){
            res.push_back(*iter);
        }
        return res;
    }
};
