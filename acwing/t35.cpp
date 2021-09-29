#define NULL 0
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* fakeHead = new ListNode(0);
        fakeHead->next = head;

        ListNode* p = fakeHead;
        ListNode* q = fakeHead->next;
        fakeHead->next = NULL;
        while(q) {
            ListNode* r = q->next;
            insertNodeFromHead(fakeHead, q);
            q = r;
        }
        ListNode* a = fakeHead->next;
        delete fakeHead;
        return a;
    }
    void insertNodeFromHead(ListNode* head, ListNode* node) {
        ListNode* p = head->next;
        head->next = node;
        node->next = p;
    }
};