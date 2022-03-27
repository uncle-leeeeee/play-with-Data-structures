#include <iostream>
#include "BSTSet.h"
#include "LinkedListMap.h"
#include "FileOperation.h"

int main()
{
    /***
     利用二叉搜索树构建集合，并存放不重复单词
     ***/
    std::cout << "a-tale-of-two-cities.txt" << std::endl; //读取双城记文本
    vector<string> words;                                 //声明一个words数组来存放文本中的单词
    if (FileOps::ReadFile("a-tale-of-two-cities.txt", words))
    {                                                                                //如果能成功读取文本文件
        std::cout << "total words size of the txt is " << words.size() << std::endl; //输出文本中总共的单词数，包括重复的
        //新建一个BSTSET对象，利用不重复的特点，统计文本中不重复的单词数
        BSTSET<string> *bst = new BSTSET<string>();
        for (auto s : words)
        {
            bst->add(s);
        }
        std::cout << "Total different words: " << bst->getSize() << std::endl;
        delete bst; //先删除，再将其赋值为空指针
        bst = nullptr;
    }

    /***
     利用链表构建Map，存放不重复单词，word-cnt一一对应
     ***/
    std::cout << "pride-and-prejudice.txt" << std::endl;
    string filename = "pride-and-prejudice.txt";
    LinkedListMap<string, int> *m = new LinkedListMap<string, int>();
    vector<string> words_map;
    if (FileOps::ReadFile(filename, words_map))
    {
        std::cout << "Total words: " << words_map.size() << std::endl;
        for (string word : words_map)
        {
            if (m->contains(word))
            {
                m->set(word, m->get(word) + 1);
            }
            else
            {
                m->add(word, 1);
            }
        }
        std::cout << "Total different words: " << m->getSize() << std::endl;
        std::cout << "Frequency of PRIDE: " << m->get("pride") << std::endl;
        std::cout << "Frequency of PREJUDICE: " << m->get("prejudice") << std::endl;
    }
    //与二叉搜索树的存放集合set示例程序相比有所不同，map这里需要计算每个单词的频次，花的时间要更长
    return 0;
}