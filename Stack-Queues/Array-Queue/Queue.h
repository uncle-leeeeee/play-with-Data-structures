
//构建虚函数，与继承类形成多态。
/*虚函数后面加=0，表示这个函数为纯虚函数，其没有函数体；表示该类为一个抽象类；不能具体实例化，只能由它去派生子类
在派生类中对此函数提供定义后，它才能具备函数的功能。
。*/
template <typename T>
class Queue
{
public:
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual T dequeue() = 0;
    virtual void enqueue(T e) = 0;
    virtual T getFront() = 0;
};