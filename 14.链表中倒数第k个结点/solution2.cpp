/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
int counts = 0;
class Solution {
public:
    // By using the recursion having return value, this recurision can return reverse kth node.
    // when recursion push stack, the aim is to reach the null of end node next postion.
    // when recrusion pop stack, there are two parts, calling reverse k-th next node to end node part and first to reverse kth-part.
    // if it is the first part, just count and return null. otherwise, return the result node which is the reverse kth node.
    // static int counts; // must be initialized during compiling. 
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL) return NULL; // return end node next position
        ListNode *return_v = FindKthToTail(pListHead->next, k);
        if(return_v != NULL) return return_v; // reach the second part during recrusion is in pop stack;
        counts++; // count the number of pop stack times;
        if(counts == k) return pListHead; // find reverse k-th node ;
        else return NULL; // first part return
    }
};
