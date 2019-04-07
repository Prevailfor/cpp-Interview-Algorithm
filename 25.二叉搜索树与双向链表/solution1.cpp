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
        TreeNode * lm = TubleList(pRootOfTree, -1);
        if(lm == NULL)
            return lm;
        // notice to check whether lm is NULL
        while(lm->left != NULL)
            lm = lm->left;
        return lm;
    }
    
    // use mid-recursion to visit.
    TreeNode* TubleList(TreeNode * pRootOfTree, int lor){
        if(pRootOfTree == NULL)
            return NULL;
        TreeNode *rtl, *rtr;
        
        rtl = TubleList(pRootOfTree->left,-1); // the left.
        if(rtl != NULL){
            rtl->right = pRootOfTree;
            pRootOfTree->left = rtl;
        }
        
        rtr = TubleList(pRootOfTree->right, 1); // the right.
        if(rtr != NULL){
            rtr->left = pRootOfTree;
            pRootOfTree->right = rtr;
        }
        
        if(rtr != NULL && lor == -1) // if this node is the left-child-tree of temproot node. return the max-val of the left-child-tree
            return rtr;              
        if(rtl != NULL && lor == 1) // otherwise...
            return rtl;
        return pRootOfTree;
    }
};
