//
//  By Daniel Henderson and Josh Maguregui
// Copyright (c) 2013 Daniel Henderson. All rights reserved.
//



#include "EventListener.h"
#include <ncurses.h>
#include <iostream>
#include <string>



#ifndef __EventManager_H_
#define __EventManager_H_


class EventManager {
public:
    static EventManager* getManager();

    void registerForEvent(int event, EventListener* pL);
    void run();

private:
    EventManager();
    ~EventManager();

    EventListener* pListeners[KEY_MAX];
    static EventManager* _pManager;

};


#endif //__EventManager_H_
