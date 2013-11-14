//
//  By Daniel Henderson and Josh Maguregui
// Copyright (c) 2013 Daniel Henderson. All rights reserved.
//


#include "HScrollbar.h"
#include "EventManager.h"
#include "Picture.h"
#include <curses.h>
#include <iostream>
using namespace std;

HScrollbar::HScrollbar( const Picture& contWin )
: P_Node(), _contentWindow(contWin) {
    EventManager* pMgr = EventManager::getManager();

    pMgr->registerForEvent(KEY_LEFT, this);
    pMgr->registerForEvent(KEY_RIGHT, this);

}

int HScrollbar::height() const {
    return 3;
    // TODO: remove border from top of scrollbar pane and return 2 instead
}

int HScrollbar::width() const {
    return ( _contentWindow.width() );
}


void HScrollbar::onEvent(int event){
    switch(event) {
        case KEY_LEFT: // left arrow on keyboard
            cout << "scroll left one\n";
            break;
        case KEY_RIGHT:  // right arrow on keyboard
            cout << "scroll right one\n";
            break;
        default:
            break;
    }
}

void HScrollbar::display(ostream &os, int row, int wd) const {
    os << "|<- scroll bar ->|\n";

}

Picture* HScrollbar::getPic() {
    return &_contentWindow;
}

Picture HScrollbar::reframe(char c, char s, char t) {
    return new HScrollbar( ::reframe( _contentWindow, c, s, t));
}

