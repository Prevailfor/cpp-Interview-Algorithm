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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        stack<TreeNode*> st;
        TreeNode* pre = NULL, *curNode = pRootOfTree, *res = NULL;
        while(!st.empty() || curNode){
            while(curNode != NULL){
                st.push(curNode);
                curNode = curNode->left;
            }
            curNode = st.top();
            st.pop();
            
            if(pre != NULL){
                pre->right = curNode;
                curNode->left = pre;
            }
            else{
                res = curNode;
            }
            pre = curNode;
            curNode = curNode->right;
        }
        return res;
    }
};
