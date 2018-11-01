#include "hyper_sphere.h"
#include <cmath>
#include <random>
#include <QDebug>

Hyper_sphere::Hyper_sphere(double _radius, size_t _dimentions_number)
	:radius(_radius),
	dimentions_number(_dimentions_number),
{}

double init(long long points_num);
{
	std::random_device generator;
	std::uniform_real_distribution <double> dist(-_radius,_radius);
	long long overlap =0;
	long double cub_volume = pow(2*_radius,_dimentions_number);
	for (long long i=0 ; i<points_num ; i++)
	{
		double count =0;
		for(size_t j=0; j< _dimentions_number; j++)
			count+=pow(dist(generator), 2);
		if (count<pow(_radius,2)) overlap++;
	}
	volume = cub_volume*overlap/points_num;
}

double Hyper_sphere::sphere_volume()
{
    return volume;
}

double Hyper_sphere::sphere_radius()
{
    return radius;
}

double Hyper_sphere::sphere_dimentions()
{
    return dimentions_number;
}
