class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int >res;
        
        int k = 0;
        int level = 0;
        
        int odds = 0;
        if(m % 2 && n % 2)
            odds = 1;
        while(k < m*n ){
            for(int t = level; k<m*n && t < n-level-1; ++t){
                res.push_back(matrix[level][t]);
                k++;
            }
            for(int t = level; k<m*n && t < m-level-1; ++t){
                res.push_back(matrix[t][n-level-1]);
                k++;
            }
            for(int t = n-level-1; k<m*n && t > level; --t){
                res.push_back(matrix[m-level-1][t]);
                k++;
            }
            for(int t = m-level-1; k<m*n && t > level; --t){
                res.push_back(matrix[t][level]);
                k++;
            }
            
            if(k == m*n-1 && odds){
                res.push_back(matrix[m/2][n/2]);
                k++;
            }
            
            level++;
        }
        
        return res;
    }
};
