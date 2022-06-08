#include <iostream>
using namespace std;

//*1. 无重复字符的最长子串
bool findInStr(char c, const char *input, int n)
{
    for (int i = 0; i < n && input[i] != 0; i++)
        if (c == input[i])
            return true;
    return false;
}
void noRepLongestSubStr(const char *input, int n)
{
    char *nowstr = new char[n]{0};
    int max = 0, now = 0;
    int begin0 = 0, end0 = 0;
    int begin = 0, end = 0;
    char c = 0;
    for (int i = 0, m = 0; i < n; i++)
    {
        c = input[i];
        if (!findInStr(c, nowstr, n))
        {
            now++;
            nowstr[m++] = input[i];
            end0++;
        }
        else
        {
            if (now > max)
            {
                max = now;
                begin = begin0;
                end = end0;
            }
            now = 1;
            begin0 = i;
            end0 = i + 1;
            m = 1;
            for (int m = 0; m < n && nowstr[m] != 0; m++)
                nowstr[m] = 0;
            nowstr[0] = c;
        }
    }
    if (now > max)
    {
        max = now;
        begin = begin0;
        end = end0;
    }
    cout << "max sub norepititive string: ";
    while (begin < end)
        cout << input[begin++];
    cout << "; length: " << max << endl;
    delete[] nowstr;
}

//*2. 最长公共前缀
const char *findConPre(char **input, int n)
{
    int pre = 0;
    bool exist = true;
    do
    {
        char c = input[0][pre];
        for (int i = 1; i < n; i++)
            if (c != input[i][pre])
                exist = false;
    } while (exist && ++pre);

    char *ret = new char[pre + 2];
    for (int i = 1; i < pre + 1; i++)
        ret[i] = input[0][i - 1];
    ret[0] = '\"';
    ret[pre + 1] = '\"';
    return ret;
}

//*3. 字符串的排列
void findIfSubStr(const char *s1, int n1, const char *s2, int n2)
{
    if (n1 > n2)
        cout << "false" << endl;

    int graph[26]{0};
    for (int i = 0; i < n1 && s1[i] != 0; i++)
        graph[s1[i] % 'a']++;
    int graphsize = n1 - 1;

    bool exist = false, exist0 = false;
    for (int i = 0; graphsize > 0 && i < n2 && s2[i] != 0; i++)
    {
        if (graph[s2[i] % 'a'] != 0)
        {
            exist0 = true;
            graph[s2[i] % 'a']--;
            graphsize--;
        }
        else if (exist0 == true && graph[s2[i] % 'a'] == 0)
        {
            exist0 = false;
            graphsize = n1 - 1;
            for (int i = 0; i < 26; i++)
                graph[i] = 0;
            for (int i = 0; i < n1 && s1[i] != 0; i++)
                graph[s1[i] % 'a']++;
        }
    }
    if (exist0 == true)
        cout << "True" << endl;
    else
        cout << "false" << endl;
}

int main()
{
    //*1. 无重复字符的最长子串
    char test1[] = "abcabcbb";
    noRepLongestSubStr(test1, sizeof(test1) / sizeof(char));
    char test2[] = "bbbbb";
    noRepLongestSubStr(test2, sizeof(test2) / sizeof(char));
    char test3[] = "pwwkew";
    noRepLongestSubStr(test3, sizeof(test3) / sizeof(char));
    //*2. 最长公共前缀
    char test40[] = "flower";
    char test41[] = "flow";
    char test42[] = "flight";
    char *test4[] = {test40, test41, test42};
    cout << findConPre(test4, sizeof(test4) / sizeof(char *)) << endl;
    char test50[] = "dog";
    char test51[] = "racecar";
    char test52[] = "car";
    char *test5[] = {test50, test51, test52};
    cout << findConPre(test5, sizeof(test5) / sizeof(char *)) << endl;
    //*3. 字符串的排列
    char test60[] = "ab";
    char test61[] = "eidbaooo";
    findIfSubStr(test60, sizeof(test60) / sizeof(char), test61, sizeof(test61) / sizeof(char));
    char test70[] = "ab";
    char test71[] = "eidboaoo";
    findIfSubStr(test70, sizeof(test70) / sizeof(char), test71, sizeof(test71) / sizeof(char));
}