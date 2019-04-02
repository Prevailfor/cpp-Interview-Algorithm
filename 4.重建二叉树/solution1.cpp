/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // dfs from bottom to top
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size()==0)
            return NULL;
      //else if(pre.size()==1)
      //    return pre.front();
        
        // to find index of pre[0] in vin
        /*
        int k;
        for(int i = 0; i < vin.size(); ++i){
            if(pre[0] == vin[i]){
                k = i;
                break;
            }
        }
        */
        int k = find(vin.begin(), vin.end(), pre.front()) - vin.begin();
        TreeNode * troot = new TreeNode(vin[k]);
        /*
        vector<int > lpre, lvin, rpre, rvin;
        for(int i = 1; i <=k; ++i){
            lpre.push_back(pre[i]);
        }
        for(int i = k+1; i < pre.size(); ++i){
            rpre.push_back(pre[i]);
        }
        for(int i = 0; i < k; ++i){
            lvin.push_back(vin[i]);
        }
        for(int i = k+1; i < vin.size(); ++i){
            rvin.push_back(vin[i]);
        }
        troot->left = reConstructBinaryTree(lpre, lvin);
        troot->right = reConstructBinaryTree(rpre, rvin);
        */
        
        troot->left = reConstructBinaryTree(vector<int>(pre.begin()+1, pre.begin()+k+1), vector<int>(vin.begin(),vin.begin()+k));
        troot->right= reConstructBinaryTree(vector<int>(pre.begin()+k+1, pre.end()), vector<int>(vin.begin()+k+1, vin.end()));
        return troot;
    }
};
