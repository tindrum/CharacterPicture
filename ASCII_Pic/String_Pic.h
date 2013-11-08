//
//  String_Pic.h
//  ASCII_Pic
//
//  Created by Daniel Henderson on 11/7/13.
//  Copyright (c) 2013 Daniel Henderson. All rights reserved.
//

#ifndef __ASCII_Pic__String_Pic__
#define __ASCII_Pic__String_Pic__

#include <iostream>

using namespace std;

#include "P_Node.h"
#include "Picture.h"

class String_Pic : public P_Node {
private:
    friend Picture  frame( const Picture& picture );
    
    String_Pic( const char* const* pLines, int nLines );
    ~String_Pic();
    
    int      height() const;
    int      width()  const;
    void     display( ostream& os, int x, int y ) const;
    Picture  reframe( char c, char s, char t );
    
public:
    void showDebug() const;
    Picture* getPic();
    
    char**  _data;
    int     _size;
    
};



#endif /* defined(__ASCII_Pic__String_Pic__) */
