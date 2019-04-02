/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
// the way to deal with n-node list and the way to deal with n+1_node list is same
// so, this imply using recursion
class Solution {
public:
    vector<int> rec_v;
    vector<int> printListFromTailToHead(ListNode* head) {
        rec_visit(head);
        return rec_v;
    }
    
    void rec_visit(ListNode * head){
        if(head == NULL)
            return ;
        
        rec_visit(head->next);
        
        rec_v.push_back(head->val);
    }
    
    // OR wirte in one function
    /*
    
    vector<int> printListFromTailToHead(ListNode* head){
        vector<int> res;
        if(head == NULL)
            return res;
        res.push_back(head->val);
        vector<int> tres;
        tres = printListFromTailToHead(head->next);
        if(!tres.empty())
            res.insert(res.begin(), tres.begin(), tres.end());
        return res;
    }
    
    */
    
};
