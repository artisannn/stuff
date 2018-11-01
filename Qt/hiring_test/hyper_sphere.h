#ifndef HYPER_SPHERE_H
#define HYPER_SPHERE_H
#include <stddef.h>


class Hyper_sphere
{
    size_t dimentions_number;
    double radius;
    double volume;
public:
    Hyper_sphere(double, size_t);
	double init(long long);
    double sphere_volume();
    double sphere_radius();
    double sphere_dimentions();
};

#endif // HYPER_SPHERE_H
