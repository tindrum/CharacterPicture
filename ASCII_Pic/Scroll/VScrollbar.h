//
// Created by Daniel Henderson on 11/14/13.
// Copyright (c) 2013 Daniel Henderson. All rights reserved.
//



#include "P_Node.h"
#include "EventListener.h"
#include "EventManager.h"

#ifndef __VScrollbar_H_
#define __VScrollbar_H_


class VScrollbar : public P_Node, public EventListener {
private:
    friend class Picture;
    friend class ScrollContainer;

    friend Picture addVScrollbar( const Picture& scrollContainer );

    int height() const;
    int width() const;
    void display(ostream& os, int row, int wd) const;
    Picture reframe(char c, char s, char t); //

    friend Picture operator&(const Picture& scrollContainer);
    VScrollbar(const Picture& scrollContainer);

public:
    Picture* getPic();


protected:
    EventManager* pMgr;

    class MyListener: public EventListener {
    public:
        MyListener(VScrollbar* pSB) { _psb = pSB; };
        void onEvent(wchar_t e) { _psb->onEvent(e); }
        VScrollbar* _psb;
    };

    void onEvent(wchar_t event);
private:
    Picture _scrollContainer;
    // this is a "has-a" reference to a ScrollContainer that this decorator scrolls
    // this class only decorates a ScrollContainer object
};




#endif //__VScrollbar_H_
