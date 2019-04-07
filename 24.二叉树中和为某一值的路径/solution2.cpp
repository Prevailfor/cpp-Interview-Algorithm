/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<vector<int> > res;
    vector<int> tmp;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root == NULL)
            return res;
        dfs(root, expectNumber);
        return res;
    }
    
    void dfs(TreeNode* root, int target){ // root must not be NULL.
        tmp.push_back(root->val);
        int tsub = target - root->val;
        
        if(root->left==NULL && root->right==NULL && tsub==0){ // leaf node
            res.push_back(tmp);
            return;
        }
        if(root->left!=NULL)
            dfs(root->left, tsub);
        if(root->right!=NULL)
            dfs(root->right, tsub);
        
        tmp.pop_back();
    }
    
};
