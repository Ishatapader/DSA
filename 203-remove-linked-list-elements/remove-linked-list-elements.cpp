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
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val) {
            ListNode* del = head;
            head = head->next;
            delete del;
        }
        ListNode* prev = NULL;
        ListNode* temp = head;

        while (temp != NULL) {
            if (temp->val == val) {
                prev->next = temp->next;
                ListNode* newNode = temp->next;
                delete temp;
                temp = newNode;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};