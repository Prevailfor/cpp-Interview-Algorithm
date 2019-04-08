/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    //a recursion way of three step, just write very beautifule
    //assumption the list maybe a graph.
    unordered_map<RandomListNode*, RandomListNode*>oldnode_newnode;// original node <==> newlist node
    set<RandomListNode*> vis;
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;
        oldnode_newnode.clear();
        vis.clear();
        dfs1(pHead);
        dfs2(pHead);
        return oldnode_newnode[pHead];
    }
    // creat the new node corresponding the original old and generate the map.
    void dfs1(RandomListNode* visone){
        if(visone!=NULL && oldnode_newnode.find(visone)==oldnode_newnode.end()){
            oldnode_newnode[visone] = new RandomListNode(visone->label);
            dfs1(visone->next);
            dfs1(visone->random);
        }
    }
    //adjuge the next and random of every node of the new list.
    void dfs2(RandomListNode* visone){
        if(visone!=NULL && vis.find(visone)==vis.end()){
            if(visone->next) oldnode_newnode[visone]->next = oldnode_newnode[visone->next];
            if(visone->random) oldnode_newnode[visone]->random = oldnode_newnode[visone->random];
            vis.insert(visone);
            dfs2(visone->next);
            dfs2(visone->random);
        }
    }
};
