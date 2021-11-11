template <class T>
//定义节点类，存放数结构中的节点
class Node
{
public:
    T e;
    Node<T> *left, right;
    Node(T e)
    {
        this->e = e;
        left = nullptr;
        right = nullptr;
    }
};
//定义二叉搜索树结构
template <class T>
class BST
{
private:
    Node<T> *root;
    int size;

public:
    BST() //无参构造函数
    {
        root = nullptr;
        size = 0;
    }

    int getsize()
    {
        return this->size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void add(T e) //添加元素，参数为一个整型变量
    {
        if (root == nullptr) //如果跟节点为空，则直接创建新节点
        {
            root = new Node<T> *(e);
            size++;
        }
        else
        {
            add(root, e);
        }
    }

    //添加元素的递归函数，参数为根节点和元素
    void add(Node<T> *node, int e)
    {
        //首先判断当前节点元素是否重复了,重复了就不用继续添加
        if (node->e == e)
        {
            return;
        }
        else if (node->e > e && node->left == nullptr)
        { //如果当前元素e大于参数e，同时左子树节点为空，则添加到左子树
            node->left = new Node<T> *(e);
            size++;
            return;
        }
        else if (node->e < e && node->right == nullptr)
        { //如果当前元素e小于于参数e，同时右子树节点为空，则添加到左子树
            node->right = new Node<T> *(e);
            size++;
            return;
        }
        if (node->e > e) //如果仅仅是大于当前节点元素，则直接在左子树节点递归调用add函数
        {
            add(node->left, e);
        }
        else //同理
        {
            add(node->right, e);
        }
    }
};