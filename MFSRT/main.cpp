//
//  main.cpp
//  MFSRT
//
//  Created by Keisuke Matsumura on 2015/03/19.
//  Copyright (c) 2015年 Keisuke Matsumura. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "image.h"
#include "Ray.h"
#include "Shape.h"
#include "DynArray.h"
#include "RNG.h"
#include "Triangle.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Ray ray(Vector3(0, 0, 1), Vector3(1, 4, 5));
    cout << ray;
    return 0;
}
