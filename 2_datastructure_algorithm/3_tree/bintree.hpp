#pragma once
#include <iostream>
#include <queue>

using namespace std;

#define _RECURSIVE_ 1

#define BinNodePtr(T) BinNode<T> *

template <typename T>
struct BinNode
{
    T _data;
    BinNodePtr(T) _parent;
    BinNodePtr(T) _lc;
    BinNodePtr(T) _rc;
    int height;

    //构造函数
    BinNode(T &data = 0)
        : _data(data)
    {
        _rc = _lc = nullptr;
        height = 0;
        _parent = nullptr;
    }

    //插入节点
    BinNodePtr(T) insertAsLC(T &data)
    {
        if (this->_lc != nullptr)
        {
            cout << "lc has existed!" << endl;
            return this->_lc;
        }
        BinNodePtr(T) ret = nullptr;
        ret = new BinNode<T>(data);
        ret->_parent = this;
        ret->height = this->height + 1;
        this->_lc = ret;
        return ret;
    }
    BinNodePtr(T) insertAsRC(T &data)
    {
        if (this->_rc != nullptr)
        {
            cout << "lc has existed!" << endl;
            return this->_rc;
        }
        BinNodePtr(T) ret = nullptr;
        ret = new BinNode<T>(data);
        ret->_parent = this;
        ret->height = this->height + 1;
        this->_rc = ret;
        return ret;
    }
    //重载比较
    bool operator<(const BinNode<T> &another) { return this->_data < another._data; }
    bool operator==(const BinNode<T> &another) { return this->_data == another._data; }
    //遍历操作
    //*子树先序遍历
    template <typename VST>
    void travPre(VST &visit)
    {
#if _RECURSIVE_
        //采用递归方式
        visit(this->_data);
        if (this->_lc)
            this->_lc->travPre(visit);
        if (this->_rc)
            this->_rc->travPre(visit);
#endif
    }
    //*子树中序遍历
    template <typename VST>
    void travIn(const VST &visit)
    {
#if _RECURSIVE_
        //采用递归方式
        if (this->_lc)
            this->_lc->travIn(visit);
        visit(this->_data);
        if (this->_rc)
            this->_rc->travIn(visit);
#endif
    }
    //*子树后序遍历
    template <typename VST>
    void travPost(VST &visit)
    {
#if _RECURSIVE_
        //采用递归方式
        if (this->_lc)
            this->_lc->travPost(visit);
        if (this->_rc)
            this->_rc->travPost(visit);
        visit(this->_data);
#endif
    }
    //*子树局次遍历
    template <typename VST>
    void travLevel(VST &visit)
    {
        queue<BinNodePtr(T)> myquene;
        myquene.push(this);
        while (!myquene.empty())
        {
            BinNodePtr(T) now = myquene.front();
            if (now->_lc)
                myquene.push(now->_lc);
            if (now->_rc)
                myquene.push(now->_rc);
            visit(now->_data);
            myquene.pop();
        }
    }

    void tranverseTree()
    {
        BinNodePtr(T) tmp = this->_lc;
        this->_lc = this->_rc;
        this->_rc = tmp;
        if (this->_lc)
            this->_lc->tranverseTree();
        if (this->_rc)
            this->_rc->tranverseTree();
    }

    void change2list(BinNodePtr(T) &parent = nullptr, BinNodePtr(T) &ret = nullptr)
    {
        BinNodePtr(T) lc = this->_lc;
        BinNodePtr(T) rc = this->_rc;
        if (lc)
            lc->change2list(parent, ret);

        if (parent == nullptr)
            ret = this;
        this->_parent = parent;
        if (this->_parent)
            this->_parent->_rc = this;
        parent = this;

        if (rc)
            rc->change2list(parent, ret);
    }
};

template <typename T>
class BinTree
{
protected:
    int updateHeight(BinNodePtr(T) x) { return x->height = 1 + max(x->_lc->height, x->_rc->height); };
    void updateHeightAbove(BinNodePtr(T) x)
    {
        while (x)
        {
            updateHeight(x);
            x = x->_parent;
        }
    };

public:
    BinNodePtr(T) _root;
    int _size;

    BinTree() : _size(0), _root(nullptr) {}
    BinTree(T *array, int n)
    {
        _root = new BinNode<T>(array[0]);
        queue<BinNodePtr(T)> myqueue;
        myqueue.push(_root);
        for (int i = 1; i < n;)
        {
            BinNodePtr(T) now = myqueue.front();
            now->insertAsLC(array[i++]);
            myqueue.push(now->_lc);
            if (i < n)
            {
                now->insertAsRC(array[i++]);
                myqueue.push(now->_rc);
            }
            myqueue.pop();
        }
        _size = n;
    }

    BinNodePtr(T) insertAsRoot(const T &data);
    BinNodePtr(T) insertAsLC(BinNodePtr(T) x, const T &data) { return x && x->insertAsLC(data); }
    BinNodePtr(T) insertAsRC(BinNodePtr(T) x, const T &data) { return x && x->insertAsRC(data); }

    struct print
    {
        void operator()(T &data) const { cout << data << ' '; }
    };

    //遍历
    template <typename VST>
    void travPre(const VST &visit)
    {
        if (_root)
            _root->travPre(visit);
        cout << endl;
    }
    template <typename VST>
    void travIn(const VST &visit)
    {
        if (_root)
            _root->travIn(visit);
        cout << endl;
    }
    template <typename VST>
    void travPost(const VST &visit)
    {
        if (_root)
            _root->travPost(visit);
        cout << endl;
    }
    template <typename VST>
    void travLevel(const VST &visit)
    {
        if (_root)
            _root->travLevel(visit);
        cout << endl;
    }
    //*1. 反转二叉查找树
    void tranverseTree()
    {
        if (_root)
            _root->tranverseTree();
    }

    //*3. 把二元查找树转变成排序的双向链表
    BinNodePtr(T) change2list()
    {
        BinNodePtr(T) ret = nullptr;
        if (_root)
        {
            BinNodePtr(T) now = nullptr;
            _root->change2list(now, ret);
        }
        return ret;
    }
};
