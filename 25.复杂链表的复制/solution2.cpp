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
    // a more effective way which include time and space, divide into three steps
    //1.copy evey node of the original list to the nexte place of these original node and connect one list.
    //2.the random pointer of every new node direct the next node of random pointer of original node.
    //3.reconstruct the list to two list, a original list and the copy list.
    RandomListNode* Clone(RandomListNode* pHead)
    {   if(pHead == NULL)
            return NULL;
        CloneNodes(pHead);
        AdjustRandompt(pHead);
        return GetNewList(pHead);
    }
    
    //1.
    void CloneNodes(RandomListNode* pHead){
        while(pHead != NULL){
            RandomListNode* newone = new RandomListNode(pHead->label);
            newone->next = pHead->next;
            pHead->next = newone;
            pHead = newone->next;
        }
    }
    //2.
    void AdjustRandompt(RandomListNode* pHead){
        while(pHead != NULL){
            if(pHead->random != NULL)
                pHead->next->random = pHead->random->next;
            else if(pHead->random == NULL)
                pHead->next->random = NULL;
            pHead = pHead->next->next;    
        }
        
    }
    //3.
    RandomListNode* GetNewList(RandomListNode* pHead){
        RandomListNode* newList, *newNode;
        newList = pHead->next;
        
        // judge pHead->next->next != NULL is easy than judge pHead->next!=NULL;
        while(pHead->next->next != NULL){
            newNode = pHead->next;
            pHead->next = newNode->next;
            pHead = pHead->next;
            newNode->next = pHead->next;
        }
        pHead->next->next = NULL;
        pHead->next = NULL;
        
        return newList;
    }
    
};















