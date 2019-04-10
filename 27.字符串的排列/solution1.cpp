class Solution {
public:
    map<string, int>res;
    string dat;
    vector<string> Permutation(string str) {
        vector<string> rt;
        if(str.size() == 0)
            return rt;
        dat = str;
        dfs(0);
        
        for(map<string, int>::iterator iter = res.begin(); iter != res.end(); ++iter){
            rt.push_back(iter->first);
        }
        return rt;
    }
    
    void dfs(int i){
        if( i == dat.size()-1 ){
            res.insert(pair<string, int>(dat, 0));
            return ;
        }
        for(int j = i; j < dat.size(); ++j){
            swap(dat[i], dat[j]);
                dfs(i+1);
            swap(dat[i], dat[j]);
        }
    }
    void swap(char &a, char &b){
        a = a + b - (b = a+b-b);
    }
};
