//
//  By Daniel Henderson and Josh Maguregui
// Copyright (c) 2013 Daniel Henderson. All rights reserved.
//


#include "HScrollbar.h"
#include "ScrollContainer.h"
#include "EventManager.h"
#include "Picture.h"
#include <ncurses.h>
#include <curses.h>
#include <iostream>
#include <string>
using namespace std;

const wchar_t SCRLL = '<';
const wchar_t SCRLR = '>';
const wchar_t IPUSH = 'i';

//const wchar_t SCRLL = KEY_LEFT;
//const wchar_t SCRLR = KEY_RIGHT;


HScrollbar::HScrollbar( const Picture& scrollWin  )
: P_Node(), _scrollContainer( scrollWin ) {
    if ( strncmp( typeid(_scrollContainer).name(), "ScrollContainer", 16) ) {
        // already points to the right kind of object
    }   else {
        Picture& tempWin = _scrollContainer;
        _scrollContainer = new ScrollContainer( _scrollContainer );

    }
    EventManager* pMgr = EventManager::getManager();

    pMgr->registerForEvent(SCRLL, this);  // TODO: get to work with KEY_LEFT
    pMgr->registerForEvent(SCRLR, this);  // TODO: get to work with KEY_RIGHT
    pMgr->registerForEvent(IPUSH, this);

    static_cast<ScrollContainer>(_scrollContainer).setH(_scrollContainer.height());
    static_cast<ScrollContainer>(_scrollContainer).setW(_scrollContainer.width());
    static_cast<ScrollContainer>(_scrollContainer).setX(0);
    static_cast<ScrollContainer>(_scrollContainer).setY(0);

}

HScrollbar::HScrollbar( const Picture& scrollWin, int winHeight, int winWidth, int winXoffset, int winYoffset  )
: P_Node(), _scrollContainer( scrollWin ) {
    if ( typeid(_scrollContainer).name() == "ScrollContainer" ) {
        // already points to the right kind of object
    }   else {
        Picture& tempWin = _scrollContainer;
        _scrollContainer = new ScrollContainer( _scrollContainer );

    }
    EventManager* pMgr = EventManager::getManager();

    pMgr->registerForEvent(SCRLL, this);  // TODO: get to work with KEY_LEFT
    pMgr->registerForEvent(SCRLR, this);  // TODO: get to work with KEY_RIGHT
    pMgr->registerForEvent(IPUSH, this);

    static_cast<ScrollContainer>(_scrollContainer).setH(winHeight);
    static_cast<ScrollContainer>(_scrollContainer).setW(winWidth);
    static_cast<ScrollContainer>(_scrollContainer).setX(winXoffset);
    static_cast<ScrollContainer>(_scrollContainer).setY(winYoffset);

}

int HScrollbar::height() const {
    return _scrollContainer.height() + 2;
    // TODO: remove border from top of scrollbar pane and return 2 instead
}

int HScrollbar::width() const {
    return ( _scrollContainer.width() );
}


void HScrollbar::onEvent(wchar_t eventChar){
    switch(eventChar) {
       // case '<': // left arrow on keyboard
       case SCRLL: // left arrow on keyboard
            cout << "scroll left one\n";
            break;
            // case '>':  // right arrow on keyboard
        case SCRLR:  // right arrow on keyboard
            cout << "scroll right one\n";
            break;
            // case '>':  // right arrow on keyboard
        case IPUSH:  // right arrow on keyboard
            cout << "\ni\n";
            break;
        default:
            break;
    }
}

void HScrollbar::display(ostream &os, int row, int wd) const {
    if (row <= _scrollContainer.height()) {
        _scrollContainer.display(os, row, wd);
    } else if ( row > ( _scrollContainer.height()   ))
    {
         if ( row == _scrollContainer.height() +0 ) // TODO: draw plain dashed line AND <-HASH-> line
        {
            for (int i = 0; i < (_scrollContainer.width()); i++) {
                os << "-";
            }
        } else if ( row == _scrollContainer.height() +1 ) {
            os << "<-";
            for (int i = 0; i < (_scrollContainer.width() -4); i++) {
                os << "#";
            }
            os << "->";
        } else {
            cerr << "printing past bottom of object. HScrollbar class.\n";
        }
    }
} // end HScrollbar::display
// TODO: The problem with drawing dashed line and hashed line may stem from
// an extra linefeed somewhere in the last line of the parent node.
// Look at the String_Pic being created by the command-line -s option.
// Try decorating the statically-created String_Pic objects to see if they suffer
// from the same bug. If not, the problem is with Dan's command-line parser,
// which has other problems anyway.
//
// Problem still exists in static-created String_Pics. Need to trace.
// (On the good side, it does properly handle nested-decorated objects
// insofar as the width is concerned.


Picture* HScrollbar::getPic() {
    return &_scrollContainer;
}

Picture HScrollbar::reframe(char c, char s, char t) {
    return new HScrollbar( ::reframe( _scrollContainer, c, s, t));
}

