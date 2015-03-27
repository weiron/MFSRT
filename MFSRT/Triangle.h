//
//  Triangle.h
//  MFSRT
//
//  Created by Keisuke Matsumura on 2015/03/27.
//  Copyright (c) 2015年 Keisuke Matsumura. All rights reserved.
//

#ifndef __MFSRT__Triangle__
#define __MFSRT__Triangle__

#include "Shape.h"
#include "Vector3.h"
#include "rgb.h"
#include "Ray.h"

class Triangle : public Shape
{
public:
    Triangle(const Vector3 &_p0, const Vector3 &_p1, const Vector3 &_p2, const rgb &_color);
    bool hit(const Ray& r, float tmin, float tmax, float time, HitRecord &record) const;
    bool shadowHit(const Ray &r, float tmin, float tmax, float time) const;
    
    
    Vector3 p0;
    Vector3 p1;
    Vector3 p2;
    
    rgb color;
};

#endif /* defined(__MFSRT__Triangle__) */
