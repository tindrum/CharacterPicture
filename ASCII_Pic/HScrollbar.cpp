//
// Created by Ed on 11/11/13.
// Copyright (c) 2013 Daniel Henderson. All rights reserved.
//


#include "HScrollbar.h"
#include "EventManager.h"
#include <curses.h>

HScrollbar::HScrollbar( const Picture& contWin )
: P_Node(), _contentWindow(contWin) {
    EventManager* pMgr = EventManager::getManager();

    pMgr->registerForEvent(34, this);
    pMgr->registerForEvent(40, this);
}

void HScrollbar::onEvent(int event) {
    switch(event) {
        case 34:
            break;
        case 40:
            break;
        default:
            break;
    }
}
