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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
       
        // level visit
        int f = 0, b = 0;
        vector<vector<int >> res;
        if(root == NULL)
            return res;
        
        vector<TreeNode *> tstack;
        vector<pair<int, int>> mk; // mk[i]->first: the pre point of this, mk[i]->second: the sum of points form the top to this node
        
        // push one node to the tstack
        tstack.push_back(root);
        b++;
        mk.push_back(pair<int, int>(-1, root->val));
        // when there are node in the tstack
        while(f != b){
            // pop the top node of the tstack
            TreeNode *p = tstack[f];
            int p_ = f;
            f++;
            //judege the top node 
            // reach leaf node
            if(p->left == NULL && p->right == NULL){
                // the top node satisfy the condition, get the route of these node
                if(mk[p_].second == expectNumber){
                      vector<int > temp;
                      int fdr = p_;
                      while(fdr != -1){
                          temp.push_back(tstack[fdr]->val);
                          fdr = mk[fdr].first;
                      }
                      reverse(temp.begin(), temp.end());
                      res.insert(res.begin(), temp);
                  }
            }
            //  not the leaf node
            else{
                if(p->left != NULL){
                    tstack.push_back(p->left);
                    mk.push_back(pair<int, int>(p_, mk[p_].second + p->left->val));
                    b++;    
                }
                if(p->right != NULL){
                    tstack.push_back(p->right);
                    mk.push_back(pair<int, int>(p_, mk[p_].second + p->right->val));
                    b++;
                }
                 
            }
            
           
            
        }
        return res;
    }
    
    
};
