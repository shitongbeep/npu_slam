#include <iostream>
#include <string.h>

using namespace std;

//*5.1 字符串的排列
void recPrintArrange(const char *lastArray0, const char *selectChar0, int i, const int n)
{
    if (i == 1)
    {
        for (int j = 0; j < n - 1; j++)
            cout << lastArray0[j];
        cout << selectChar0[0] << ';' << endl;
    }
    else
    {
        char *lastArray = new char[n - i + 1];
        for (int j = 0; j < n - i; j++)
            lastArray[j] = lastArray0[j];
        char *selectChar = new char[i - 1];
        for (int j = 0; j < i; j++)
        {
            lastArray[n - i] = selectChar0[j];
            for (int k = 0, m = 0; k < i; k++)
                if (k != j)
                {
                    selectChar[m] = selectChar0[k];
                    m++;
                }
            recPrintArrange(lastArray, selectChar, i - 1, n);
        }
    }
}
void printArrange(const char *array, const int n)
{
    recPrintArrange(nullptr, array, n, n);
}

//*5.2 统计大小写字母的个数
void countBigSmall(const char *array, const int n)
{
    int small = 0, big = 0;
    for (int i = 0; i < n; i++)
        if (array[i] >= 'a' && array[i] <= 'z')
            small++;
        else if (array[i] >= 'A' && array[i] <= 'Z')
            big++;
    cout << "big:" << big << "; small:" << small << endl;
}

//*5.3 大小写转化
void bigConvertSmall(const char *array, const int n)
{
    int dist = 'A' - 'a';
    char c;
    for (int i = 0; i < n; i++)
        if (array[i] >= 'a' && array[i] <= 'z')
        {
            c = array[i] + dist;
            cout << c;
        }
        else if (array[i] >= 'A' && array[i] <= 'Z')
        {
            c = array[i] - dist;
            cout << c;
        }
    cout << endl;
}

//*5.4 字符串拷贝
void copyString(const char *input, char *output, int n)
{
    for (int i = 0; i < n; i++)
        output[i] = input[i];
}

//*5.5 字符串比较函数
bool compareString(const char *input, const char *input2, int n)
{
    for (int i = 0; i < n; i++)
        if (input[i] != input2[i])
            return false;
    return true;
}

//*5.6 字符串连接函数
char *linkString(const char *input1, const char *input2, int n1, int n2)
{
    char *ret = new char[n1 + n2];
    int m = 0;
    for (int i = 0, m = 0; i < n1; i++)
        if (input1[i] != '\n' && input1[i] != '0')
        {
            ret[m] = input1[i];
            m++;
        }
    for (int i = 0; i < n2; i++)
    {
        ret[m] = input2[i];
        m++;
    }
    return ret;
}

//*5.7 字符串长度
int lenthString(const char *input)
{
    int m = 0;
    while (input[m] != '\n' && input[m] != 0)
        m++;
    return m;
}

//*5.8 杨辉三角形
void YangHui(int n)
{
    int col = 2 * n - 1;
    int *odd = new int[col];
    int *even = new int[col];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0)
            {
                if (j == n - 1)
                {
                    even[j] = 1;
                    cout << ' ' << even[j] << ' ';
                }
                else
                {
                    even[j] = 0;
                    cout << "   ";
                }
            }
            else if (i % 2)
            {
                if (j == 0)
                    odd[j] = even[j + 1];
                else if (j == col - 1)
                    odd[j] = even[j - 1];
                else
                    odd[j] = even[j - 1] + even[j + 1];

                if (odd[j] == 0)
                    cout << "   ";
                else if (odd[j] / 100)
                    cout << odd[j];
                else if (odd[j] / 10)
                    cout << ' ' << odd[j];
                else
                    cout << ' ' << odd[j] << ' ';
            }
            else
            {
                if (j == 0)
                    even[j] = odd[j + 1];
                else if (j == col - 1)
                    even[j] = odd[j - 1];
                else
                    even[j] = odd[j - 1] + odd[j + 1];

                if (even[j] == 0)
                    cout << "   ";
                else if (even[j] / 100)
                    cout << even[j];
                else if (even[j] / 10)
                    cout << ' ' << even[j];
                else
                    cout << ' ' << even[j] << ' ';
            }
        }
        cout << endl;
    }
    delete[] odd;
    delete[] even;
}

//*5.9 九九乘法表
void NineXNine()
{
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            cout << i << " x " << j << " = ";
            int cul = i * j;
            if (cul / 10)
                cout << cul;
            else
                cout << cul << ' ';
            cout << "  ";
        }
        cout << endl;
    }
}

//*5.10 翻转句子中单词的顺序
void inverseString(char *array, int n)
{
    int m = -1;
    char *inverse = new char[n];
    for (int i = n - 1; i >= 0; i--)
    {
        if (array[i] != ' ')
        {
            m++;
            inverse[m] = array[i];
        }
        else if (m != -1)
        {
            for (int j = m; j >= 0; j--)
            {
                cout << inverse[j];
                m--;
            }
            cout << ' ';
        }
        else
            cout << ' ';
    }
    if (m != -1)
    {
        for (int j = m; j >= 0; j--)
        {
            cout << inverse[j];
            m--;
        }
        cout << ' ';
    }
    cout << endl;
    delete[] inverse;
}

//*5.11 删除字符串中的字符
void deleteString(const char *input1, const char *input2, int n1, int n2)
{
    for (int i = 0; i < n1; i++)
    {
        bool output = true;
        for (int j = 0; j < n2; j++)
            if (input1[i] == input2[j])
                output = false;
        if (output == true)
            cout << input1[i];
    }
    cout << endl;
}

//*5.12 字符串最后一个单词的长度
int testStringLength(const char *input, int n)
{
    int m = 0;
    for (int i = n - 1; i >= 0; i--)
        if (input[i] != ' ')
            m++;
        else
            break;
    return m;
}

//*5.13 计算字符个数
int charNum(const char *input, char c, int n)
{
    char dist = 'A' - 'a';
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (input[i] == c)
            m++;
        else if ((input[i] >= 'a' && input[i] <= 'z') && input[i] == c - dist)
            m++;
        else if ((input[i] >= 'A' && input[i] <= 'Z') && input[i] == c + dist)
            m++;
        else
            continue;
    }
    return m;
}

//*5.14 简单密码破解
void passwordGuess(const char *input, int n)
{
    char *password = new char[100];
    char dist = 'A' - 'a';
    for (int i = 0; i < n; i++)
    {
        if (input[i] >= '0' && input[i] <= '9')
            password[i] = input[i];
        else if (input[i] >= 'a' && input[i] <= 'c')
            password[i] = '2';
        else if (input[i] >= 'd' && input[i] <= 'f')
            password[i] = '3';
        else if (input[i] >= 'g' && input[i] <= 'i')
            password[i] = '4';
        else if (input[i] >= 'j' && input[i] <= 'l')
            password[i] = '5';
        else if (input[i] >= 'm' && input[i] <= 'o')
            password[i] = '6';
        else if (input[i] >= 'p' && input[i] <= 's')
            password[i] = '7';
        else if (input[i] >= 't' && input[i] <= 'v')
            password[i] = '8';
        else if (input[i] >= 'w' && input[i] <= 'z')
            password[i] = '9';
        else if (input[i] >= 'A' && input[i] <= 'Y')
            password[i] = input[i] - dist + 1;
        else if (input[i] == 'Z')
            password[i] = 'a';
    }
    cout << "real password: " << password << endl;
    delete[] password;
}

//*5.15 括号配对检测
void checkBrackets(const char *input, int n)
{
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (input[i] == '(')
            m++;
        if (input[i] == ')')
            m--;
    }
    if (m == 0)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}

int main()
{
    //*5.1 字符串的排列
    char test[] = "abc";
    printArrange(test, sizeof(test) / sizeof(char) - 1);
    //*5.2 统计大小写字母的个数
    char test2[] = "aBcDeFg";
    countBigSmall(test2, sizeof(test2) / sizeof(char));
    //*5.3 大小写转化
    bigConvertSmall(test2, sizeof(test2) / sizeof(char));
    //*5.7 字符串长度
    cout << "length:" << lenthString(test2) << endl;
    //*5.8 杨辉三角形
    YangHui(10);
    //*5.9 九九乘法表
    NineXNine();
    //*5.10 翻转句子中单词的顺序
    char test3[] = "I  am a student.";
    inverseString(test3, sizeof(test3) / sizeof(char));
    //*5.11 删除字符串中的字符
    char test4[] = "They are students.";
    char test5[] = "aeiou";
    deleteString(test4, test5, sizeof(test4) / sizeof(char), sizeof(test5) / sizeof(char));
    //*5.13 计算字符个数
    char c = 'E';
    cout << test4 << " has " << charNum(test4, c, sizeof(test4) / sizeof(char)) << ' ' << c << endl;
    //*5.14 简单密码破解
    char test6[] = "YUANzhi1987";
    passwordGuess(test6, sizeof(test6) / sizeof(char));
    //*5.15 括号配对检测
    char test7[] = "3 + 4 + (4+3+((1+2))";
    checkBrackets(test7, sizeof(test7) / sizeof(char));
}