//
//  Sphere.h
//  MFSRT
//
//  Created by Keisuke Matsumura on 2015/03/28.
//  Copyright (c) 2015年 Keisuke Matsumura. All rights reserved.
//

#ifndef __MFSRT__Sphere__
#define __MFSRT__Sphere__

#include "Shape.h"
#include "Vector3.h"
#include "Ray.h"
#include "rgb.h"

class Sphere : public Shape
{
public:
    Sphere(const Vector3& _center, float _radius, const rgb& _color);
    bool hit(const Ray& r, float tmin, float tmax, float time, HitRecord& record) const;
    bool shadowHit(const Ray& r, float tmin, float tmax, float time) const;
    
    Vector3 center;
    float radius;
    rgb color;
};

#endif /* defined(__MFSRT__Sphere__) */
