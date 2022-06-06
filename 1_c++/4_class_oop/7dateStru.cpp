#include <iostream>
#include <queue>

using namespace std;

//*7.1 查找链表中倒数第k个结点
struct ListNode
{
    int m_nKey;
    ListNode *m_pNext;
    ListNode() : m_pNext(nullptr){};
    ListNode(int m, ListNode *next) : m_nKey(m), m_pNext(next){};
};

struct MyList
{
    ListNode *header;
    ListNode *tailer;
    int size_;

    MyList(){};
    MyList(int *input, int n)
    {
        size_ = 0;

        header = new ListNode;
        tailer = new ListNode;

        ListNode *first = header;

        for (int i = 0; i < n; i++)
        {
            first->m_pNext = new ListNode(input[i], tailer);
            size_++;
            first = first->m_pNext;
        }
    }

    int &operator[](int r)
    {
        if (r >= size_ || r < 0)
            return tailer->m_nKey;

        ListNode *first = header->m_pNext;
        while (r--)
            first = first->m_pNext;

        return first->m_nKey;
    }

    int &tailK(int k)
    {
        return this->operator[](size_ - k);
    }
};

//*7.2 在排序数组中查找和为给定值的两个数字
void findSubNum(int *input, int n, int num)
{
    bool exist = false;
    for (int i = 0, j = n - 1; i < j;)
    {
        if (input[i] + input[j] == num)
        {
            exist = true;
            cout << input[i] << " + " << input[j] << " = " << num << endl;
            i++;
            j--;
        }
        else if (input[i] + input[j] > num)
            j--;
        else if (input[i] + input[j] < num)
            i++;
    }
    if (exist == false)
        cout << "no this" << endl;
}

//*7.3 从上往下遍历二叉树
//?用队列实现
#define BTnodePtr BTnode *
struct BTnode
{
    BTnodePtr left;
    BTnodePtr right;
    int data;
    BTnode(int d = 0, BTnodePtr l = nullptr, BTnodePtr r = nullptr) : data(d), left(l), right(r){};
};

struct BTree
{
    BTnodePtr master;
    int size_;
    int level_;

    BTree(int *input, int n)
    {
        size_ = n;
        level_ = 1;
        master = new BTnode(input[0]);
        queue<BTnodePtr> q;
        q.push(master);
        for (int i = 1; i < n;)
        {
            BTnodePtr now = q.front();
            now->left = new BTnode(input[i++]);
            now->right = new BTnode(input[i++]);
            q.push(now->left);
            q.push(now->right);
            q.pop();
        }
    }

    void print()
    {
        queue<BTnodePtr> q;
        q.push(master);
        while (!q.empty())
        {
            BTnodePtr now = q.front();
            cout << now->data << ' ';
            if (now->left)
                q.push(now->left);
            if (now->right)
                q.push(now->right);
            q.pop();
        }
        cout << endl;
    }
    void printtree()
    {
        int i = 0, level = 1;
        queue<BTnodePtr> q;
        q.push(master);
        while (!q.empty())
        {
            i++;
            BTnodePtr now = q.front();
            cout << now->data << ' ';
            if (i % level == 0)
            {
                cout << endl;
                level *= 2;
                i = 0;
            }
            if (now->left)
                q.push(now->left);
            if (now->right)
                q.push(now->right);
            q.pop();
        }
        cout << endl;
    }
};

//*7.4 设计包含min函数的栈
struct stack
{
    int min_;
    int size_;
    vector<int> data;

    stack(int *input, int n) : size_(n)
    {
        min_ = input[0];
        for (int i = 0; i < n; i++)
        {
            data.push_back(input[i]);
            if (min_ > input[i])
                min_ = input[i];
        }
    }

    void push(int d)
    {
        data.push_back(d);
        size_++;
        if (min_ > d)
            ;
        min_ = d;
    }

    int pop()
    {
        int ret = data[size_ - 1];
        data.pop_back();
        return ret;
    }

    int min()
    {
        return min_;
    }
};

int main()
{
    //*7.1 查找链表中倒数第k个结点
    int test1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    MyList mylist(test1, sizeof(test1) / sizeof(int));
    cout << mylist.tailK(3) << endl;
    //*7.2 在排序数组中查找和为给定值的两个数字
    int test2[] = {0, 1, 2, 4, 7, 11, 15};
    findSubNum(test2, sizeof(test2) / sizeof(int), 15);
    //*7.3 从上往下遍历二叉树
    int test3[] = {8, 6, 10, 5, 7, 9, 11};
    BTree mytree(test3, sizeof(test3) / sizeof(int));
    mytree.print();
    mytree.printtree();
    //*7.4 设计包含min函数的栈
    stack mystack(test3, sizeof(test3) / sizeof(int));
    cout << mystack.min() << endl;
}
