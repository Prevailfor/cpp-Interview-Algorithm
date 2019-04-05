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
    
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        //---------------way one
        ListNode * ed = pListHead;
        // create the k distance between a and b; a is the head;
        // when b is null, a is the reverse kth node;
        for(int i = 0; i < k; ++i){
            if(ed == NULL)
                return NULL; // guarantee that the reverse kth node exsit;
            ed = ed->next;
        }
        while(ed != NULL){
            ed = ed->next;
            pListHead = pListHead->next;
        }
        return pListHead;
        
        //--------------->way two: simplify the way one
      /*ListNode *toNull = pListHead;
        ListNode *toresult = pListHead;
        int m_k = 0;
        for(; toNull!=NULL; m_k++){
            if(m_k >= k) toresult = toresult->next;
            toNull = toNull->next;
        }
        return m_k>=k? toresult : NULL;
      */
    }
};
