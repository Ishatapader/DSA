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
    ListNode* splitAtMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev != NULL) {
            prev->next = NULL;
        }
        return slow;
    }
    ListNode* revRightHead(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev; 
    }
    void reorderList(ListNode* head) {
        ListNode* rightHead = splitAtMid(head);
        ListNode* reverseRightHead = revRightHead(rightHead);

        // alternate merging
        ListNode* left = head;
        ListNode* right = reverseRightHead;
        ListNode* tail = NULL;
        while (left != NULL && right != NULL) {
            ListNode* nextLeft = left->next;
            ListNode* nextRight = right->next;
            left->next = right;
            right->next = nextLeft;
            tail = right; 
            left = nextLeft;
            right = nextRight;
        }
        if (right != NULL) {
            tail->next = right;
        }
    }
};