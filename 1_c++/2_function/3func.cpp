#include <iostream>
#include <random>
#include <time.h>
#include <math.h>

using namespace std;
//*3.1 整数的各位数字求和
int nSum(int a)
{
    int ret = 0;
    a = abs(a);
    while (a / 10)
    {
        ret += a % 10;
        a /= 10;
    }
    ret += a;
    return ret;
}
//*3.2 点数统计
void recordFre()
{
    int fre[6]{0};
    default_random_engine e;
    e.seed(time(nullptr));
    for (int i = 0; i < 10000; i++)
    {
        int radm = e();
        fre[abs(radm) % 6] += 1;
    }
    for (int i = 0; i < 6; i++)
    {
        cout << i + 1 << ":" << fre[i] << ' ';
    }
    cout << endl;
}
//*3.3 素数
bool primeNumber(int a)
{
    a = abs(a);
    bool ret = true;
    for (int i = 2; i < sqrt(a); i++)
    {
        if (a % i == 0)
        {
            ret = false;
            break;
        }
    }
    return ret;
}
//*3.4 求自然指数e的值
void cul_e(int pre)
{
    pre = abs(pre);
    double e = 1;
    double pres = exp10(-1 * pre);
    double i = 1, j = 1;
    while (1 / i > pres)
    {
        j++;
        e += 1 / i;
        i *= j;
    }
    e += 1 / i;
    cout << e << endl;
}
//*3.5 求圆周率
void cul_pi(int pre)
{
    double pres = exp10(-1 * pre);
    double pi = 0;
    double i = 1;
    while (4 * 1 / i > pres)
    {
        pi += 4 * 1 / i;
        i = -1 * (i + 2);
    }
    cout << "pi:" << pi << endl;
}
//*3.6 数字的统计
void cul_num(double *input, int n)
{
    int pos = 0, neg = 0, zero = 0;
    for (int i = 0; i < n; i++)
    {
        if (input[i] == 0)
            zero++;
        else if (input[i] > 0)
            pos++;
        else
            neg++;
    }
}
//*3.7 奇数之和、偶数之和
void cul_3_7()
{
    int i;
    int odd = 0, even = 0;
    while (cin >> i)
    {
        if (i == 0)
            break;
        if (i % 2)
            odd++;
        else
            even++;
    }
    cout << "odd sum:" << odd << ";even sum:" << even << endl;
}
//*3.8 水仙花数
void waterFlower()
{
    for (int i = 100; i < 999; i++)
    {
        int n = i;
        if (pow(n % 10, 3) + pow(n % 100, 3) + pow(n / 100, 3) == n)
            cout << n << ' ';
    }
    cout << endl;
}
//*3.9 变量值交换
void change(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
//*3.10 欧式距离计算
double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
//*3.11 矩阵乘积
void multMatrix(double **a, double **b, double **output, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                output[i][j] += a[i][k] * b[k][j];
}
//*3.12 体育运动成绩
double score(double *input, int n)
{
    int max = 0, min = 100, k;
    double ret = -2;
    for (int i = 0; i < n; i++)
    {
        if (input[i] < 0 || input[i] > 100)
            continue;
        if (input[i] > max)
            max = input[i];
        if (input[i] < min)
            min = input[i];
        ret += input[i];
        k++;
    }
    ret = ret - max - min;
    ret /= k;
    return ret;
}
//*3.13 选数字
void select_num()
{
    int candi[52];
    default_random_engine e;
    e.seed(time(nullptr));
    for (int i = 0; i < 52; i++)
        candi[i] = e();
    for (int i = 0; i < 13; i++)
    {
        int sel = e();
        sel %= 52;
        cout << candi[sel] << ' ';
    }
    cout << endl;
}
//*3.14 阶乘计算
int cul_factorial(int n)
{
    int ret = 1;
    for (int i = 1; i <= n; i++)
        ret *= i;
    return ret;
}
//*3.15 汉诺塔
void hanoi()
{
    int l1 = 64, l2 = 0, l3 = 0;
    int n = 1;
    while (n <= 64 || l2 * l3)
    {
        if (!l2)
        {
            cout << "l1 -> l2 : circle " << n << endl;
            n++;
            l1--;
            l2 = n;
        }
        else if (!l3)
        {
            cout << "l1 -> l3 : circle " << n << endl;
            n++;
            l1--;
            l3 = n;
        }
        else
        {
            if (l2 < l3)
            {
                cout << "l2 -> l3 : circle " << 1 << '-' << l2 << endl;
                l2 = 0;
            }
            else
            {
                cout << "l3 -> l2 : circle " << 1 << '-' << l3 << endl;
                l3 = 0;
            }
        }
    }
}

//? test
int main()
{
    cout << "3.1" << endl;
    cout << nSum(12345) << endl;
    cout << "3.1" << endl;
    recordFre();
    cout << "3.3" << endl;
    for (int i = 0; i < 1000; i++)
    {
        if (primeNumber(i) == true)
            cout << i << ' ';
    }
    cout << endl;
    cout << "3.4" << endl;
    cul_e(4);
    cout << "3.5" << endl;
    cout << "3.6" << endl;
    cout << "3.7" << endl;
    cout << "3.8" << endl;
    cout << "3.9" << endl;
    cout << "3.10" << endl;
    cout << "3.11" << endl;
    cout << "3.12" << endl;
    cout << "3.13" << endl;
    cout << "3.14" << endl;
    cout << "3.15" << endl;
    hanoi();
}