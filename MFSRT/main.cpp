//
//  main.cpp
//  MFSRT
//
//  Created by Keisuke Matsumura on 2015/03/19.
//  Copyright (c) 2015年 Keisuke Matsumura. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "Vector3.h"
#include "rgb.h"
#include "image.h"
#include "Shape.h"
#include "Triangle.h"
#include "Sphere.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    HitRecord rec;
    bool is_a_hit;
    float tmax;
    Vector3 dir(0,0,-1);
    
    vector<Shape*> shapes;
    shapes.push_back(new Sphere(Vector3(250,250,-1000), 150, rgb(.2,.2,.8)));
    shapes.push_back(new Triangle(Vector3(300.0f, 600.0f, -800), Vector3(0.0f, 100.0f, -1000), Vector3(450.0f,20.0f,-1000), rgb(.8,.2,.2)));
    
    Image im(500,500);
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            tmax = 100000.0f;
            is_a_hit = false;
            Ray r(Vector3(i,j,0), dir);
            
            for (int k = 0; k < shapes.size(); k++) {
                if (shapes[k]->hit(r, .00001f, tmax, 0, rec)) {
                    tmax = rec.t;
                    is_a_hit = true;
                }
                
                if (is_a_hit) {
                    im.setPixel(i, j, rec.color);
                }else {
                    im.setPixel(i, j, rgb(.2,.2,.2));
                }
            }
        }
    }
    ofstream output("test.ppm");
    im.writePPM(output);
    return 0;
}
