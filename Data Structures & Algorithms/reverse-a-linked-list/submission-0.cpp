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
    ListNode* recurse(ListNode** temp, ListNode** end) {
        if((*temp)->next == nullptr) {
            *end = *temp;
            return *temp;
        }
        ListNode *trav = (*temp)->next;
        (*temp)->next = nullptr;
        trav = recurse(&trav, end);
        (*end)->next = *temp;
        *end = *temp;
        *temp = trav;
        return *temp;
    }
    ListNode* reverseList(ListNode* head) {
        // head -> 1 -> 2
        // head -> 2 -> 1
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *end = nullptr, *temp = head->next;
        head->next = nullptr;
        temp = recurse(&temp, &end);
        end->next = head;
        head = temp;
        return head;
    }
};

/*
head -> 1 -> 2 -> 3
3 -> 2 -> 1
*/