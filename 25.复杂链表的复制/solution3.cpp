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
    typedef pair<RandomListNode*, RandomListNode*> mk;
    unordered_map<RandomListNode*, RandomListNode*> old_new;
    RandomListNode* Clone(RandomListNode* pHead)
    {   if(pHead == NULL)
            return NULL;
        RandomListNode* newone = new RandomListNode(pHead->label);
        old_new.insert(mk(pHead, newone));
        // first push stack,and record the unorded_map
        newone->next = Clone(pHead->next);
        // pop back, now, adjust the random.
        newone->random = old_new[pHead->random];
        return newone;
    }
};
