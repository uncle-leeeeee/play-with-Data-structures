#include <iostream>
#include "BSTSet.h"
#include "FileOperation.h"

int main()
{
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

    return 0;
}