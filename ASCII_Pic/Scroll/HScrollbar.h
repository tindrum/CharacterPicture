//
//  By Daniel Henderson and Josh Maguregui
// Copyright (c) 2013 Daniel Henderson. All rights reserved.
//




#ifndef __HScrollbar_H_
#define __HScrollbar_H_

#include "EventListener.h"
#include "EventManager.h"

#include <iostream>
#include "P_Node.h"
#include "Picture.h"
#include "VCat_Pic.h"



class HScrollbar : public P_Node, public EventListener {
private:
    friend class Picture;
    friend class ScrollContainer;

    friend Picture addHScrollbar( const Picture& scrollContainer );

    int height() const;
    int width() const;
    void display(ostream& os, int row, int wd) const;
    Picture reframe(char c, char s, char t); //

    friend Picture operator&(const Picture& scrollContainer);
    HScrollbar(const Picture& scrollContainer);
    HScrollbar( const Picture& scrollWin, int winHeight, int winWidth, int winXoffset, int winYoffset  );

public:
    Picture* getPic();


protected:
    EventManager* pMgr;

    class MyListener: public EventListener {
    public:
        MyListener(HScrollbar* pSB) { _psb = pSB; };
        void onEvent(wchar_t e) { _psb->onEvent(e); }
        HScrollbar* _psb;
    };

    void onEvent(wchar_t event);
private:
    Picture _scrollContainer;
    // this is a "has-a" reference to a ScrollContainer that this decorator scrolls
    // this class only decorates a ScrollContainer object
};


#endif //__HScrollbar_H_
