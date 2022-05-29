#include <iostream>
#include <tuple>
#include <math.h>

//* 1.基础题

//* 1.1
float max(float a, float b, float c)
{
    float max = a;
    if (max < b)
        max = b;
    if (max < c)
        max = c;
    return max;
}

//*1.2
std::tuple<bool, std::tuple<float, float>> extract_root(float a, float b, float c)
{
    std::tuple<bool, std::tuple<float, float>> ret;
    if (abs(a) + abs(b) == 0)
        return ret = std::make_tuple(false, std::make_tuple(0, 0));

    if (a == 0)
        return ret = std::make_tuple(true, std::make_tuple(c / b, c / b));

    float dealt = b * b - 4 * a * c;
    if (dealt < 0)
        return ret = std::make_tuple(false, std::make_tuple(0, 0));
    return ret = std::make_tuple(true, std::make_tuple((-b + sqrt(dealt)) / (2 * a), (-b - sqrt(dealt)) / (2 * a)));
}

//*1.3
bool triangle(double a, double b, double c)
{
    bool ret = false;
    if (a > 0 && b > 0 && c > 0)
        if (a + b > c && a + c > b && b + c > a)
            ret = true;
    return ret;
}

int main(int argc, char **argv)
{
    std::cout << "max:" << max(1, 2, -3) << std::endl;                                                                                                      //?2
    std::cout << "extract_root:" << std::get<0>(std::get<1>(extract_root(1, 2, 1))) << ' ' << std::get<1>(std::get<1>(extract_root(1, 2, 1))) << std::endl; //?-1 -1
    std::cout << "triangle:" << triangle(3, 2, 3) << std::endl;                                                                                             //?1
}