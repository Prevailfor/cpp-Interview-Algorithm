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
        TreeNode* pre = NULL;
        Mid_visit(pRootOfTree, &pre);
        while(pre != NULL && pre->left!=NULL)
            pre = pre->left;
        return pre;
    }
    
    void Mid_visit(TreeNode* pNode, TreeNode**pre){
        if(pNode == NULL)
            return ;
        
        Mid_visit(pNode->left, pre);
        
        pNode->left = *pre;
        if(*pre != NULL)
            (*pre)->right = pNode;
        *pre = pNode;
        
        Mid_visit(pNode->right, pre);
    }
    
};
