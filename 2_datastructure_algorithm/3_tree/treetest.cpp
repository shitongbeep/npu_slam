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
    //*4. 在二叉树中找出和为某一值的所有路径
    mybintree1.findSum(29);
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
    //*4. 在二叉树中找出和为某一值的所有路径
    BinTree<int> mybintree2;
    mybintree2.insertAsRoot(10);
    mybintree2.insertAsRC(mybintree2._root, 12);
    BinNodePtr(int) now = mybintree2.insertAsLC(mybintree2._root, 5);
    mybintree2.insertAsLC(now, 4);
    mybintree2.insertAsRC(now, 7);
    mybintree2.travLevel(print<int>());
    mybintree2.findSum(22);
}