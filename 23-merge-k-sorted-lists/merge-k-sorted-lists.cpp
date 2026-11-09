/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class compare{
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
    
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
    int k= lists.size();
    if(k == 0){
        return NULL;//LL me kuch hoga hi nahi
    }
    
    //Step-1: starting ke k elements ko minHeap me daal do
    for(int i= 0; i< k; i++){
        if(lists[i] != NULL){
            minHeap.push(lists[i]);
        }
    }

    ListNode* head= NULL;
    ListNode* tail= NULL;

    while(minHeap.size()> 0){
        ListNode* top= minHeap.top();
        minHeap.pop();

        //ab LL me daal rahe hain minHeap ke elements ko
        if(head == NULL){//answer LL is empty
            head= top;
            tail= top;

            if(tail->next != NULL){
                minHeap.push(tail->next);
            }
        }
        else{//insert at end
            tail->next= top;
            tail= top;
            if(tail->next != NULL){
                minHeap.push(tail->next);
            }
        }
    }
    return head; 
    }
};