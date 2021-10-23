template <typename T>
class Solution5
{
public:
    ListNode<T> *removeElements(ListNode<T> *head, int val)
    {
        if (head == nullptr)
        {
            return head;
        }
        else
        {
            head->next = removeElements(head->next, val);
            return head->val == val ? head->next : head; //利用三目运算符
        }
    }
};