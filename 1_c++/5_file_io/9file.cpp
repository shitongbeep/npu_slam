#include <fstream>
#include <iostream>

using namespace std;

//*9.1 读取文本文件
int readTXTculWord(char *filedst)
{
    int num = 0;
    ifstream fin(filedst);
    fin >> std::noskipws;
    char ch;
    bool space = false;
    while (fin.get(ch))
    {
        // cout << ch;
        if ((ch < 'a' || ch > 'z') &&
            (ch < 'A' || ch > 'Z') &&
            (ch < '0' || ch > '9'))
            if (space == false)
            {
                num++;
                space = true;
            }
            else
                ;
        else
            space = false;
    }
    if ((ch > 'a' && ch < 'z') ||
        (ch > 'A' && ch < 'Z') ||
        (ch > '0' && ch < '9'))
        num++;
    // cout<<ch;
    return num;
}

//*9.2 输出杨辉三角形
void outputYanghui(const char* filedst,int n)
{
    ofstream fout(filedst);
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
                    fout << ' ' << even[j] << ' ';
                }
                else
                {
                    even[j] = 0;
                    fout << "   ";
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
                    fout << "   ";
                else if (odd[j] / 100)
                    fout << odd[j];
                else if (odd[j] / 10)
                    fout << ' ' << odd[j];
                else
                    fout << ' ' << odd[j] << ' ';
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
                    fout << "   ";
                else if (even[j] / 100)
                    fout << even[j];
                else if (even[j] / 10)
                    fout << ' ' << even[j];
                else
                    fout << ' ' << even[j] << ' ';
            }
        }
        fout << endl;
    }
    delete[] odd;
    delete[] even;
}

//*9.3 图书管理系统

int main()
{
    //*9.1 读取文本文件
    char dst[] = "test.txt";
    cout << readTXTculWord(dst) << " words" << endl;
    //*9.2 输出杨辉三角形
    char dst2[]="yanghui.txt";
    outputYanghui(dst2,10);
}