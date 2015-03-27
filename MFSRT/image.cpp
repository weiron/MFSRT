//
//  image.cpp
//  MFSRT
//
//  Created by Keisuke Matsumura on 2015/03/26.
//  Copyright (c) 2015年 Keisuke Matsumura. All rights reserved.
//

#include "image.h"
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

Image::Image(int w_, int h_) :
    w(w_), h(h_)
{
    assert(w > 0 && h > 0);
    data = new rgb*[w];
    assert(data != 0);
    for (int i = 0; i < w; i++) {
        data[i] = new rgb[h];
        assert(data[i]);
    }
}

Image::Image(int w_, int h_ , rgb c) : w(w_), h(h_) {
    assert(w > 0 && h > 0);
    data = new rgb*[w];
    assert(data != 0);
    for (int i = 0; i < w; i++) {
        data[i] = new rgb[h];
        assert(data[i]);
        for (int j = 0; j < h; j++)
            data[i][j] = c;
    }
}

void Image::readPPM(char *file_name)
{
    int i, j;
    ifstream in;
    in.open(file_name);
    if (!in) {
        cerr << "ERROR -- Can't find PPM file \'" << string(file_name) << "\'\n";
        exit(0);
    }
    string file_type, garbage;
    rgb pix_col;
    
    in >> file_type >> w >> h >> garbage;
    
    data = new rgb*[w];
    for (i = 0; i < w; i++) {
        data[i] = new rgb[h];
    }
    
    if (file_type == "P3") {
        int red, green, blue;
        for (i = h - 1; i >= 0; i--) {
            for (j = 0; j < w; j++) {
                in >> red >> green >> blue;
                pix_col[0] = ((float(red)   + 0.5) / 256.0) *
                ((float(red)   + 0.5) / 256.0);
                pix_col[1] = ((float(green) + 0.5) / 256.0) *
                ((float(green) + 0.5) / 256.0);
                pix_col[2] = ((float(blue)  + 0.5) / 256.0) *
                ((float(blue)  + 0.5) / 256.0);
                
                data[j][i] = pix_col;
            }
        }
    }
    else
    {
        unsigned char red, green, blue;
        in.get((char&)red);
        for (i = h-1; i >= 0; i--)
            for (j = 0; j < w; j++)
            {
                in.get((char&)red);
                in.get((char&)green);
                in.get((char&)blue);
                
                pix_col[0] = ((float(red)   + 0.5) / 256.0) *
                ((float(red)   + 0.5) / 256.0);
                pix_col[1] = ((float(green) + 0.5) / 256.0) *
                ((float(green) + 0.5) / 256.0);
                pix_col[2] = ((float(blue)  + 0.5) / 256.0) *
                ((float(blue)  + 0.5) / 256.0);
                
                data[j][i] = pix_col;
            }
        
    }
}

void Image::writePPM(ostream &s) const
{
    s << "P6\n" << w << " " << h << "\n255\n";
    
    unsigned int i;
    for(int y = h-1; y >= 0; y--)
    {
        for(int x = 0; x < w; x++)
        {
            float gamma = 1.0 / 2.2;
            data[x][y] = rgb(pow(data[x][y].r(), gamma), pow(data[x][y].g(), gamma), pow(data[x][y].b(),gamma));
            i = (unsigned int)(256.0 * data[x][y].r());
            if (i > 255)i = 255;
            s.put(i);
            i = (unsigned int)(256.0 * data[x][y].g());
            if (i > 255)i = 255;
            s.put(i);
            i = (unsigned int)(256.0 * data[x][y].b());
            if (i > 255)i = 255;
            s.put(i);
        }
    }
}



