#include <iostream>
#include <algorithm>

using namespace std;

//*1. 岛屿的最大面积
#define ROW 8
#define COL 13
void area(int input[ROW][COL], int i, int j, int &now)
{
    input[i][j] = 0;
    now++;
    if (i - 1 >= 0 && input[i - 1][j])
        area(input, i - 1, j, now);
    if (i + 1 < ROW && input[i + 1][j])
        area(input, i + 1, j, now);
    if (j - 1 >= 0 && input[i][j - 1])
        area(input, i, j - 1, now);
    if (j + 1 < COL && input[i][j + 1])
        area(input, i, j + 1, now);
}

void maxArea(int input[ROW][COL])
{
    int max = 0, now = 0;
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
        {
            if (input[i][j])
                area(input, i, j, now);
            if (now > max)
                max = now;
            now = 0;
        }
    cout << "max area: " << max << endl;
}

//*2. 最长连续递增序列
void maxIncArr(int *input, int n)
{
    int begin0 = 0, end0 = 0;
    int begin = 0, end = 0;
    int max = 1, now = 1;
    for (int i = 1; i < n; i++)
    {
        if (input[i] > input[i - 1])
        {
            end0 = i;
            now++;
        }
        else
        {
            if (now > max)
            {
                max = now;
                end = end0;
                begin = begin0;
            }
            now = 1;
            begin0 = end0 = i;
        }
    }
    cout << "max increase array : ";
    while (begin <= end)
        cout << input[begin++] << ' ';
    cout << " ;length: " << max << endl;
}

//*3. 数组中的第K个最大元素
void maxKElement(int input[], int n, int k)
{
    int *maxk = new int[k];
    for (int i = 0; i < k; i++)
        maxk[i] = input[0];
    for (int i = 1; i < n; i++)
    {
        if (input[i] > maxk[0])
            for (int j = 1; j < k; j++)
            {
                if (input[i] > maxk[j])
                {
                    maxk[j - 1] = maxk[j];
                    if (j == k - 1)
                        maxk[j] = input[i];
                }
                else
                {
                    maxk[j - 1] = input[i];
                    break;
                }
            }
        else if (i < k)
            for (int j = 0; j < k - i; j++)
                maxk[j] = input[i];
        // for (int i = 0; i < k; i++)
        //     cout << maxk[i] << ' ';
        // cout << endl;
    }
    cout << "max num_k element : " << maxk[0] << endl;
    for (int i = 0; i < k; i++)
        cout << maxk[i] << ' ';
    cout << endl;
    delete[] maxk;
}

//*4. 朋友圈
#define FRIENDNUM 3
void addFriendGroup(const int group[FRIENDNUM][FRIENDNUM], int student[FRIENDNUM], int which)
{
    if (student[which] == 0)
        return;
    student[which] = 0;
    for (int i = which; i < FRIENDNUM; i++)
        if (group[which][i] == 1)
            addFriendGroup(group, student, i);
}
void friendGroup(int group[FRIENDNUM][FRIENDNUM])
{
    int student[FRIENDNUM];
    for (int i = 0; i < FRIENDNUM; i++)
        student[i] = 1;
    int groupnum = 0;
    for (int i = 0; i < FRIENDNUM; i++)
        if (student[i] == 1)
        {
            groupnum++;
            addFriendGroup(group, student, i);
        }
    cout << groupnum << " groups" << endl;
}

//*5. 中值均值
void midAverage(int *input, int n, float nabor)
{
    int front = (float)n * (1 - nabor) / 2 + 0.5;
    int end = (float)n * (nabor + (1 - nabor) / 2) + 0.5;
    float ret = 0;

    sort(input, input + n, [](int a, int b) -> bool
         { return a > b; });

    for (int i = front; i < end; i++)
        ret += (float)input[i] / (end - front);

    cout << "mid average: " << ret << endl;
}

//*6. 两个数组的交集
void checkIntersection(int *input1, int n1, int *input2, int n2)
{
    sort(input1, input1 + n1, [](int a, int b) -> bool
         { return a < b; });
    sort(input2, input2 + n2, [](int a, int b) -> bool
         { return a < b; });
    int cur = input1[0], intersectNum = 0,i;
    int *intersection = new int[min(n1, n2)];
    for (i = 0, intersectNum = 0; i < n1; i++)
    {
        if (input1[i] != cur || i == 0)
        {
            for (int j = 0; j < n2; j++)
            {
                if (input2[j] > input1[i])
                    break;
                if (input2[j] == input1[i])
                {
                    intersection[intersectNum] = input1[i];
                    intersectNum++;
                    break;
                }
            }
        }
        cur = input1[i];
    }
    cout << "check intersection (" << intersectNum << ") :";
    for (int i = 0; i < intersectNum; i++)
        cout << intersection[i] << ' ';
    cout << endl;
}

int main()
{
    //*1. 岛屿的最大面积
    int test1[ROW][COL] = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                           {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                           {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    maxArea(test1);
    //*2. 最长连续递增序列
    int test20[] = {1, 3, 5, 4, 7};
    int test21[] = {2, 2, 2, 2, 2};
    int test22[] = {1, 3, 5, 2, 1, 3, 5, 7, 9, 2, 1, 3, 5};
    maxIncArr(test20, sizeof(test20) / sizeof(int));
    maxIncArr(test21, sizeof(test21) / sizeof(int));
    maxIncArr(test22, sizeof(test22) / sizeof(int));
    //*3. 数组中的第K个最大元素
    int test30[] = {3, 2, 1, 5, 6, 4};
    int test31[] = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    maxKElement(test30, sizeof(test30) / sizeof(int), 6);
    maxKElement(test31, sizeof(test31) / sizeof(int), 9);
    //*4. 朋友圈
    int test41[FRIENDNUM][FRIENDNUM] = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    int test42[FRIENDNUM][FRIENDNUM] = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
    int test43[FRIENDNUM][FRIENDNUM] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    friendGroup(test41);
    friendGroup(test42);
    friendGroup(test43);
    //*5. 中值均值
    int test51[] = {4, 9, 1, 2, 3, 8, 5, 7, 6, 0};
    int test52[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int test53[] = {19, 34, 8};
    midAverage(test51, sizeof(test51) / sizeof(int), 0.8);
    midAverage(test52, sizeof(test52) / sizeof(int), 0.8);
    midAverage(test53, sizeof(test53) / sizeof(int), 0.9);
    //*6. 两个数组的交集
    int nums1[] = {1, 2, 2, 1};
    int nums2[] = {2, 2};
    checkIntersection(nums1, sizeof(nums1) / sizeof(int), nums2, sizeof(nums2) / sizeof(int));
    int nums3[] = {4, 9, 5};
    int nums4[] = {9, 4, 9, 8, 4};
    checkIntersection(nums3, sizeof(nums3) / sizeof(int), nums4, sizeof(nums4) / sizeof(int));
}