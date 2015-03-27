//
//  Ray.h
//  MFSRT
//
//  Created by Keisuke Matsumura on 2015/03/27.
//  Copyright (c) 2015年 Keisuke Matsumura. All rights reserved.
//

#ifndef MFSRT_Ray_h
#define MFSRT_Ray_h

#include "Vector3.h"

using namespace std;

class Ray
{
public:
    Ray() {}
    Ray(const Vector3& a, const Vector3& b)
    {
        data[0] = a; data[1] = b;
        data[2] = Vector3(1.0 / b.x(), 1.0 / b.y(), 1.0 / b.z());
        
        posneg[0] =  (data[1].x() > 0 ? 0 : 1);
        posneg[1] = posneg[0] ^ 1;
        
        posneg[2] =  (data[1].y() > 0 ? 0 : 1);
        posneg[3] = posneg[2] ^ 1;
        
        posneg[4] =  (data[1].z() > 0 ? 0 : 1);
        posneg[5] = posneg[4] ^ 1;

        
    }
    
    Ray(const Ray& r) {*this = r;}
    Vector3 origin() const {return data[0];}
    Vector3 direction() const {return data[1];}
    Vector3 invDirection() const {return data[2];}
    void setOrigin(const Vector3& v) {data[0] = v;}
    void setDirection(const Vector3& v)
    {
        data[1] = v;
        data[2] = Vector3(1.0f / v.x(), 1.0f / v.y(), 1.0f / v.z());
        
        posneg[0] =  (data[1].x() > 0 ? 0 : 1);
        posneg[1] = posneg[0] ^ 1;
        
        posneg[2] =  (data[1].y() > 0 ? 0 : 1);
        posneg[3] = posneg[2] ^ 1;
        
        posneg[4] =  (data[1].z() > 0 ? 0 : 1);
        posneg[5] = posneg[4] ^ 1;
    }
    Vector3 pointAtParameter(float t) const { return data[0] + t*data[1]; }
    
    Vector3 data[3]; //o d 1/d
    int posneg[6];
};

inline ostream& operator<<(ostream &os, const Ray &r)
{
    os << "(" << r.origin() << ") + t("  << r.direction() << ")";
    return os;
}


#endif
