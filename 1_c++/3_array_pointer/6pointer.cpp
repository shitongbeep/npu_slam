#include <iostream>

using namespace std;

//*6.1 使用指针改变数组的元素顺序
void changeArrayPosi(int *array, int n, int m)
{
    m = m % n;
    int *marray = new int[m];
    for (int i = n - m, j = 0; i < n; i++)
    {
        marray[j++] = array[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (i < m)
            array[i] = marray[i];
        else
            array[i] = array[i - m];
    }
    delete[] marray;
}

//*6.2 字符串拷贝
char *copyString(char *input, int n)
{
    char *output = new char[n];
    for (int i = 0; i < n; i++)
    {
        *(output + i) = *input++;
    }
    return output;
}

//*6.3 求字符串长度
int getStringLength(char *input)
{
    int ret = 0;
    while (*input++)
        ret++;
    return ret;
}

//*6.4 矩阵转置
#define N 4
void inverseMatrix(int (*input)[N], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            int tmp = *(*(input + i) + j);
            *(*(input + i) + j) = *(*(input + j) + i);
            *(*(input + j) + i) = tmp;
        }
}

//*6.5 找到矩阵的最大值
void findMaxInMatrix(int input[2][3])
{
    int max = input[0][0], row = 0, col = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
        {
            if (input[i][j] > max)
            {
                max = input[i][j];
                row = i;
                col = j;
            }
        }
    cout << "max at (" << row << ',' << col << ") is " << max << endl;
}

//*6.6 字符串统计
void countSpecialChar(char *input)
{
    int space = 0, charac = 0, number = 0;
    while (*input++)
    {
        if (*input == ' ')
            space++;
        else if (*input >= '0' && *input <= '9')
            number++;
        else if ((*input >= 'a' && *input <= 'z') || (*input >= 'A' && *input <= 'Z'))
            charac++;
    }
    cout << "number: " << number << "; char: " << charac << "; space: " << space << endl;
}

//*6.7 链表反转
#define listnodePtr(T) listnode<T> *
template <typename T>
struct listnode
{
    listnodePtr(T) pre;
    listnodePtr(T) succ;
    T data;

    listnode() { pre = nullptr, succ = nullptr; }
    listnode(T d, listnodePtr(T) p = nullptr, listnodePtr(T) s = nullptr) : data(d), pre(p), succ(s)
    {
        this->pre->succ = this;
        this->succ->pre = this;
    };
};

template <typename T>
struct list
{
    listnodePtr(T) header;
    listnodePtr(T) tailer;
    int size_;

    list()
    {
        header = new listnode<T>;
        tailer = new listnode<T>;
    };
    list(int *array, int n)
    {
        header = new listnode<T>;
        tailer = new listnode<T>;
        listnodePtr(T) insert = nullptr;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                insert = new listnode<T>(array[i], header, tailer);
            else
                insert = new listnode<T>(array[i], insert, tailer);
        }
    }
    void print()
    {
        listnodePtr(T) first = header->succ;
        while (first->succ != nullptr)
        {
            cout << first->data << ' ';
            first = first->succ;
        }
        cout << endl;
    }
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
};

int main()
{
    //*6.1 使用指针改变数组的元素顺序
    int test[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    changeArrayPosi(test, sizeof(test) / sizeof(int), 3);
    for (auto i : test)
        std::cout << i << ' ';
    std::cout << std::endl;
    //*6.2 字符串拷贝
    char test2[] = "testing!";
    cout << copyString(test2, sizeof(test2) / sizeof(char)) << endl;
    //*6.3 求字符串长度
    cout << "length: " << getStringLength(test2) << endl;
    //*6.4 矩阵转置
    int test3[N][N] = {{1, 2, 3, 3}, {4, 5, 6, 6}, {7, 8, 9, 9}, {1, 2, 3, 3}};
    inverseMatrix(test3, N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << test3[i][j] << ' ';
        }
        cout << endl;
    }
    //*6.7 链表反转
    int test4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> mylist(test4, sizeof(test4) / sizeof(int));
    mylist.print();
    mylist.inverselist();
    mylist.print();
}
