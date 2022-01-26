#ifndef FILEOPS_H
#define FILEOPS_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

using namespace std;
//定义一个读取文件的命名空间，里面定义了读取txt文件，获取文本单词的方法；其实也可以封装成一个类，但从属性角度来说有点奇怪
namespace FileOps
{
    //判断一个字符是否为字母
    bool isCharacter(char c)
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    //获取字符串中第一个为字母的下标
    int firstCharacterIndex(const string &s, int start)
    {
        for (int i = start; i < int(s.length()); i++)
        {
            if (isCharacter(s[i])) //若为字母则返回当前下标位置
            {
                return i;
            }
        }
        return s.length(); //否则返回该字符串的长度
    }

    //把单词全部转化为小写单词
    string lowerS(const string &s)
    {
        string ret = "";
        for (int i = 0; i < int(s.length()); i++)
        { //要先判断该字符是否为字母
            assert(isCharacter(s[i]));
            ret += tolower(s[i]); //转化为小写
        }
        return ret;
    }

    //读取文件中的字符串，传入引用的string word，来存入遍历得到的每个单词
    bool ReadFile(const string &filename, vector<string> &words)
    {
        string line;
        string contents = "";
        ifstream file(filename); //创建一个文件输入流
        if (file.is_open())
        { //先判断是否能正常打开该文件，并将文本内容读取进入contents字符串中
            while (getline(file, line))
            {
                contents += (line + "\n"); //获取每行内容
            }
        }
        else
        {
            cout << "can't open " << filename << "please check out the file path!!" << endl;
            return false;
        }

        int start = firstCharacterIndex(contents, 0); //获取文本内容中第一个为字符的下标
        int i;
        for (i = start + 1; i <= int(contents.length());)
        {
            if (i == int(contents.length()) || !isCharacter(contents[i]))
            {                                                               //如果已经遍历到文本内容的最后一个字符的后一位，或者当前的字符不是字母
                words.push_back(lowerS(contents.substr(start, i - start))); //从start下标开始，往后取i-start个字符作为单词，并转成小写，放入words当中
                start = firstCharacterIndex(contents, i);                   //更新start的位置
                i = start + 1;                                              //更新i的位置
            }
            else
            { //否则继续往后读取字符
                i += 1;
            }
        }
        return true;
    }

}

#endif