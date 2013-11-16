//
//  By Daniel Henderson and Josh Maguregui
// Copyright (c) 2013 Daniel Henderson. All rights reserved.
//


#include "HScrollbar.h"
#include "EventManager.h"
#include "Picture.h"
#include <ncurses.h>
#include <curses.h>
#include <iostream>
using namespace std;

const wchar_t SCRLL = '<';
const wchar_t SCRLR = '>';
const wchar_t IPUSH = 'i';

//const wchar_t SCRLL = KEY_LEFT;
//const wchar_t SCRLR = KEY_RIGHT;


HScrollbar::HScrollbar( const Picture& contWin )
: P_Node(), _contentWindow(contWin) {
    EventManager* pMgr = EventManager::getManager();

    pMgr->registerForEvent(SCRLL, this);  // TODO: get to work with KEY_LEFT
    pMgr->registerForEvent(SCRLR, this);  // TODO: get to work with KEY_RIGHT
    pMgr->registerForEvent(IPUSH, this);

}

int HScrollbar::height() const {
    return _contentWindow.height() + 2;
    // TODO: remove border from top of scrollbar pane and return 2 instead
}

int HScrollbar::width() const {
    return ( _contentWindow.width() );
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
    if (row <= _contentWindow.height()) {
        _contentWindow.display(os, row, wd);
    } else if ( row > ( _contentWindow.height()   ))
    {
         if ( row == _contentWindow.height() +0 ) // TODO: draw plain dashed line AND <-HASH-> line
        {
            for (int i = 0; i < (_contentWindow.width()); i++) {
                os << "-";
            }
        } else if ( row == _contentWindow.height() +1 ) {
            os << "<-";
            for (int i = 0; i < (_contentWindow.width() -4); i++) {
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
    return &_contentWindow;
}

Picture HScrollbar::reframe(char c, char s, char t) {
    return new HScrollbar( ::reframe( _contentWindow, c, s, t));
}

