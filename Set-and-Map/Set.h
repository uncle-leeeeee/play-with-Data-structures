#ifndef SET_H
#define SET_H

template <typename T>
class Set
{ //声明纯虚函数，需要在子类中定义
    virtual void add(T e) = 0;
    virtual void remove(T e) = 0;
    virtual bool contains(T e) = 0;
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;

public:
    virtual ~Set()
    {
        std::cout << "Set::~Set()" << std::endl;
    }
};

#endif