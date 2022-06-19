#include <iostream>
#include <algorithm>

using namespace std;

#define listnodePtr(T) listnode<T> *
template <typename T>
struct listnode
{
    //链表节点
    listnodePtr(T) pre;
    listnodePtr(T) succ;
    T _data;

    //默认构造（主要用这个）
    listnode(T data = 0, listnodePtr(T) p = nullptr, listnodePtr(T) s = nullptr) : _data(data), pre(p), succ(s)
    {
        if (pre != nullptr)
            pre->succ = this;
        if (succ != nullptr)
            succ->pre = this;
    }
    //插入节点（其实用不太到）
    listnodePtr(T) addAfter(T data = 0)
    {
        listnodePtr(T) ret = nullptr;
        ret = new listnode(data, this, this->succ);
        return ret;
    }
    listnodePtr(T) addBefore(T data = 0)
    {
        listnodePtr(T) ret = nullptr;
        ret = listnode(data, this->pre, this);
        return ret;
    }
};

template <typename T>
struct linkedList
{
    listnodePtr(T) header;
    listnodePtr(T) tailer;
    int _size;
    bool _loop;

    //默认构造
    linkedList(bool loop = false) : _loop(loop)
    {
        header = new listnode<T>(0);
        if (!loop)
            tailer = new listnode<T>(0, header);
        else
            tailer = header;
    }
    //数组构造
    linkedList(T *array, int n, bool loop = false) : _loop(loop)
    {
        header = new listnode<T>(0);
        if (!loop)
            tailer = new listnode<T>(0, header);
        else
            tailer = header;
        sort(array, array + n, [](T a, T b) -> bool
             { return a < b; });
            listnodePtr(T) ret = header;
        for (int i = 0; i < n; i++)
        {
            ret = new listnode<T>(array[i], ret, tailer);
        }
        _size = n;
    }
    //拷贝构造引用
    linkedList(linkedList<T> &copyfrom, bool loop = false) : _loop(loop)
    {
        header = new listnode<T>(0);
        if (!loop)
            tailer = new listnode<T>(0, header);
        else
            tailer = header;
        listnodePtr(T) ret = header;
        listnodePtr(T) ret2 = copyfrom.header;
        for (int i = 0; i < copyfrom._size; i++)
        {
            ret2 = ret2->succ;
            ret = new listnode<T>(ret2->_data, ret, tailer);
        }
        _size = copyfrom._size;
    }
    //拷贝构造指针
    linkedList(linkedList<T> *copyfrom, bool loop = false) : _loop(loop)
    {
        header = new listnode<T>(0);
        if (!loop)
            tailer = new listnode<T>(0, header);
        else
            tailer = header;
        listnodePtr(T) ret = header;
        listnodePtr(T) ret2 = copyfrom->header;
        for (int i = 0; i < copyfrom->_size; i++)
        {
            ret2 = ret2->succ;
            ret = new listnode<T>(ret2->_data, ret, tailer);
        }
        _size = copyfrom->_size;
    }
    //打印测试
    void print()
    {
        listnodePtr(T) now = header;
        for (int i = 0; i < _size; i++)
        {
            now = now->succ;
            cout << now->_data << "->";
        }
        if (!_loop)
            cout << "NULL" << endl;
        else
            cout << '|' << "--->" << now->succ->succ->_data << endl;
    }
    //*1. 合并两个有序链表
    linkedList<T> *mergeLinkedList(linkedList<T> &another)
    {
        linkedList<T> *ret = nullptr;
        if (this->_size > another._size)
        {
            ret = new linkedList(this);
            listnodePtr(T) now = ret->header->succ;
            listnodePtr(T) now2 = another.header;
            for (int i = 0; i < another._size; i++)
            {
                now = now->succ;
                now2 = now2->succ;
                new listnode<T>(now2->_data, now->pre, now);
            }
        }
        else
        {
            ret = new linkedList(another);
            listnodePtr(T) now = ret->header->succ;
            listnodePtr(T) now2 = this->header;
            for (int i = 0; i < this->_size; i++)
            {
                now = now->succ;
                now2 = now2->succ;
                new listnode<T>(now2->_data, now->pre, now);
            }
        }

        if (ret != nullptr)
        {
            ret->_size = this->_size + another._size;
            ret->print();
        }

        return ret;
    }
    //*2. 反转链表
    //?反转单链表只需要改变一个方向的指针，这里实现反转双链表
    void inverselist()
    {
        listnodePtr(T) first = header->succ;
        header->succ = tailer->pre;
        tailer->pre = first;

        header->succ->succ = header;
        tailer->pre->pre = tailer;

        first = header->succ;
        while (first != tailer)
        {
            listnodePtr(T) tmp = first->succ;
            first->succ = first->pre;
            first->pre = tmp;
            first = first->succ;
        }
    }
    listnodePtr(T) operator[](int r)
    {
        listnodePtr(T) now = header->succ;
        while (r--)
        {
            now = now->succ;
        }
        return now;
    }

    //*3. 查找链表中倒数第k个结点
    listnodePtr(T) backwardsK(int k)
    {
        return this->operator[](_size - k);
    }
};

int main()
{
    int test1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int test2[] = {1, 2, 3, 4, 5, 6};
    //*链表
    linkedList<int> mylist1(test1, sizeof(test1) / sizeof(int));
    linkedList<int> mylist2(test2, sizeof(test2) / sizeof(int));
    mylist1.print();
    mylist2.print();
    //*1. 合并两个有序链表
    mylist2.mergeLinkedList(mylist1);
    //*2. 反转链表
    mylist1.inverselist();
    mylist1.print();
    //*3. 查找链表中倒数第k个结点
    int test3[] = {5, 6, 2, 10, 3};
    linkedList<int> mylist3(test3, sizeof(test3) / sizeof(int));
    mylist3.print();
    cout << mylist3.backwardsK(2)->_data << endl;
    //*4. 双向循环链表的队列
    int test4[] = {3, 10, 54, 23, 50, 8, 2, 40};
    linkedList<int> mylist4(test4, sizeof(test4) / sizeof(int), true);
    mylist4.print();
}