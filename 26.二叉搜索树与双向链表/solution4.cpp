
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL) return pRootOfTree;
        pRootOfTree = ConvertNode(pRootOfTree);
        while(pRootOfTree->left) pRootOfTree = pRootOfTree->left;
        return pRootOfTree;
    }
 
    TreeNode* ConvertNode(TreeNode* root)
    {
        if(root == NULL) return root;
        if(root->left)
        {
            TreeNode *left = ConvertNode(root->left);
            while(left->right) left = left->right;
            left->right = root;
            root->left = left;
        }
         
        if(root->right)
        {
            TreeNode *right = ConvertNode(root->right);
            while(right->left) right = right->left;
            right->left = root;
            root->right = right;
        }
        return root;
    }
};

/*

class Solution {
public:
    vector<TreeNode*> nodes;
     
    void tranverse(TreeNode* pRoot) {
        if (nullptr == pRoot)
            return;
        tranverse(pRoot->left);
        nodes.push_back(pRoot);
        tranverse(pRoot->right);
    }
     
    TreeNode* adjustTree() {
        for (int i = 0; i < nodes.size() - 1; ++i)
            nodes[i]->right = nodes[i+1];
        nodes[nodes.size()-1]->right = nullptr;
        for (int i = nodes.size() - 1; i > 0; --i)
            nodes[i]->left = nodes[i-1];
        nodes[0]->left = nullptr;
        return nodes[0];
    }
     
    TreeNode* Convert(TreeNode* pRoot)
    {
        if (nullptr == pRoot)
            return nullptr;
        tranverse(pRoot);
        return adjustTree();
    }
};
*/
