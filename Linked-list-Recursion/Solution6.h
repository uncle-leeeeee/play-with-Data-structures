#include <iostream>
template <class T>
class Solution6
{
public:
    //定义一个去除特定元素的函数，要传入调用时的深度
    ListNode<T> *removeElements(ListNode<T> *head, int val, int depth)
    {
        print(depth);                                 //表示这是在第几层调用该函数
        std::cout << "Call: remove " << val << " in"; //要删除的元素是
        head->print();                                //打印出目前的链表元素

        if (head == nullptr)
        {
            print(depth);
            std::cout << "Return: ";
            head->print();
            return head;
        }

        ListNode<T> *res = removeElements(head->next, val, depth + 1); //在下一个节点处递归调用
        print(depth);                                                  //输出当前深度
        std::cout << "After remove" << val << ":";                     //输出在删除节点后的子链情况
        res->print();
        ListNode<T> *ret;
        if (head->val == val)
        {
            ret = res;
        }
        else
        {
            head->next = res;
            ret = head;
        }
        print(depth);
        std::cout << "Return:"; //在判断头结点情况后，返回当前链表状态。
        ret->print();
        return ret;
    }

    void print(int depth)
    {
        for (int i = 0; i < depth; i++)
        {
            std::cout << "--";
        }
    }
};
