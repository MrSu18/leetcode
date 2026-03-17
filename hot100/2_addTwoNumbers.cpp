#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode dummy;
        ListNode* cur = &dummy;
        int carry = 0;//进位
        int sum = 0;
        while (l1 || l2 || carry) //只要有一个不是空节点，或者有进位就有继续迭代
        {
            if (l1) 
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if (l2)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            cur->next=new ListNode(sum%10); 
            cur=cur->next;
            sum=0;
        }
        return dummy.next;
    }
};

ListNode* creatList(vector<int> nums)
{
    ListNode dummy;
    ListNode* cur = &dummy;
    for (auto num : nums)
    {
        cur->next=new ListNode(num);
        cur = cur->next;
    }
    return dummy.next;
}

// 辅助函数：打印链表
void printList(ListNode* head) 
{
    cout << "[";
    while (head) 
    {
        cout << head->val;
        if (head->next) cout << ",";
        head = head->next;
    }
    cout << "]" << endl;
}

void deleteList(ListNode* head)
{
    while (head)
    {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }    
}

int main()
{
    vector<int> list1 = {0};
    vector<int> list2 = {0};
    ListNode* l1 = creatList(list1);
    ListNode* l2 = creatList(list2);
    printList(l1);
    printList(l2);
    Solution test;
    ListNode* result = test.addTwoNumbers(l1,l2);
    printList(result);
    deleteList(l1);
    deleteList(l2);
    return 0;
}
