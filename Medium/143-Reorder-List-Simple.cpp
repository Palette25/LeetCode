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
    void reorderList(ListNode* head) {
        vector<ListNode*> store;
        ListNode* ptr = head;
        int count = 0, size = 0;
        while(ptr != NULL) {
            store.push_back(ptr);
            ptr = ptr->next;
            ++size;
        }
        int turn = 0;
        while(head != NULL && count < (size-1)/2) {
            if(turn % 2 == 0) {
                int index = size-count-1;
                ListNode* target = store[index], *pp = head->next;
                head->next = target;
                target->next = pp;
                ++count;
            }
            head = head->next;
            ++turn;
            cout << turn << endl;
        }
    }
};
