//
//  RNG.h
//  MFSRT
//
//  Created by Keisuke Matsumura on 2015/03/28.
//  Copyright (c) 2015年 Keisuke Matsumura. All rights reserved.
//

#ifndef MFSRT_RNG_h
#define MFSRT_RNG_h

class RNG
{
public:
    RNG(unsigned long long _seed = 7564231ULL)
    {
        seed      = _seed;
        mult      = 62089911ULL;
        llong_max = 4294967295ULL;
        float_max = 4294967295.0f;
    }
    float operator()();
    
    unsigned long long seed;
    unsigned long long mult;
    unsigned long long llong_max;
    float float_max;
};

inline float RNG::operator()()
{
    seed = mult * seed;
    return float(seed % llong_max) / float_max;
}


#endif
