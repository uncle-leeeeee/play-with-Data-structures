#include <stack>
#include <queue>
template <class T>
//定义节点类，存放数结构中的节点
class Node
{
public:
    T e;
    Node<T> *left, *right;
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

    //对add递归函数进行优化，使用更加简洁的递归方式
    Node<T> *add(Node<T> *node, T e)
    {
        //如果节点为空，则new一个node并返回该节点，
        if (node == nullptr)
        {
            size++; //记得元素个数要自增
            return new Node<T>(e);
        }

        //否则直接判断该元素与当前节点的大小关系，看是在左子树添加还是在右子树添加
        if (node->e > e) //在左子树添加
        {
            node->left = add(node->left, e);
        }
        else if (node->e < e) //在右子树添加
        {
            node->right = add(node->right, e);
        }
        //最后记得返回节点本身
        return node;
    }

    bool contains(Node<T> *node, T e)
    {
        if (node == nullptr)
        {
            return false;
        }
        else if (node->e == e)
        {
            return true;
        }
        else if (node->e > e)
        {
            return contains(node->left, e);
        }
        else
        {
            return contains(node->right, e);
        }
    }

    //先序遍历,根左右
    void preOrder(Node<T> *node)
    {
        if (node == nullptr)
        {
            return;
        }
        std::cout << node->e << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    //中序遍历，左根右
    void inOrder(Node<T> *node)
    {
        if (node == nullptr)
        {
            return;
        }
        inOrder(node->left);
        std::cout << node->e << " ";
        inOrder(node->right);
    }

    //后序遍历，左右根
    void postOrder(Node<T> *node)
    {
        if (node == nullptr)
        {
            return;
        }
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->e << " ";
    }

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
            root = new Node<T>(e); //new 已经是返回一个指针了，所以无需创建指针类型
            size++;
        }
        else
        {
            add(root, e);
        }
    }

    //添加元素的递归函数，参数为根节点和元素
    // void add(Node<T> *node, T e)
    // { //这里的递归判断条件比较臃肿，是第一种写法
    //     //首先判断当前节点元素是否重复了,重复了就不用继续添加
    //     if (node->e == e)
    //     {
    //         return;
    //     }
    //     else if (node->e > e && node->left == nullptr)
    //     { //如果当前元素e大于参数e，同时左子树节点为空，则添加到左子树
    //         node->left = new Node<T>(e);
    //         size++;
    //         return;
    //     }
    //     else if (node->e < e && node->right == nullptr)
    //     { //如果当前元素e小于于参数e，同时右子树节点为空，则添加到左子树
    //         node->right = new Node<T>(e);
    //         size++;
    //         return;
    //     }
    //     if (node->e > e) //如果仅仅是大于当前节点元素，则直接在左子树节点递归调用add函数
    //     {
    //         add(node->left, e);
    //     }
    //     else //同理
    //     {
    //         add(node->right, e);
    //     }
    // }

    //判断某元素是否在该二叉树中
    bool contains(T e)
    {
        return contains(root, e);
    }

    void preOrder()
    { //先序遍历，左根右
        return preOrder(root);
    }

    void inOrder()
    {
        return inOrder(root);
    }

    void postOrder()
    {
        return postOrder(root);
    }

    //非递归形式的前序遍历
    void preOrderNR()
    {
        std::stack<Node<T> *> s1; //声明栈
        s1.push(root);            //先把根节点push进入栈中
        while (!s1.empty())       //当该栈不为空时
        {
            Node<T> *node = s1.top();
            std::cout << node->e << " ";
            s1.pop();
            if (node->right != nullptr)
            { //先把右节点压入栈
                s1.push(node->right);
            }
            if (node->left != nullptr)
            {
                s1.push(node->left); //再把左节点压入栈
            }
        }
        std::cout << std::endl;
    }

    //非递归形式的中序遍历
    void inOrderNR()
    {
        std::stack<Node<T> *> stack;
        Node<T> *cur = root;
        while (cur != nullptr || !stack.empty())
        {
            while (cur != nullptr)
            {
                stack.push(cur);
                cur = cur->left;
            }
            if (!stack.empty())
            {
                cur = stack.top();
                std::cout << cur->e << " ";
                stack.pop();
                cur = cur->right;
            }
        }
        std::cout << std::endl;
    }

    //非递归形式的后序遍历，这个比较复杂，左右中
    void postOrderNR()
    {
        std::stack<Node<T> *> stack;
        Node<T> *cur = root;
        Node<T> *temp;
        while (cur != nullptr || !stack.empty())
        {
            while (cur != nullptr) //当当前节点不为空时，不端遍历，把左子树入栈
            {
                stack.push(cur);
                cur = cur->left;
            }
            if (!stack.empty()) //当栈不为空时，取出栈顶元素，并判断右子树节点是否为空，若为空则输出当前节点值
            {
                cur = stack.top();
                if (cur->right == temp || cur->right == nullptr)
                {
                    std::cout << cur->e << " ";
                    stack.pop();
                    temp = cur;
                    cur = nullptr;
                }
                else
                {
                    cur = cur->right;
                }
            }
        }
        std::cout << std::endl;
    }

    void generateDepthString(int depth)
    {
        for (int i = 0; i < depth; i++)
        {
            std::cout << "--";
        }
    }

    //对于给定的节点，遍历输出二叉树中元素,以先序遍历形式输出
    void generateBSTString(Node<T> *node, int depth)
    {
        if (node == nullptr) //若为空节点
        {
            generateDepthString(depth); //输出该节点所处树的深度
            std::cout << "NULL" << std::endl;
            return;
        }
        generateDepthString(depth);
        std::cout << node->e << std::endl;
        generateBSTString(node->left, depth + 1);
        generateBSTString(node->right, depth + 1);
    }

    void levelOrder()
    {
        std::queue<Node<T> *> q;
        q.push(root);
        while (!q.empty())
        {
            Node<T> *temp = q.front();
            std::cout << temp->e << " ";
            if (temp->left != nullptr)
            {
                q.push(temp->left);
            }
            if (temp->right != nullptr)
            {
                q.push(temp->right);
            }
            q.pop();
        }
        std::cout << std::endl;
    }

    void print()
    {
        generateBSTString(root, 0);
    }
};