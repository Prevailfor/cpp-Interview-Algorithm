/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        
        //------------------way one:head insert method
        /*
        if(pHead == NULL || pHead->next == NULL)
            return pHead;
        ListNode *p;
        ListNode *res = new ListNode(0);
        res->next = NULL;

        while(pHead!=NULL){
            p = pHead;
            pHead = pHead->next;
            p->next = res->next;
            res->next = p;
        }
        
        return res->next;
        */
        
        //------------------way two: reverse one by one
        //pHead is the current node to operate.
        ListNode* rverHead = NULL, * pNext,* pPre = NULL;
        
        while(pHead != NULL){
            pNext = pHead ->next;
            if(pNext == NULL) 
                rverHead = pHead;
            pHead->next = pPre;
            // adjust pPre and pHead
            pPre = pHead;
            pHead = pNext;
        }
        return rverHead;
 
    }
};
