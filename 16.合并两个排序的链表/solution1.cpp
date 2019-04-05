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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *res = new ListNode(0);
        ListNode *p;
        ListNode *res_end = res;
        while(pHead1 != NULL && pHead2 != NULL){
            if(pHead1->val <= pHead2->val){
                p = pHead1;
                pHead1 = pHead1->next;
                res_end->next = p;
                p->next = NULL;
                res_end = p;
            }
            else{
                p = pHead2;
                pHead2 = pHead2->next;
                res_end->next = p;
                p->next = NULL;
                res_end = p;
            }
        }
        if(pHead1 != NULL){
            res_end->next = pHead1;
        }
        if(pHead2 != NULL){
            res_end->next = pHead2;
        }
        
        return res->next;
    }
};
