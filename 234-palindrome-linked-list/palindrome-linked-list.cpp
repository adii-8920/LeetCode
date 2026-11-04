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
class Solution {
public:
    ListNode* getMid(ListNode* head){
        ListNode* slow= head;
        ListNode* fast= head->next;
        while(fast != NULL && fast->next != NULL){
            fast= fast->next->next;
            slow= slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev= NULL;
        ListNode* curr= head;
        ListNode* forward= NULL;
        while(curr != NULL){
            forward= curr->next;
            curr->next= prev;
            prev= curr;
            curr= forward;
        }
        return prev;//Reversed LL ka head
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }
        //Step-1: Find Middle
        ListNode* middle= getMid(head);

        //Step-2: Reverse list after middle
        ListNode* temp= middle->next;
        middle->next= reverse(temp);

        ListNode* head1= head;
        ListNode* head2= middle->next;
        
        //Step-3: Compare both halves
        while(head2 != NULL){
            if(head1->val != head2->val){
                return false;//Not a Palindrome
            }
            head1= head1->next;
            head2= head2->next;
        }
        
        //Step-4: Repeat Step 2 to get original LL back(Optional Step)
        temp= middle->next;
        middle->next= reverse(temp);

        //Agar loop ke baahar aaye ho matlab palindrome toh hai
        return true;

    }
};