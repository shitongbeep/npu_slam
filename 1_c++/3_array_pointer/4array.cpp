#include <iostream>
#include <tuple>
#include <vector>

//*4.1 数组逆序
void invert(int *array, int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
        i++;
        j--;
    }
}

//*4.2 数组的最大元素
int maxPos(int *array, int n)
{
    int max = array[0];
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
            pos++;
        }
    }
    return pos;
}

//*4.3求鞍点
std::vector<std::tuple<int, int>> lowPoint(int **array, int row, int col)
{
    bool exist = false;
    std::vector<std::tuple<int, int>> ret;
    for (int i = 0; i < row; i++)
    {
        int max = array[i][0], pos = 0;
        for (int j = 0; j < col; j++)
        {
            if (max < array[i][j])
            {
                max = array[i][j];
                pos++;
            }
        }
        bool ifmax = true;
        for (int j = 0; j < row; j++)
        {
            if (array[j][pos] < max)
            {
                ifmax == false;
                break;
            }
        }
        if (ifmax == true)
        {
            exist = true;
            ret.push_back(std::make_tuple(i, pos));
        }
    }
    if (exist == false)
        ret.push_back(std::make_tuple(-1, -1));
    return ret;
}

//*4.4 查找某个值
int findvalue(int *array, int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] == value)
            return i;
    }
    return -1;
}

//*4.5 求子数组的最大和
std::tuple<int, int, int> subArraySum(const int *array, int n)
{
    std::tuple<int, int, int> ret;
    int begin0 = 0, begin = 0, end = 0, max, min = max = array[0], sum = 0, subsum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += array[i];
        if (max < sum)
        {
            max = sum;
            end = i;
        }
        if (min > sum)
        {
            min = sum;
            begin0 = i + 1;
        }
        if (begin0 < end)
        {
            begin = begin0;
            subsum = max - min;
        }
    }
    ret = std::make_tuple(subsum, begin, end);
    return ret;
}

//*4.6 查找最小的k个元素
void minNint(const int *array, int n, int k)
{
    int *minK = new int[k];
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            for (int j = 0; j < k; j++)
                minK[j] = array[0];
        else
        {
            if (array[i] < minK[0])
                //*小于最大值的时候才考虑放进来
                for (int j = 1; j < k; j++)
                {
                    //*前面的元素往前挪
                    if (array[i] < minK[j])
                    {
                        minK[j - 1] = minK[j];
                    }
                    //*挪到合适的位置存下来
                    else
                    {
                        minK[j - 1] = array[i];
                        break;
                    }
                    //*如果挪到了最后存下来
                    if (j == k - 1)
                        minK[j] = array[i];
                }
            // else if (minK[0] == minK[1])
            //     for (int j = 0; j < k - 1; j++)
            //         if (minK[j] == minK[j + 1])
            //             minK[j] = array[i];
            //         else
            //             break;
            else if (i < k) //!保证前K个元素的不同
                for (int j = 0; j < k - i; j++)
                    minK[j] = array[i];
        }
    }
    std::cout << "min " << k << " element:";
    for (int i = 0; i < k; i++)
        std::cout << minK[i] << ' ';
    std::cout << std::endl;
    delete[] minK;
}

//*4.7 两数之和
std::tuple<int, int> findSumPosi(int *array, int n, int target)
{
    int sub;
    for (int i = 0; i < n; i++)
    {
        sub = target - array[i];
        for (int j = i; j < n; j++)
            if (array[j] == sub)
                return std::make_tuple(i, j);
    }
    return std::make_pair(-1, -1);
}
int main()
{
    //*求子数组的最大和
    int test[] = {1, -2, 3, 10, -4, 7, 2, -5, -4};
    std::tuple<int, int, int> ans = subArraySum(test, sizeof(test) / sizeof(int));
    std::cout << "max sub array sum: " << std::get<0>(ans) << std::endl;
    std::cout << "sub array: ";
    for (int i = std::get<1>(ans); i <= std::get<2>(ans); i++)
    {
        std::cout << test[i] << ' ';
    }
    std::cout << std::endl;

    //*4.6 查找最小的k个元素
    minNint(test, sizeof(test) / sizeof(int), 4);

    //*4.7 两数之和
    int target=3;
    std::tuple<int, int> anse = findSumPosi(test, sizeof(test) / sizeof(int), target);
    std::cout << "tow num sum:" << std::endl;
    std::cout << "num[" << std::get<0>(anse) << "] + num[" << std::get<1>(anse) << "] = " << test[std::get<0>(anse)] << " + " << test[std::get<1>(anse)] << " = " << target << std::endl;
}
