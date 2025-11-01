/*
You are given an array of integers `nums` and the `head`of a linked list.
Return the `head` os the modified linked list after removing all nodes from the linked list
after removing all nodes from the linked list that have a value that exists in `nums`.

############
* You have:
    An array of integers -> `nums`
    A linked list-> Starting from `head`

* yOU MUST REMOVE ALL NODES WHOSE `value` APPEARS IN `nums`.

This is a filtering problem on a linked list. Kepp only those nodes not in `nums`.

1. COnvert `nums` to a `set`.
    * look up in a list is O(n)
    * Look up in a set is O(1)
    * 
2. Use a dummy node pattern
3. Traverse with two pointers
4 Return the new `head`
*/

#include <unordered_set>
#include <vector>

//Definition for singly-linked list
struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode *next):val(x), next(next){}

};

class Solution {
public:
    ListNode* modifiedList(std::vector<int>& nums, ListNode* head){
        //Step 1: Convert nums array to unordered_set for O(1) lookup
        std::unordered_set<int> to_remove(nums.begin(), nums.end());

        //Step 2: Create dummy node to handle edge cases
        ListNode* dummy=new ListNode(0);
        dummy->next=head;

        //Step 3: Traverse with two pointers
        ListNode* prev=dummy;
        ListNode* curr=head;

        while (curr !=nullptr){
            if (to_remove.count(curr->val)){
                //Value found in set -skip this node
                prev->next=curr->next;

                //Optimal: delete the removed node to avoid memory leak
                ListNode* temp=curr;
                curr=curr->next;
                delete temp;
            }else{
                //Value not in set-keep this node
                prev=curr;
                curr=curr->next;
            }
        }

        //Step 4: Get the new head and clean up dummy
        ListNode* newHead=dummy->next;
        delete dummy;

        return newHead;
    }
};

int main(){
    //Create linked list: 1->2->3->4->5
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);

    //Value to remove
    std::vector<int> nums={2, 4};

    //Remove nodes
    Solution solution;
    ListNode* result=solution.modifiedList(nums, head);

    //Result: 1->3->5

    return 0;
}