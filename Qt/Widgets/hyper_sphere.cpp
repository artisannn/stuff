#include "hyper_sphere.h"
#include <cmath>
#include <random>
#include <QDebug>

Hyper_sphere::Hyper_sphere(double radius, size_t dimentions_number)
{
    std::random_device generator;
    std::uniform_real_distribution <double> dist(-radius,radius);

    long long n = 1000000;
    long long overlap =0;
    long double cub_volume = pow(2*radius,dimentions_number);
    for (long long i=0 ; i<n ; i++)
    {
        double count =0;
        for(size_t j=0; j< dimentions_number; j++)
            count+=pow(dist(generator), 2);
        if (count<pow(radius,2)) overlap++;
    }
    volume = cub_volume*overlap/n;
}

double Hyper_sphere::sphere_volume()
{
    return volume;
}
