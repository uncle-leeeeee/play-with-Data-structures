template <typename T>
class Solution4
{
public:
    //采用递归的方式删除对应元素
    ListNode<T> *removeElements(ListNode<T> *head, int val)
    {
        if (head == nullptr)
        {
            return head;
        }
        //新建一个指针指向后续元素执行函数后返回的节点
        ListNode<T> *res = removeElements(head->next, val);
        //如果head的val==val，那么直接返回res，否则返回head
        if (head->val == val)
        {
            return res;
        }
        else
        {
            head->next = res;
            return head;
        }
    }
};