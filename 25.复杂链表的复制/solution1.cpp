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
    // use relative array called map to store the informaiton of node.
    RandomListNode* Clone(RandomListNode* pHead)
    {    
        RandomListNode* res, *pHoper, *pre, *tail;
        res = pre = NULL; // when res is defined, it is not null, need to be assigned null.
        if(pHead == NULL)
            return res;
        vector<RandomListNode*> storeres;
        map<RandomListNode*, int> Node2Index;
        pHoper = pHead;
        int cts = 0;
        // add the next, and record node. 
        // storeres[0,1,,,,n-1] = newnode1, newnode2,...., newnoden;
        //Node2Index[node1, node2...] = 0, 1, ....
        //storeres[New_x]->random = storeres[Node2Index[Original_x->random]];
        while(pHoper != NULL){
            if(pre == NULL){
                res = tail = new RandomListNode(pHoper->label);
                storeres.push_back(res);
                Node2Index.insert(pair<RandomListNode*, int>(pHoper, cts++));
                pre = tail;
            }
            else{
                pre->next = tail = new RandomListNode(pHoper->label);
                storeres.push_back(tail);
                Node2Index.insert(pair<RandomListNode*, int>(pHoper, cts++));
                pre = tail;
            }
            pHoper = pHoper->next;
        }
        storeres.back()->next = NULL;
        
        // add random pointer
        pHoper = pHead;
        cts = 0;
        while(pHoper != NULL){
            if(pHoper->random == NULL)
                storeres[cts]->random = NULL;
            else
                storeres[cts]->random = storeres[Node2Index[pHoper->random]];
            cts++;
            pHoper = pHoper->next;
        }
        
        return res;
    }
};
