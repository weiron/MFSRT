//
//  Shape.h
//  MFSRT
//
//  Created by Keisuke Matsumura on 2015/03/27.
//  Copyright (c) 2015年 Keisuke Matsumura. All rights reserved.
//

#ifndef MFSRT_Shape_h
#define MFSRT_Shape_h

#include "Ray.h"
#include "Vector3.h"
#include "rgb.h"

struct HitRecord
{
    float t;
    Vector3 normal;
    rgb color;
    
};

class Shape
{
public:
    virtual bool hit(const Ray& r, float tmin, float tmax, float time, HitRecord& recort) const = 0;
    virtual bool shadowHit(const Ray& r, float tmin, float tmax, float time) const = 0;
};

#endif
