#include <iostream>
#include <string>
#include <vector>
#include "BSTSET.h"
#include "Solution.h"

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
    std::vector<int> v1 = {1, 2, 5, 56, 100};
    std::vector<int> v2 = {100, 5};
    Solution().intersection(v1, v2);

    return 0;
}