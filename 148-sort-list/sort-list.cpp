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

    ListNode* merge(ListNode* left, ListNode* right) {

        ListNode dummy(-1);
        ListNode* tail = &dummy;

        while(left != NULL && right != NULL) {

            if(left->val <= right->val) {
                tail->next = left;
                left = left->next;
            }
            else {
                tail->next = right;
                right = right->next;
            }

            tail = tail->next;
        }

        if(left != NULL) {
            tail->next = left;
        }

        if(right != NULL) {
            tail->next = right;
        }

        return dummy.next;
    }

    ListNode* splitAtMid(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL;

        return slow;
    }

    ListNode* sortList(ListNode* head) {

        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* rightHead = splitAtMid(head);

        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);

        return merge(left, right);
    }
};