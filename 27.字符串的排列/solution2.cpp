class Solution {
public:
    vector<string > res;
    int n;
    vector<string> Permutation(string str) {
        if(str.empty())
            return res;
        //sort(str.begin(), str.end());
        dfs(str, 0);
        //sort(res.begin(), res.end());
        return res;
    }
    void dfs(string str, int i){
        if(i == str.size()){
            res.push_back(str);
            return;
        }
        for(int j = i; j < str.size(); ++j){
            if((j==i) || (j!=i && str[j]!=str[i])){
                for(int k = j-1; k >= i; --k)
                    str[k] = str[k] + str[k+1] - (str[k+1] = str[k]);
                dfs(str, i+1);
                for(int k = i; k <= j-1; ++k)
                    str[k] = str[k] + str[k+1] - (str[k+1] = str[k]);
            }
        }
    }
};
