#include <iostream>
#include <tuple>
#include <random>
using namespace std;

//* 2 控制与循环
//* 2.1 找最大值、最小值和平均数
tuple<float, float, float> max_min_avg(float input[], int n)
{
    float max = input[0], min = max, avg = max / n;
    for (int i = 1; i < n; i++)
    {
        if (input[i] > max)
            max = input[i];
        if (input[i] < min)
            min = input[i];
        avg += input[i] / n;
    }
    tuple<float, float, float> ret = make_tuple(max, min, avg);
    return ret;
}

//*2.2 n个数排序
void bubbleSort(float input[], int n)
{
    int high = n;
    while (--high)
    {
        //!从高到低遍历，保证最高位是最大
        for (int low = 1; low <= high; low++)
        {
            //!依次把最大值送到最高位
            //?稳定排序，不改变相同值的次序
            if (input[low - 1] > input[low])
            {
                float tmp = input[low - 1];
                input[low - 1] = input[low];
                input[low] = tmp;
            }
        }
    }
}

//*2.3 符合条件的数
void conditionNum()
{
    cout << "condition number:";
    for (int i = 1; i <= 100; i++)
    {
        if (i % 5 == 2 || 1 % 9 == 0)
            cout << i << ' ';
    }
    cout << endl;
}

//*2.4 没有重复数字
void nonRepetiton()
{
    int i = 0;
    for (int j = 1; j <= 9; j++)
        for (int k = 0; k <= 9; k++)
            if (k != j)
                for (int l = 0; l <= 9; l++)
                    if (l != k && l != j)
                        i++;
    cout << "nonRepetition:" << i << endl;
}

//*2.5 鸡兔的个数
void chicken_rabbit()
{
    int c = 0, r = 0;
    for (c = 0; c <= 30; c++)
        if (2 * c + 4 * (30 - c) == 90)
        {
            r = 30 - c;
            break;
        }
    cout << "chiken:" << c << ";rabbit:" << r << endl;
}

//*2.6 猴子吃桃
void monkey()
{
    int peach = 1;
    for (int i = 1; i < 10; i++)
    {
        peach = (peach + 1) * 2;
    }
    cout << "peach: " << peach << endl;
    ;
}

//*2.7 打印图案
void rhombus()
{
    int n = 15;
    for (int i = 0; i < n; i++)
    {
        int level = i > n / 2 ? n - i - 1 : i;
        for (int j = 0; j < n; j++)
        {
            if (j >= n / 2 - level && j <= n - 1 - (n / 2 - level))
                cout << '*';
            else
                cout << ' ';
        }
        cout << endl;
    }
}

int main(int argc, char **argv)

{
    //*2.2
    cout << "2.2" << endl;
    float testInput[20];
    std::default_random_engine e;
    e.seed(10);
    int n = sizeof(testInput) / sizeof(float);
    while (n--)
    {
        testInput[n] = e();
        cout
            << testInput[n] << ' ';
    }
    cout << endl;
    bubbleSort(testInput, sizeof(testInput) / sizeof(float));
    n = sizeof(testInput) / sizeof(float);
    while (n--)
        cout
            << testInput[n] << ' ';
    cout << endl;
    //*2.3
    cout << "2.3" << endl;
    conditionNum();
    //*2.4
    cout << "2.4" << endl;
    nonRepetiton();
    //*2.5
    cout << "2.5" << endl;
    chicken_rabbit();
    //*2.6
    cout << "2.6" << endl;
    monkey();
    //*2.7
    cout << "2.7" << endl;
    rhombus();
}