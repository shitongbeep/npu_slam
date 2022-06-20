#include "bintree.hpp"

template <typename T>
class print
{
public:
    void operator()(T &data) const { cout << data << ' '; }
};

int main()
{
    //* test a tree
    int test1[] = {8, 6, 10, 5, 7, 9, 11};
    BinTree<int> mybintree1(test1, sizeof(test1) / sizeof(int));
    cout << "travel Intermedia: ";
    mybintree1.travIn(print<int>());
    cout << "travel Pre: ";
    mybintree1.travPre(print<int>());
    cout << "travel Post: ";
    mybintree1.travPost(print<int>());
    //*2. 从上往下遍历二元树
    cout << "travel Level: ";
    mybintree1.travLevel(print<int>());
    //*1. 反转二叉查找树
    mybintree1.tranverseTree();
    cout << "afert tranverse ... travel Level: ";
    mybintree1.travLevel(print<int>());
    //*3. 把二元查找树转变成排序的双向链表
    BinNodePtr(int) c = mybintree1.change2list();
    cout << c->_data;
    c = c->_rc;
    while (c != nullptr)
    {
        cout << " = " << c->_data;
        c = c->_rc;
    }
    cout << endl;
}