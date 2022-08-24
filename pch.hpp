// pch.cpp: 与预编译标头对应的源文件

#include "pch.h"
#include "time.h"
// 当使用预编译的头时，需要使用此源文件，编译才能成功。
#include<iostream>
#include <stdlib.h> 
#include <vector>
#include <math.h>
#include <random>
#include <cmath>
#include <boost/array.hpp>
using namespace std;
using namespace boost;
#define M_PI 3.14159265358979323846


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
bool Calculate_distance(double* w, double* q, int index)
{
    bool acu = true;
    double X = w[index];
    double Y = q[index];

    for (int i = 0; i < index; i++)
    {
        double x = w[i];
        double y = q[i];
        if ((Y - y) * (Y - y) + (X - x) * (X - x) <= 3)
        {
            cout << abs((Y - y) * (Y - y) + (X - x) * (X - x)) << endl;
            acu = false;
            break;
        }
    }
    return acu;
}
void Random_Position_Rectangle(double* w, double* q, int Amount, float length, float width)
{
    if (length * width <= 666)
    {
        cout << "面积应大于一亩（666平方米）";
        return;
    }
    else
    {
        if (Amount >= int((length * width / 666)) * 80)
        {
            cout << "每亩最多80棵树，超过当前面积可种树木上限！";
            return;
        }
    }
    srand((unsigned)time(NULL));

    for (int i = 0; i < Amount; i++)
    {
        w[i] = 0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0 + length)));
        q[i] = 0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0 + width)));
        if (i >= 1)
        {
            if (!Calculate_distance(w, q, i))
            {
                i -= 1;
            }
        }
    }

}
void Random_Position_Square(double* w, double* q, int Amount, float length)
{
    if (length * length <= 666)
    {
        cout << "面积应大于一亩（666平方米）";
        return;
    }
    else
    {
        if (Amount >= int((length * length / 666)) * 80)
        {
            cout << "每亩最多80棵树，超过当前面积可种树木上限！";
            return;
        }
    }
    srand((unsigned)time(NULL));

    for (int i = 0; i < Amount; i++)
    {
        w[i]=0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0 + length)));
        q[i]=0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0 + length)));
        if (i >= 1)
        {
            if (!Calculate_distance(w, q, i))
            {
                i -= 1;
            }
        }
    }

}
void Random_Position_Circle(double* w, double* q, int Amount, double radius)
{
    if (radius * radius * M_PI <= 666)
    {
        cout << "面积应大于一亩（666平方米）";
        return;
    }
    else
    {
        if (Amount >= int((radius * radius * M_PI <= 666 / 666)) * 80)
        {
            cout << "每亩最多80棵树，超过当前面积可种树木上限！";
            return;
        }
    }

    srand((unsigned)time(NULL));

    for (int i = 0; i < Amount; i++)
    {
        double theta = (0 + static_cast <double> (rand()) / (static_cast <float> (RAND_MAX / (0 + 1)))) * 2 * M_PI;
        double r = 0 + static_cast <double> (rand()) / (static_cast <float> (RAND_MAX / (0 + radius)));
        w[i]=r* cos(theta);
        q[i]=r* sin(theta);
        if (i >= 1)
        {
            if (!Calculate_distance(w, q, i))
            {
                i -= 1;
            }
        }
    }

}

/*以下为使用模板及boost::array的函数*/

template <int T>
void Gauss_Height(boost::array<double, T>* Height, int Amount)
{
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(25.91, 10.0);
    for (int i = 0; i < Amount; i++)
    {
        double number = distribution(generator);
        Height->at(i) = number;
    }
}
template <int T>
void Gauss_Diameter(boost::array<double, T>* Diameter, int Amount)
{
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0.76, 1);
    for (int i = 0; i < Amount; i++)
    {
        double number = distribution(generator);
        Diameter->at(i) = number;
    }
}
template <int T>
bool Calculate_distance(boost::array<double, T>* w, boost::array<double, T>* q, int index)
{
    bool acu = true;
    double X = w->at(index);
    double Y = q->at(index);

    for (int i = 0; i < index; i++)
    {
        double x = w->at(i);
        double y = q->at(i);
        if ((Y - y) * (Y - y) + (X - x) * (X - x) <= 3)
        {
            cout << abs((Y - y) * (Y - y) + (X - x) * (X - x)) << endl;
            acu = false;
            break;
        }
    }
    return acu;
}
template <int T>
void Random_Position_Rectangle(boost::array<double, T>* w, boost::array<double, T>* q, int Amount, float length, float width)
{
    if (length * width <= 666)
    {
        cout << "面积应大于一亩（666平方米）";
        return;
    }
    else
    {
        if (Amount >= int((length * width / 666)) * 80)
        {
            cout << "每亩最多80棵树，超过当前面积可种树木上限！";
            return;
        }
    }
    srand((unsigned)time(NULL));

    for (int i = 0; i < Amount; i++)
    {
        w->at(i) = 0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0 + length)));
        q->at(i) = 0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0 + width)));
        if (i >= 1)
        {
            if (!Calculate_distance(w, q, i))
            {
                i -= 1;
            }
        }
    }

}
template <int T>
void Random_Position_Square(boost::array<double, T>* w, boost::array<double, T>* q, int Amount, float length)
{
    if (length * length <= 666)
    {
        cout << "面积应大于一亩（666平方米）";
        return;
    }
    else
    {
        if (Amount >= int((length * length / 666)) * 80)
        {
            cout << "每亩最多80棵树，超过当前面积可种树木上限！";
            return;
        }
    }
    srand((unsigned)time(NULL));

    for (int i = 0; i < Amount; i++)
    {
        w->at(i) = 0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0 + length)));
        q->at(i) = 0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0 + length)));
        if (i >= 1)
        {
            if (!Calculate_distance(w, q, i))
            {
                i -= 1;
            }
        }
    }

}
template <int T>
void Random_Position_Circle(boost::array<double, T>* w, boost::array<double, T>* q, int Amount, double radius)
{
    if (radius * radius * M_PI <= 666)
    {
        cout << "面积应大于一亩（666平方米）";
        return;
    }
    else
    {
        if (Amount >= int((radius * radius * M_PI <= 666 / 666)) * 80)
        {
            cout << "每亩最多80棵树，超过当前面积可种树木上限！";
            return;
        }
    }

    srand((unsigned)time(NULL));

    for (int i = 0; i < Amount; i++)
    {
        double theta = (0 + static_cast <double> (rand()) / (static_cast <float> (RAND_MAX / (0 + 1)))) * 2 * M_PI;
        double r = 0 + static_cast <double> (rand()) / (static_cast <float> (RAND_MAX / (0 + radius)));
        w->at(i) = r * cos(theta);
        q->at(i) = r * sin(theta);
        if (i >= 1)
        {
            if (!Calculate_distance(w, q, i))
            {
                i -= 1;
            }
        }
    }

}
