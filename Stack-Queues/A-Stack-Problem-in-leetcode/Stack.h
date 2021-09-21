#ifndef STACK_H
#define STACK_H
//定义一个Stack类，并在里面定义虚函数
template <typename T>
class Stack
{
public:
    virtual int getSize() = 0;//返回个数
    virtual bool isEmpty() = 0;//
    virtual void push(T e) = 0;
    virtual T pop() = 0;
    virtual T peek() = 0;
};

#endif
