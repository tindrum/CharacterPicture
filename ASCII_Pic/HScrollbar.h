//
// Created by Daniel Henderson on 11/11/13.
// Copyright (c) 2013 Daniel Henderson. All rights reserved.
//




#ifndef __HScrollbar_H_
#define __HScrollbar_H_

#include "EventListener.h"
#include <iostream>
#include "P_Node.h"
#include "Picture.h"
#include "VCat_Pic.h"



class HScrollbar : public P_Node, public EventListener {
private:
    friend class Picture;
    friend Picture addScrollbar( const Picture& contentWindow );

    int height() const;
    int width() const;
    void display(ostream& os, int row, int wd) const;
    Picture reframe(char c, char s, char t); //

    friend Picture operator&(const Picture& contentWindow);
    HScrollbar(const Picture& contentWindow);

public:
    Picture* getPic();


protected:

    class MyListener: public EventListener {
    public:
        MyListener(HScrollbar* pSB) { _psb = pSB; };
        void onEvent(int e) { _psb->onEvent(e); }
        HScrollbar* _psb;
    };

    void onEvent(int event);
private:
    Picture _contentWindow;
    // this is a "has-a" reference to the String_Pic that this decorator scrolls
    // this class only decorates a String_Pic object, or a class that has a grid of characters that
    // acts just like a String_Pic object (perhaps a mini-spreadsheet or ASCII-Art picture of Snoopy)
};


#endif //__HScrollbar_H_
