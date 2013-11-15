//
//  By Daniel Henderson and Josh Maguregui
// Copyright (c) 2013 Daniel Henderson. All rights reserved.
//


#include "HScrollbar.h"
#include "EventManager.h"
#include "Picture.h"
#include <ncurses.h>
#include <iostream>
using namespace std;

HScrollbar::HScrollbar( const Picture& contWin )
: P_Node(), _contentWindow(contWin) {
    EventManager* pMgr = EventManager::getManager();

    pMgr->registerForEvent((int)'<', this);  // TODO: get to work with KEY_LEFT
    pMgr->registerForEvent((int)'>', this);  // TODO: get to work with KEY_RIGHT

}

int HScrollbar::height() const {
    return _contentWindow.height() + 2;
    // TODO: remove border from top of scrollbar pane and return 2 instead
}

int HScrollbar::width() const {
    return ( _contentWindow.width() );
}


void HScrollbar::onEvent(int event){
    char eventChar = (char)event;
    switch(eventChar) {
        case '<': // left arrow on keyboard
       // case KEY_LEFT: // left arrow on keyboard
            cout << "scroll left one\n";
            break;
        case '>':  // right arrow on keyboard
        // case KEY_RIGHT:  // right arrow on keyboard
            cout << "scroll right one\n";
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

