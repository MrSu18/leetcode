 


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        if (head==NULL || head->next==NULL)
        {
            return head;
        }
        
        ListNode *pre=head, *cur=head->next,*next_node;
        pre->next=NULL;
        while (cur!=NULL)
        {
            next_node=cur->next;//先记录好下一个节点的位置不要丢失了
            //开始翻转
            cur->next=pre;
            pre=cur;
            cur=next_node;
        }
        return pre;
    }
};

int main()
{
    vector<int> list = {1,2,3,4,5};
    ListNode *common = new ListNode(list[0]);
    ListNode *temp=common;
    for (size_t i = 1; i < list.size(); i++)
    {
        temp->next=new ListNode(list[i]);
        temp = temp->next;
    }
    Solution test;
    test.reverseList(common);
    return 0;
}
