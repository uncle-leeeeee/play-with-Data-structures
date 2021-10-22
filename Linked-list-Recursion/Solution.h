//#include "ListNode.h"
//没有虚拟头结点的情况下，删除某值节点
template <typename T>
class Solution
{
public:
    ListNode<T> *removeElements(ListNode<T> *head, int val)
    {
        //当头结点就是该val时，头结点也需要删除
        while (head != nullptr && head->val == val)
        {
            ListNode<T> *delNode = head;
            head = head->next;
            delNode->next = nullptr;
            delNode = nullptr;
            delete delNode;
        }
        if (head == nullptr) //如果头结点为空，则直接返回头结点
        {
            return head;
        }

        //当是中间元素需要删除时
        ListNode<T> *prev = head;
        while (prev->next != nullptr)
        {
            if (prev->next->val == val)
            {
                ListNode<T> *delNode = prev->next;
                prev->next = delNode->next;
                delNode->next = nullptr;
                delNode = nullptr;
                delete delNode;
            }
            else
            {
                prev = prev->next;
            }
        }
        prev = nullptr;
        delete prev;
        return head;
    }
};