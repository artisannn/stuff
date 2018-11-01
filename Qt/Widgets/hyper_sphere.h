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
    double sphere_volume();

};

#endif // HYPER_SPHERE_H
