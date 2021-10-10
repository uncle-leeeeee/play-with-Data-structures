#include "ListNode.h"

//带有虚拟头结点的写法
template <typename T>
class Solution3
{
public:
    ListNode<T> *removeElements(ListNode *head, int val)
    {
        ListNode<T> *dummyHead = new ListNode<T>(-1); //新建一个虚拟的头结点
        dummyHead->next = head;                       //将虚拟头结点指向真正的头结点
        ListNode<T> *prev = dummyHead;                //从虚拟头结点开始遍历，这样要删除第一个节点时也和删除中间节点一样的操作了
        while (prev->next != nullptr)
        {
            if (prev->next->val == val)
            {
                prev->next = prev->next->next;
            }
            else
            {
                prev = prev->next;
            }
        }
        prev = nullptr;
        delete prev;
        return dummyHead->next; //返回真正的头结点，用户不需要获取虚拟头结点。
    }
};