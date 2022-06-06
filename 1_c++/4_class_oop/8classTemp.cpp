#include <iostream>

using namespace std;

//*8.1 函数模版
template <typename T>
void computeMaxMinAvg(T *input, int n)
{
    T max_ = input[0], min_ = input[0], avg = 0;
    for (int i = 0; i < n; i++)
    {
        if (input[i] > max_)
            max_ = input[i];
        if (input[i] < min_)
            min_ = input[i];
        avg += input[i] / n;
    }
    cout << "max:" << max_ << endl;
    cout << "min:" << min_ << endl;
    cout << "avg:" << avg << endl;
}

//*8.2 数据交换函数模版
template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

//*8.3 类模板
template <typename T>
class sortArray
{
private:
    T *array;
    int n;

public:
    sortArray() : array(nullptr), n(0){};
    sortArray(T *a, int num) : array(a), n(num){};
    void sort()
    {
        int high = n;
        while (--high)
        {
            //!从高到低遍历，保证最高位是最大
            for (int low = 1; low <= high; low++)
            {
                //!依次把最大值送到最高位
                //?稳定排序，不改变相同值的次序
                if (array[low - 1] > array[low])
                {
                    float tmp = array[low - 1];
                    array[low - 1] = array[low];
                    array[low] = tmp;
                }
            }
        }
    }
    void print()
    {
        for (int i = 0; i < n; i++)
            cout << array[i] << ' ';
        cout << endl;
    }
};

//*8.4 类模版的链表
#define ListNodePtr(T) ListNode<T> *
template <typename T>
struct ListNode
{
    T m_nKey;
    ListNodePtr(T) m_pNext;
    ListNode() : m_pNext(nullptr){};
    ListNode(T m, ListNodePtr(T) next) : m_nKey(m), m_pNext(next){};
};

template <typename T>
struct MyList
{
    ListNodePtr(T) header;
    ListNodePtr(T) tailer;
    int size_;

    MyList(){};
    MyList(T *input, int n)
    {
        size_ = 0;

        header = new ListNode<T>;
        tailer = new ListNode<T>;

        ListNodePtr(T) first = header;

        for (int i = 0; i < n; i++)
        {
            first->m_pNext = new ListNode<T>(input[i], tailer);
            size_++;
            first = first->m_pNext;
        }
    }

    ListNodePtr(T) operator[](int r)
    {
        if (r >= size_ || r < 0)
            return tailer;

        ListNodePtr(T) first = header->m_pNext;
        while (r--)
            first = first->m_pNext;

        return first;
    }

    bool addat(int r, T t)
    {
        if (r >= size_ || r < 0)
            return false;
        ListNodePtr(T) now = this->operator[](r + 1);
        this->operator[](r)->m_pNext = new ListNode<T>(t, now);
        return true;
    }

    bool deleteat(int r)
    {
        if (r >= size_ || r < 0)
            return false;
        ListNodePtr(T) now = this->operator[](r + 1);
        delete this->operator[](r);
        this->operator[](r - 1)->m_pNext = now;
        return true;
    }

    void print()
    {
        ListNodePtr(T) first = header->m_pNext;
        while (first != tailer)
        {
            cout << first->m_nKey << ' ';
            first = first->m_pNext;
        }
        cout << endl;
    }
};

//*8.5 类与继承
class Vehicle
{
protected:
    int wheels;
    double weight;

public:
    Vehicle(int wh = 0, double we = 0) : wheels(wh), weight(we){};
    void print()
    {
        cout << "wheels:" << wheels << "; weight:" << weight << endl;
    }
};

class Car : private Vehicle
{
private:
    int passager_load;

public:
    Car(int wh = 0, double we = 0, int pa = 0) : Vehicle(wh, we), passager_load(pa){};
    void print()
    {
        Vehicle::print();
        cout << "passager_load:" << passager_load << endl;
    }
};

class Truck : private Vehicle
{
private:
    double payload;

public:
    Truck(int wh = 0, double we = 0, double pa = 0) : Vehicle(wh, we), payload(pa){};
    void print()
    {
        Vehicle::print();
        cout << "payload:" << payload << endl;
    }
};

int main()
{
    //*8.3 类模板
    int array1[5] = {3, 6, 2, 1, 4};
    double array2[5] = {3.1, 1.2, 4.5, 1.1, 0.2};
    sortArray<int> test1(array1, sizeof(array1) / sizeof(int));
    sortArray<double> test2(array2, sizeof(array2) / sizeof(double));
    test1.sort();
    test2.sort();
    test1.print();
    test2.print();
    //*8.4 类模版的链表
    MyList<double> mylist(array2, sizeof(array2) / sizeof(double));
    mylist.print();
    mylist.deleteat(2);
    mylist.print();
    mylist.addat(3, 6.7);
    mylist.print();
    //*8.5 类与继承
    Car mycar(1, 2, 3);
    mycar.print();
    Truck mytrunk(1.1,2.2,3.3);
    mytrunk.print();
}