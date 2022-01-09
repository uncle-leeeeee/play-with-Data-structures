#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "BSTSET.h"
#include "Solution.h"

template <typename T>
void shuffle(T arr[], int n)
{ //随机打乱整个数组
    srand(time(0));
    for (int i = n - 1; i >= 0; i--)
    {
        int pos = (int)(rand() % n); //随机获取下标
        T t = arr[pos];
        arr[pos] = arr[i];
        arr[i] = t;
    }
}

int main()
{
    // std::vector<std::string> words = {"apple", "mother", "damn", "messi"};
    // int size = BSTSET<std::string>().uniqueMorseRepresentations(words);
    // std::cout << "size= " << size << std::endl;
    // BST<int> bst = BST<int>();
    // for (int i = 0; i < 5; i++)
    // {
    //     bst.add(i);
    // }
    // for (int i = 0; i < 10; i += 2)
    // {
    //     std::cout << bst.contains(i) << std::endl;
    // }

    // BST<int> bst;
    // int nums[] = {5, 3, 6, 8, 4, 2};
    // for (int num : nums)
    // {
    //     bst.add(num);
    // }
    // bst.levelOrder();
    // bst.remove(6);
    // bst.levelOrder();

    // std::cout << "preorder:" << std::endl;
    // bst.preOrder();
    // std::cout << std::endl;
    // std::cout << "preOrderNR:" << std::endl;
    // bst.preOrderNR();
    // std::cout << "inorder:" << std::endl;
    // bst.inOrder();
    // std::cout << std::endl;
    // std::cout << "inOrderNR:" << std::endl;
    // bst.inOrderNR();
    // std::cout << "postorder:" << std::endl;
    // bst.postOrder();
    // std::cout << std::endl;
    // std::cout << "postOrderNR:" << std::endl;
    // bst.postOrderNR();
    // std::cout << "levelOrderNR:" << std::endl;
    // bst.levelOrder();
    // bst.print();
    // std::vector<int> v1 = {1, 2, 5, 56, 100};
    // std::vector<int> v2 = {100, 5};
    // Solution().intersection(v1, v2);

    //remove运行例子
    BST<int> bst1;
    int n = 100;
    srand(time(0));
    for (int i = 0; i < n; ++i)
    {
        bst1.add(rand() % n); //随机数加入bst中
    }

    int *order = new int[n];    //声明了一个新数组
    for (int j = 0; j < n; j++) //给该数组赋值
    {
        order[j] = j;
    }
    shuffle(order, n); //打断该数组的数据
    std::cout << "Size=" << bst1.getsize() << std::endl;
    for (int k = 0; k < n; k++)
    {
        if (bst1.contains(order[k]))
        {
            bst1.remove(order[k]);
            std::cout << "After remove " << order[k] << ", size=" << bst1.getsize() << std::endl;
        }
    }
    std::cout << "done";
    return 0;
}