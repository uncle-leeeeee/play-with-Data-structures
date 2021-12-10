#include <iostream>
#include <string>
#include <vector>
#include "BST.h"

template <class T>
class BSTSET
{
private: //私有成员一个二叉搜索树
    BST<T> bst;

public:
    int getsize()
    {
        return bst.getsize();
    }

    bool isEmpty()
    {
        return bst.isEmpty();
    }

    void add(T e)
    {
         bst.add(e);
    }

    bool contains(T e)
    {
        return bst.contains(e);
    }

    void remove(T e)
    {
        return bst.remove(e);
    }

    int uniqueMorseRepresentations(std::vector<std::string> &words)
    {
        std::vector<std::string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
                                          ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
                                          ".--", "-..-", "-.--", "--.."};
        BST<std::string> bst;
        for (const std::string &word : words)
        {
            std::cout << '"' << word << '"' << "->";
            std::string code = "";
            for (char c : word)
            {
                code += morse[c - 'a'];
            }
            std::cout << '"' << code << '"' << std::endl;
            bst.add(code);
        }
        return bst.getsize();
    }
};