//
//  Sphere.cpp
//  MFSRT
//
//  Created by Keisuke Matsumura on 2015/03/28.
//  Copyright (c) 2015年 Keisuke Matsumura. All rights reserved.
//

#include "Sphere.h"

Sphere::Sphere(const Vector3 &_center, float _radius, const rgb &_color) :
    center(_center), radius(_radius), color(_color)
{
    
}

bool Sphere::hit(const Ray &r, float tmin, float tmax, float time, HitRecord &record) const
{
    Vector3 temp = r.origin() - center;
    
    double a = dot(r.direction(), r.direction());
    double b = 2*dot(r.direction(), temp);
    double c = dot(temp, temp) - radius*radius;
    
    double discriminant = b*b - 4*a*c;
    
    if (discriminant > 0) {
        discriminant = sqrt(discriminant);
        double t = (-b - discriminant) / (2*a);
        
        if (t < tmin) {
            t = (-b + discriminant) / (2*a);
        }
        if (t < tmin || t > tmax) {
            return false;
        }
        
        record.t = t;
        record.normal = unitVector(r.origin()+t*r.direction()-center);
        record.color = color;
        return true;
    }
    return false;
}

bool Sphere::shadowHit(const Ray &r, float tmin, float tmax, float time) const
{
    Vector3 temp = r.origin() - center;
    
    double a = dot(r.direction(), r.direction());
    double b = 2*dot(r.direction(), temp);
    double c = dot(temp, temp) - radius*radius;
    
    double discriminant = b*b - 4*a*c;
    
    if (discriminant > 0) {
        discriminant = sqrt(discriminant);
        double t = (-b - discriminant) / (2*a);
        
        if (t < tmin) {
            t = (-b + discriminant) / (2*a);
        }
        if (t < tmin || t > tmax) {
            return false;
        }
        
        return true;
    }
    return false;
}