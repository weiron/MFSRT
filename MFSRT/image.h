//
//  image.h
//  MFSRT
//
//  Created by Keisuke Matsumura on 2015/03/26.
//  Copyright (c) 2015年 Keisuke Matsumura. All rights reserved.
//

#ifndef MFSRT_image_h
#define MFSRT_image_h

#include "rgb.h"
#include <cmath>
#include <cstdlib>

class Image
{
public:
    Image(){}
    Image(int w, int h);
    Image(int w, int h, rgb c);
    void safeSetPixel(int x, int y, rgb c)
    {
        if(x >= 0 && x < w && y >= 0 && y < h)
            data[x][y] = c;
    }
    
    void setPixel(int x, int y, rgb c)
    {
        if (!(x >= 0 && x < w && y >= 0 && y < h)) {
            cerr << "Image::setPixel    w = " << w << " h = " << h
            << "   requested pixel (" << x << ", " << y << ")"
            << endl;
            exit(0);
        }
        data[x][y] = c;
    }
    
    rgb getPixel(int x, int y) const
    {
        x = ( x >= 0 ? x : 0);
        x = ( x <  w ? x : w-1);
        y = ( y >= 0 ? y : 0);
        y = ( y <  h ? y : h-1);
        /*      if (!(x >= 0 && x < w && y >= 0 && y < h))
         {
         cerr << "Image::getPixel w = " << w << " h = " << h << endl
         << "       requested pixel (" << x << ", " << y << ")"
         << endl;
         exit(0);
         }
         */
        return data[x][y];
    }
    int width()const {return w;}
    int height() const {return h;}
    void readPPM(char *file_name);
    void writePPM(ostream &s)const;
    
private:
    rgb **data;
    int w, h;
    
};


#endif
