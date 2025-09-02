#include <iostream>
#include <vector>
using namespace std;

//Definition for singly linked list
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};

class Solution{
public:
    int getDecimalValue(ListNode* head){
        int result=0;
        while(head){
            //left shift result by 1 and add current node's value
            result=(result<<1) | head->val;
            head=head->next;
        }
        return result;
    }
};

//Helper to build linked list
ListNode* buildList(const vector<int>& bits){
    ListNode dummy(0);
    ListNode* curr=&dummy;
    for(int b : bits){
        curr->next=new ListNode(b);
        curr=curr->next;
    }
    return dummy.next;
}

//Test
int main(){
    vector<int> bits={1, 0, 1}; //Binary 101 => Decimal 5
    ListNode* head=buildList(bits);

    Solution sol;
    cout<<"Decimal value:"<<sol.getDecimalValue(head)<<endl; //Output: 5

    return 0;
}