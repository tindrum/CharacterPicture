//
// Created by Daniel Henderson on 11/14/13.
// Copyright (c) 2013 Daniel Henderson. All rights reserved.
//



#ifndef __VScrollbar_H_
#define __VScrollbar_H_

#include "EventListener.h"
#include <iostream>
#include "P_Node.h"
#include "Picture.h"
#include "HCat_Pic.h"


class VScrollbar : public P_Node, public EventListener {
private:
    friend class Picture;
    friend Picture addScrollbar( const Picture& contentWindow );
    
    int height() const;
    int width() const;
    void display(ostream& os, int row, int wd) const;
    Picture reframe(char c, char s, char t); //
    
    friend Picture operator&(const Picture& contentWindow);
    VScrollbar(const Picture& contentWindow);
    
public:
    Picture* getPic();
    
    
protected:
    
    class MyListener: public EventListener {
    public:
        MyListener(VScrollbar* pSB) { _psb = pSB; };
        void onEvent(int e) { _psb->onEvent(e); }
        VScrollbar* _psb;
    };
    
    void onEvent(int event);
private:
    Picture _contentWindow;
    // this is a "has-a" reference to the String_Pic that this decorator scrolls
    // this class only decorates a String_Pic object, or a class that has a grid of characters that
    // acts just like a String_Pic object (perhaps a mini-spreadsheet or ASCII-Art picture of Snoopy)
};


#endif //__VScrollbar_H_
