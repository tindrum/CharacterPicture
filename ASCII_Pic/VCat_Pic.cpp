//
//  VCat_Pic.cpp
//  ASCII_Pic
//
//  Created by Daniel Henderson on 11/7/13.
//  Copyright (c) 2013 Daniel Henderson. All rights reserved.
//

#include "Picture.h"
#include "VCat_Pic.h"

VCat_Pic::VCat_Pic( const Picture& top, const Picture& bottom )
: P_Node(), _top( top ), _bottom( bottom ) {  }

Picture operator&( const Picture& top, const Picture& bottom ) {
    return new VCat_Pic( top._pnode, bottom._pnode );
}

int VCat_Pic::height() const { return _top.height() + _bottom.height(); }
int VCat_Pic::width() const { return max( _top.width(), _bottom.width() ); }

void VCat_Pic::display( ostream& os, int row, int wd) const {
    if (row >= 0 && row < _top.height()) {
        _top.display( os, row, wd );
    } else if (row < _top.height() + _bottom.height()) {
        _bottom.display( os, row - _top.height(), wd );
    } else {
        pad( os, 0, wd );
    }
}

Picture VCat_Pic::refram( char c, char s, char t ) {
    return new VCat_Pic(
                        reframe( _top, c, s, t ),
                        reframe( _bottom, c, s, t ) );
}

Picture* VCat_Pic::getPic() {  return &_top; }
