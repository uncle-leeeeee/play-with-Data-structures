#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class Node
{
public: //node这些信息不能声明为私有成员，否则从外界无法访问其e与next元素；应该是直接封装在LinkedList里面，通过LL类来进行对外界的屏蔽保护。
    T e;
    Node<T> *next;

    Node(T e, Node *next) : e(e), next(next) {}
    Node(T e) : e(e), next(nullptr) {}
    Node() : next(nullptr) {}
};

template <typename T>
class LinkedList
{
private:
    Node<T> *dummyhead; //两个私有成员变量，一个虚拟头节点和链表元素个数
    int size;

public:
    /*
    无参构造函数
    getsize获取元素个数
    isEmpty
    在链表添加元素(头，中部，尾部)addFirst(T e) add(int index,T e), addLast(T e),记得维护size变量
    获取链表第index个位置的元素。
    修改链表中的第index个位置的元素
    查找链表中是否有元素e 
    从链表中删除一个元素；删除第一个元素，删除第二个元素。
    */

    LinkedList()
    {
        dummyhead = new Node<T>(); //添加一个虚拟头节点，表示该头节点再后一节点才是真正的头节点；以便通过add方式来插入元素。
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void add(int index, T e)
    {
        assert(index >= 0 && index <= size); //判断index位置，最大可以是size位置

        Node<T> *prev = dummyhead;
        for (int i = 0; i < index; i++)
        {
            prev = prev->next;
        }
        prev->next = new Node<T>(e, prev->next);
        size++;
    }

    void addFirst(T e)
    {
        add(0, e);
    }

    void addLast(T e)
    {
        add(size, e);
    }

    T get(int index)
    {
        assert(index >= 0 && index < size); //这里不能够取到size，因为下标从0开始，size下标其实是没有元素的，最多取到size-1
        Node<T> *cur = dummyhead->next;
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        return cur->e;
    }

    T getFirst()
    {
        return get(0);
    }

    T getLast()
    {
        return get(size - 1); //因为get函数是按index取元素，所以链表中最后一位元素的下标为size-1，因此使用get(size-1)，而不是get(size)
    }
    //修改第index为元素
    void set(int index, T e)
    {
        assert(index >= 0 && index < size);
        Node<T> *node = dummyhead->next;
        for (int i = 0; i < index; i++)
        {
            node = node->next;
        }
        node->e = e;
    }

    //修改第一位元素
    void setFirst(T e)
    {
        set(0, e);
    }

    //修改最后一位元素
    void setLast(T e)
    {
        set(size - 1, e);
    }

    //判断该链表中是否包含某元素
    bool ifContain(T e)
    {
        Node<T> *cur = dummyhead->next;
        while (cur != nullptr)
        {
            if (cur->e == e)
                return true;
            cur = cur->next;
        }
        return false;
    }

    //从链表中删除一个元素
    T remove(int index)
    {
        //判断index是否符合规则
        assert(index >= 0 && index < size);
        Node<T> *pre = dummyhead;
        //需要定位到该index的前一个元素
        for (int i = 0; i < index; i++)
        {
            pre = pre->next;
        }

        Node<T> *TemNode = pre->next;
        pre->next = TemNode->next;
        TemNode->next = nullptr;
        size--;
        return TemNode->e;
    }

    //删除第一个元素
    T removeFirst()
    {
        return remove(0);
    }

    //删除最后一个元素
    T removeLast()
    {
        return remove(size - 1);
    }

    //打印该链表信息
    void print()
    {
        Node<T> *node = dummyhead->next;
        cout << "LinkedList: size= " << size << endl;
        cout << "[";
        while (node != nullptr)
        {
            if (node->next != nullptr)
            {
                cout << node->e << ",";
            }
            else
            {
                cout << node->e;
            }
            node = node->next;
        }
        cout << "]" << endl;
    }
};
