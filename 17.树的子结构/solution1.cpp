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
    // find in the pre-order.
    int st1[1000];
    int st2[1000];
    int len1, len2;
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2 == NULL)
            return false;
        len1 = len2 = 0;
        MOrder1(pRoot1);
        MOrder2(pRoot2);
        int i = 0;
        int j = 0;
        while( i < len1 && j < len2 ){
            if(st1[i] == st2[j]){
                ++i;
                ++j;
            }
            else{
               if(j==0) i++;
               else j = 0;
            }
        }
        if(j == len2)
            return true;
        else
            return false;
        
    }
    
    void MOrder1(TreeNode *p){
        if(p == NULL)
            return;
        st1[len1++] = p->val;
        MOrder1(p->left);
        
        MOrder1(p->right);
    }
    void MOrder2(TreeNode *p){
        if(p == NULL)
            return;
        st2[len2++] = p->val;
        MOrder2(p->left);
        
        MOrder2(p->right);
    }
};
