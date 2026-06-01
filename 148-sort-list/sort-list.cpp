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
    class List {
    public:
        ListNode* head;
        ListNode* tail;

        List() {
            head = NULL;
            tail = NULL;
        }

        void push_back(int val) {
            ListNode* newNode = new ListNode(val);
            if (head == NULL) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    };
    ListNode* merge(ListNode* left, ListNode* right) {
        List ans; // Creating new list
        ListNode* i = left;
        ListNode* j = right;
        while (i != NULL && j != NULL) {
            if (i->val <= j->val) {
                ans.push_back(i->val);
                i = i->next;
            } else {
                ans.push_back(j->val);
                j = j->next;
            }
        }
        while (i != NULL) {
            ans.push_back(i->val);
            i = i->next;
        }
        while (j != NULL) {
            ans.push_back(j->val);
            j = j->next;
        }

        return ans.head; // returning the head of answer
    }
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
        return slow; // rightNode = slow
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* rightHead = splitAtMid(head);
        ListNode* left = sortList(head);       // left head
        ListNode* right = sortList(rightHead); // right head
        return merge(left, right);
    }
};