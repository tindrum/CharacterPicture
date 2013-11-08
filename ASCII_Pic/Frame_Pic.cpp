//
//  Frame_Pic.cpp
//  ASCII_Pic
//
//  Created by Daniel Henderson on 11/7/13.
//  Copyright (c) 2013 Daniel Henderson. All rights reserved.
//

#include "Frame_Pic.h"
#include "Picture.h"

Frame_Pic::Frame_Pic(const Picture& other) : P_Node(), _pic(other){
    
}

Frame_Pic::Frame_Pic(const Picture& pic, char c, char s, char t) : _pic(pic), _corner(c), _sideborder(s), _topborder(t){
    
}
int Frame_Pic::height() const{
    return _pic.height() + 2;
}

int Frame_Pic::width() const{
    return _pic.width() + 2;
}

void Frame_Pic::display(ostream& os, int row, int wd) const{
    if(row < 0 || row >=height()){
        pad(os,0,wd);
    }
    else{
        if(row == 0 || row >= height() - 1){
            os << _corner;
            int i = _pic.width();
            while(--i >= 0){
                os << _topborder;
            }
            os << '+';
        }
        else{
            os << _sideborder;
            _pic.display(os, row -1, _pic.width());
            os << _sideborder;
        }
        pad(os,width(), wd);
    }
}

Picture Frame_Pic::reframe(char c, char s, char t ){
    return new Frame_Pic( ::reframe(_pic, c, s, t), c, s, t);
}

Picture* Frame_Pic::getPic(){
    return &_pic;
}

void Frame_Pic::showDebug() const{
    cout << "Frame_Pic{" << this << ",_pic:";
    _pic.showDebug();
    cout << "]" << endl;
}