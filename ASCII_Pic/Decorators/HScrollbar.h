//
// Created by Ed on 11/11/13.
// Copyright (c) 2013 Daniel Henderson. All rights reserved.
//



#include "BorderDecorator.h"
#include "EventListener.h"
#include "VisualItem.h"

#ifndef __HScrollbar_H_
#define __HScrollbar_H_



class HScrollbar : public BorderDecorator,public EventListener {

public:
    HScrollbar(BorderDecorator& rd);
    HScrollbar(VisualItem& ve);

    void draw();
    void someOtherFuntion();

protected:
    class MyListener: public EventListener {
    public:
        MyListener(HScrollbar* pSB) { _psb = pSB; };
        void onEvent(int e) { _psb->onEvent(e); }
        HScrollbar* _psb;
    };

    void onEvent(int event);
};


#endif //__HScrollbar_H_
