// pch.cpp: 与预编译标头对应的源文件

#include "pch.h"
#include "time.h"
// 当使用预编译的头时，需要使用此源文件，编译才能成功。
#include<iostream>
#include <stdlib.h> 
#include <time.h>
#include <math.h>
#include <random>
using namespace std;


void Gauss_Height(double* Height, int Amount)
{
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(25.91, 10.0);
    for (int i = 0; i < Amount; i++)
    {
        double number = distribution(generator);
        Height[i] = number;
    }
}
void Gauss_Diameter(double* Diameter, int Amount)
{
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0.76, 1);
    for (int i = 0; i < Amount; i++)
    {
        double number = distribution(generator);
        Diameter[i] = number;
    }
}
bool check(double* a, double* b, int index)
{
    bool acu = true;
    for (int i = 0; i <= index; i++)
    {
        if (abs((a[index] - a[i]) * (a[index] - a[i]) + (b[index] - b[i]) * (b[index] - b[i])) > 3
            &&
            abs((a[index] - a[i]) * (a[index] - a[i]) + (b[index] - b[i]) * (b[index] - b[i])) < 5)
        {
            acu = false;
            break;
        }
    }
    return acu;
}
void Random_Position_Rectangle(double* w, double* q, int Amount, float length, float width)
{
    srand((unsigned)time(NULL));
    clock_t start, end;
    start = clock();
    for (int i = 0; i < Amount; i++)
    {
        w[i] = 0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0 + length)));
        q[i] = 0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0 + width)));
        if (i >= 1)
        {
            if (!check(w, q, i))
            {
                i -= 1;
            }
        }
    }
    end = clock();   //结束时间
    cout << "time = " << double(end - start) / CLOCKS_PER_SEC << "s" << endl;
}
void Random_Position_Square(double* w, double* q, int Amount, float length)
{
    srand((unsigned)time(NULL));
    clock_t start, end;
    start = clock();
    for (int i = 0; i < Amount; i++)
    {
        w[i] = 0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0 + length)));
        q[i] = 0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0 + length)));
        if (i >= 1)
        {
            if (!check(w, q, i))
            {
                i -= 1;
            }
        }
    }
    end = clock();   //结束时间
    cout << "time = " << double(end - start) / CLOCKS_PER_SEC << "s" << endl;
}
void Random_Position_Circle(double* w, double* q, int Amount, double radius)
{
    srand((unsigned)time(NULL));
    clock_t start, end;
    start = clock();
    for (int i = 0; i < Amount; i++)
    {
        w[i] = 0 + static_cast <double> (rand()) / (static_cast <float> (RAND_MAX / (0 + radius * 2)));
        double up = sqrt(radius * radius - (w[i] - radius) * (w[i] - radius)) + radius;
        double down = -1 * sqrt(radius * radius - (w[i] - radius) * (w[i] - radius)) + radius;
        q[i] = down + static_cast <double> (rand()) / (static_cast <float> (RAND_MAX / down + up));
        if (i >= 1)
        {
            if (!check(w, q, i))
            {
                i -= 1;
            }
        }
    }
    end = clock();   //结束时间
    cout << "time = " << double(end - start) / CLOCKS_PER_SEC << "s" << endl;
}
