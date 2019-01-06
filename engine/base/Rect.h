//
// Created by wuwang on 19-1-4.
//

#ifndef _CHARM_RECT_H_
#define _CHARM_RECT_H_

template <typename T>
class Rect {
public:
    T x;
    T y;
    T width;
    T height;
};

typedef Rect<float> RectF;
typedef Rect<int>   RectI;
typedef Rect<double> RectD;

#endif //_CHARM_RECT_H_
