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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<TreeNode*> tstack;
        vector<int > res;
        // f: indicate the first element of the queue
        // b: indicate the next index of the last element of the queue
        
        // this step is important
        if(root == NULL)
            return res;
        int f, b;
        int oper;
        f = 0, b = 0;
        tstack.push_back(root);
        b++;
        
        // foreach evey element of the binary tree;
        while(f != b){
            oper = f;
            f++;
            res.push_back(tstack[oper]->val);
            
            if(tstack[oper]->left != NULL){
                tstack.push_back(tstack[oper]->left);
                b++;
            }
            if(tstack[oper]->right != NULL){
                tstack.push_back(tstack[oper]->right);
                b++;
            }
        }
        return res;
    }
};
