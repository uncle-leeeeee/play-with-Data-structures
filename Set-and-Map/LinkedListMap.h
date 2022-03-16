#include <iostream>
#include <cassert>
#include "Map.h"

#ifndef LINKEDLISTMAP_H
#define LINKEDLISTMAP_H

template <typename Key, typename Value>
class MapNode
{
public:
    Key key;
    Value value;
    MapNode<Key, Value> *next;
    MapNode(Key key, Value value, MapNode<Key, Value> *next) : key(key), value(value), next(next) {}
    MapNode() : key(), value(), next(nullptr) {}
};

template <typename Key, typename Value>
class LinkedListMap : Map<Key, Value> //继承Map类别
{
private:
    MapNode<Key, Value> *dummyHead;
    int size;
    MapNode<Key, Value> *getNode(Key key)
    {
        // assert(contains(key)); //如果找不到则返回空指针，无需判断是否contain
        MapNode<Key, Value> *cur = dummyHead->next;
        while (cur != nullptr)
        {
            if (cur->key == key)
            {
                return cur;
            }
            cur = cur->next;
        }
        return nullptr;
    }

public:
    LinkedListMap()
    {
        dummyHead = new MapNode<Key, Value>();
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool contains(Key key)
    {
        return getNode(key) != nullptr;
    }

    Value get(Key key)
    {
        assert(contains(key));
        MapNode<Key, Value> *node = getNode(key);
        return node->value;
    }

    void add(Key key, Value value)
    {
        MapNode<Key, Value> *node = getNode(key);
        if (node == nullptr)
        {
            dummyHead->next = new MapNode<Key, Value>(key, value, dummyHead->next);
            size++; //维护linkedlistmap元素数量
        }
        else
        {
            node->value = value; //如果key已经存在，则把key所对应的value进行更改
        }
    }

    void set(Key key, Value newvalue)
    {
        MapNode<Key, Value> *node = getNode(key);
        if (node == nullptr)
        {
            add(key, newvalue);
        }
        else
        {
            node->value = newvalue;
        }
    }

    Value remove(Key key)
    {
        assert(contains(key));                //先判断是否存在该元素
        MapNode<Key, Value> *pre = dummyHead; //因为要删除元素，要先定位到其前一位元素位置
        while (pre->next != nullptr)
        {
            if (pre->next->key == key)
            {
                break;
            }
            pre = pre->next;
        }
        if (pre->next != nullptr) //如果目标key后面还有非空元素
        {
            MapNode<Key, Value> *delNode = pre->next;
            pre->next = delNode->next;
            delNode->next = nullptr;
            size--;
            return delNode->value;
        }
        else
        { //如果是移除后一个节点
            return pre->value;
        }
    }
};

#endif