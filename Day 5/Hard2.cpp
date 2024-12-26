Ques 5. You are given an array of k linked-lists lists, each linked-list is sorted 
in ascending order. 
Merge all the linked-lists into one sorted linked-list and return it. 
 
Program Code: 
#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std; 
struct ListNode { 
    int val; 
    ListNode* next; 
    ListNode() : val(0), next(nullptr) {} 
    ListNode(int x) : val(x), next(nullptr) {} 
    ListNode(int x, ListNode* next) : val(x), next(next) {} 
}; 
class Solution { 
public: 
    ListNode* mergeKLists(vector<ListNode*>& lists) { 
        auto compare = [](ListNode* a, ListNode* b) { return a->val > b->val; }; 
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> 
minHeap(compare); 
 
        for (ListNode* list : lists) { 
            if (list) minHeap.push(list); 
        } 
        ListNode dummy(0); 
        ListNode* current = &dummy; 
        while (!minHeap.empty()) { 
            ListNode* node = minHeap.top(); 
            minHeap.pop(); 
            current->next = node; 
            current = current->next; 
            if (node->next) minHeap.push(node->next); 
        } 
        return dummy.next; 
    } 
}; 
 
int main() { 
    ListNode* l1 = new ListNode(1, new ListNode(4, new ListNode(5))); 
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4))); 
    ListNode* l3 = new ListNode(2, new ListNode(6)); 
    vector<ListNode*> lists = {l1, l2, l3}; 
 
    Solution solution; 
    ListNode* result = solution.mergeKLists(lists); 
 
    while (result) { 
        cout << result->val << " "; 
        result = result->next; 
    } 
return 0; 
} 
