/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        //Make it cyclic
        ListNode* tail= headA;
        while(tail->next != NULL){
            tail= tail->next;
        }
        tail->next= headA;

        //Now finding Intersection(Starting Point of Loop)
        ListNode* slow= headB;
        ListNode* fast= headB;
        while(fast != NULL && fast->next != NULL){
            fast= fast->next->next;
            slow= slow->next;

            if(slow == fast){
                ListNode* intersection = slow;
                slow= headB;
                while(slow != intersection){
                    slow= slow->next;
                    intersection= intersection->next;
                }
                tail->next= NULL;//Undo the loop, by setting tail->next = NULL
                return slow;
            }
        }
        tail->next= NULL;//Undo the loop, by setting tail->next = NULL
        return NULL;

    }
};