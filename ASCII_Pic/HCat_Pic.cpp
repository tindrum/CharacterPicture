//
//  HCat_Pic.cpp
//  ASCII_Pic
//
//  Created by Daniel Henderson on 11/7/13.
//  Copyright (c) 2013 Daniel Henderson. All rights reserved.
//

#include "HCat_Pic.h"
#include "Picture.h"

HCat_Pic::HCat_Pic( const Picture& left, const Picture& right )
: P_Node(), _left( left ), _right( right ) {  }

Picture operator|( const Picture& left, const Picture& right ) {
    return new HCat_Pic( left._pnode, right._pnode );
}

int HCat_Pic::height() const { return max( _left.height(), _right.height() ); }
int HCat_Pic::width() const { return _left.width() + _right.width(); }

void HCat_Pic::display( ostream& os, int row, int wd ) const {
    _left.display( os, row, _left.width() );
    _right.display( os, row, _right.width() );
    pad( os, width(), wd );
}

Picture HCat_Pic::refram( char c, char s, char t ) {
    return new HCat_Pic(
                        reframe( _left, c, s, t ),
                        reframe( _right, c, s, t) );
}

Picture* HCat_Pic::getPic() { return &_left; }