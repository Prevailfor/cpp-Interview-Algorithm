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
    // recursion: use the recursion stack state to reverse the list.
    //            1.reach the end point of the list.
    //            2.return the result. no matter whether the list is null.
    //            3.by the step one and two, the current node's next node must not be null
    //            cur->next->nxt = cur;
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==NULL || pHead->next==NULL) return pHead; // aim: 1. if the list is null or have only one node, just return. 2.return the result node(reverse head)
        ListNode* revNode = ReverseList(pHead->next);     // reache the end node.
        pHead->next->next = pHead;                                                  //now the pHead must be in the pre-positon of the end node.
        pHead->next = NULL; // if the node is the head of initial list, pHead->next = null work to gurantee it is the last node of reverlist.
        
        return revNode;
    }
};
