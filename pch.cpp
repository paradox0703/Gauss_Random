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
using namespace std;

#define M_PI 3.14159265358979323846

void Gauss_Height(vector<double>* Height, int Amount)
{
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(25.91, 10.0);
    for (int i = 0; i < Amount; i++)
    {
        double number = distribution(generator);
        Height->push_back(number);
    }
}
void Gauss_Diameter(vector<double>* Diameter, int Amount)
{
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0.76, 1);
    for (int i = 0; i < Amount; i++)
    {
        double number = distribution(generator);
        Diameter->push_back(number);
    }
}
bool Calculate_distance(vector<double>* w, vector<double>* q, int index)
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
void Random_Position_Rectangle(vector<double>* w, vector<double>* q, int Amount, float length, float width)
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
        w->push_back(0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0 + length))));
        q->push_back(0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0 + width))));
        if (i >= 1)
        {
            if (!Calculate_distance(w, q, i))
            {
                i -= 1;
                w->pop_back();
                q->pop_back();
            }
        }
    }

}
void Random_Position_Square(vector<double>* w, vector<double>* q, int Amount, float length)
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
        w->push_back(0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0 + length))));
        q->push_back(0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0 + length))));
        if (i >= 1)
        {
            if (!Calculate_distance(w, q, i))
            {
                i -= 1;
                w->pop_back();
                q->pop_back();
            }
        }
    }

}
void Random_Position_Circle(vector<double>* w, vector<double>* q, int Amount, double radius)
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
        w->push_back(r * cos(theta));
        q->push_back(r * sin(theta));
        if (i >= 1)
        {
            if (!Calculate_distance(w, q, i))
            {
                i -= 1;
                w->pop_back();
                q->pop_back();
            }
        }
    }

}
