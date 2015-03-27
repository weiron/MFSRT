//
//  DynArray.h
//  MFSRT
//
//  Created by Keisuke Matsumura on 2015/03/27.
//  Copyright (c) 2015年 Keisuke Matsumura. All rights reserved.
//

#ifndef MFSRT_DynArray_h
#define MFSRT_DynArray_h

#include <cstdlib>
#include <cassert>

template <class T>
class DynArray
{
public:
    DynArray();
    DynArray(int);
    ~DynArray();
    DynArray(const DynArray<T>&);
    DynArray<T>& operator=(const DynArray<T>&);
    
    bool append(T item); // always tagged to end
    bool truncate();     // make arRaySize = nData;
    void clear() { nData = 0; }
    
    int length() const { return nData; }
    bool empty() const { return length() == 0; }
    
    const T &operator[] (int i) const { assert(i >= 0 && i < length());
        return data[i]; }
    T &operator[] (int i) { assert(i >= 0 && i < length());
        return data[i]; }
    
private:
    T *data;
    int nData;
    int arRaySize;
};

template <class T>
DynArray<T>::DynArray() {
    nData = 0;
    arRaySize = 4;
    data = new T[arRaySize];
}

template <class T>
DynArray<T>::DynArray(int a) {
    nData = 0;
    arRaySize = a;
    data = new T[arRaySize];
}

template <class T>
DynArray<T>::DynArray(const DynArray<T>& t) {
    nData = t.length();
    arRaySize = t.arRaySize;
    data = new T[arRaySize];
    for (int i = 0; i < t.length(); i++)
        data[i] = t[i];
}

template <class T>
DynArray<T>::~DynArray() {
    nData = 0;
    delete [] data;
}

template <class T>
DynArray<T>& DynArray<T>::operator=(const DynArray<T>& t) {
    if (&t == this) return *this;
    if (data != 0) delete [] data;
    nData = t.length();
    arRaySize = t.arRaySize;
    data = new T[arRaySize];
    for (int i = 0; i < t.length(); i++)
        data[i] = t[i];
    return *this;
}

template <class T>
bool DynArray<T>::truncate()
{
    if(nData != arRaySize)
    {
        T *temp = data;
        arRaySize = nData;
        if(!(data = new T[arRaySize])) return false;
        for(int i = 0; i < nData; i++)
            data[i] = temp[i];
        delete [] temp;
    }
    return true;
}

template <class T>
bool DynArray<T>::append(T item) {
    if (nData == arRaySize) {
        arRaySize *= 2;
        T *temp = data;
        if (!(data = new T[arRaySize])) return false;
        for (int i = 0; i < nData; i++)
            data[i] = temp[i];
        delete [] temp;
    }
    data[nData++] = item;
    return true;
}





#endif
