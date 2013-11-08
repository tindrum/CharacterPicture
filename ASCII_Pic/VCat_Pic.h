//
//  VCat_Pic.h
//  Frame
//
//  Created by D. Henderson on 11/7/13.
//  Copyright (c) 2013 D Henderson. All rights reserved.
//

#ifndef __ASCII_Pic__VCat_Pic__
#define __ASCII_Pic__VCat_Pic__

#include <iostream>
#include "P_Node.h"
#include "Picture.h"
using namespace std;

class VCat_Pic : public P_Node{
private:
    VCat_Pic(const Picture& top, const Picture& bottom);
    
    int height() const;
    int width() const;
    void display(ostream& os, int row, int wd) const;
    Picture reframe(char c, char s, char t);
    
    friend Picture operator&(const Picture& top, const Picture& bottom);
    
public:
    Picture* getPic();
    
private:
    Picture _top, _bottom;
};

#endif /* defined(__ASCII_Pic__VCat_Pic__) */