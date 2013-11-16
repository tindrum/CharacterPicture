//
// Created by Daniel Henderson on 11/14/13.
// Copyright (c) 2013 Daniel Henderson. All rights reserved.
//



#include "EventManager.h"

#ifndef __ScrollContainer_H_
#define __ScrollContainer_H_


class ScrollContainer : public P_Node {
private:
    friend class Picture;
    friend class HScrollbar;
    friend class VScrollbar;
    friend Picture addHScroll( const Picture& textArea );
    friend Picture addVScroll( const Picture& textArea );

    int height() const;
    int width() const;
    void display(ostream& os, int row, int wd) const;
    Picture reframe(char c, char s, char t); //

    friend Picture operator&(const Picture& textArea);
    Picture addScrollContainer(const Picture& textArea);
    ScrollContainer(const Picture& other);
    ScrollContainer(const Picture& other, int winH, int winW, int winX, int winY );

public:
    Picture* getPic();
    void showDebug() const;


protected:
    EventManager* pMgr;

    class MyListener: public EventListener {
    public:
        MyListener(ScrollContainer* pSB) { _psb = pSB; };
        void onEvent(wchar_t e) { _psb->onEvent(e); }
        ScrollContainer* _psb;
    };

    void onEvent(wchar_t event);

    int _h;
    int _w;
    int _x;
    int _y;

    // getters and setters for ScrollContainer.
    // Kinda breaks encapsulation to have them here,
    // but this project needed to be refactored to
    // include a sub-area to show, so
    // ScrollContainer gets that job.
    void setH( int );
    int getH();
    void setW( int );
    int getW();
    void setX( int );
    int getX();
    void setY( int );
    int getY();

private:
    Picture _textArea;
    // this is a "has-a" reference to a ScrollContainer that this decorator scrolls
    // this class only decorates a ScrollContainer object

};


#endif //__ScrollContainer_H_
