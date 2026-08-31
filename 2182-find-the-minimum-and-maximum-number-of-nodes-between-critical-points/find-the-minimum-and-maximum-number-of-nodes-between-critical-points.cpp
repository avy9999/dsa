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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = NULL;
        int idx = 0;
        vector <int> a;
        while(head != NULL){
            if (prev == NULL || head -> next == NULL){
                prev = head;
                head = head -> next;
                continue;
            }
            if (head -> val > prev -> val && head -> val > head -> next -> val){
                a.push_back(idx);
            } else if (head -> val < prev -> val && head -> val < head -> next -> val){
                a.push_back(idx);
            }
            idx++;
            prev = prev -> next;
            head = head -> next;
        }
        if (a.size() < 2) return {-1, -1};
        int mini = INT_MAX;
        int maxi = a[a.size() - 1] - a[0];
        for (int i = 1; i < a.size(); ++i){
            mini = min(mini, a[i] - a[i - 1]);
        }
        return {mini, maxi};
    }
};