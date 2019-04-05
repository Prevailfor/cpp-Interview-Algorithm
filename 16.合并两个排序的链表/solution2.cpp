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
    // recursion: have return value, firt formt top to bottom, then return .
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL) return pHead2;
        else if(pHead2 == NULL) return pHead1;
        ListNode *retv = NULL;
        if(pHead1->val <= pHead2->val){
            retv = pHead1;
            retv->next = Merge(pHead1->next, pHead2);
        }
        else if(pHead1->val > pHead2->val){
            retv = pHead2;
            retv->next = Merge(pHead1, pHead2->next);
        }
        return retv;
    }
};
