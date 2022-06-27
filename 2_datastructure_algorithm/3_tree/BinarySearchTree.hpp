#pragma once
#include "bintree.hpp"

template <typename T>
class BinarySearchTree : public BinTree<T>
{
protected:
    BinNodePtr(T) _hot;

public:
    static BinNodePtr(T) & searchAt(const BinNodePtr(T) & v, const T &data, BinNodePtr(T) & hot)
    {
        if (v->_data == data || !v)
            return v;
        hot = v;
        searchAt((data < v->_data) ? v->_lc : v->_rc, data, hot);
    }
    virtual BinNodePtr(T) & search(const T &data)
    {
        //* 时间复杂度 最好O(1) 最差O(n) 与树的结构有关
        if (_root)
            return searchAt(_root, data, _hot = nullptr);
        return nullptr;
    };
    //*节点插入
    virtual BinNodePtr(T) insert(const T &data)
    {
        BinNodePtr(T) now = search(data);
        if (now)
            return now;
        now = new BinNode<T>(data);
        now->_parent = _hot;
        updateHeightAbove(_hot);
        return now;
    };
    //*节点删除
    virtual bool remove(const T &data)
    {
        BinNodePtr(T) &now = search(data);
        if (!now)
            return false;
        BinNodePtr(T) x = now;
        if (!now->_rc)
        {
            //如果没有右子树，接入左子树
            now = now->_lc;
            if (now)
                now->_parent = _hot;
        }
        else if (!now->_lc)
        {
            //如果没有左子树接入右子树
            now = now->_rc;
            if (now)
                now->_parent = _hot;
        }
        else
        {
            //两边都有的话，寻找直接后继交换位置
            BinNodePtr(T) succ & = now->succ();
            T tmp = now->_data;
            now->_data = succ->_data;
            succ->_data = tmp;

            //真正删除的是直接后继
            x = succ;
            _hot = x->_parent;
            succ = succ->_rc;
            if (succ)
                succ->_parent = _hot;
        }
        delete x;
    };
};
