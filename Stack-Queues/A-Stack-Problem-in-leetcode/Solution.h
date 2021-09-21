#include <stack>
#include <string>

class Solution
{
public:
    bool isVaild(std::string s)
    {
        std::stack<char> *s1 = new std::stack<char>();
        //遍历字符串里面的每个元素，并判断是否入栈
        for (int i = 0; i < int(s.size()); i++)
        {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{')
            {
                s1->push(c);
            }
            else //如果是右括号则判断当前栈是否为空
            {
                if (s1->empty()) //如果当前栈为空
                {
                    return false; //该字符串的括号不匹配
                }
                char t = s1->top(); //获取栈顶元素
                //判断弹出的括号与输入的是否匹配
                if (t == '(' && c == ')')
                {
                    s1->pop(); //弹出栈顶元素
                }
                else if (t == '[' && c == ']')
                {
                    s1->pop();
                }
                else if (t == '{' && c == '}')
                {
                    s1->pop();
                }
                else
                {
                    return false;
                }
            }
        }
        //还需要判断对字符串操作完后，当前栈是否为空
        return s1->empty();
    }
};