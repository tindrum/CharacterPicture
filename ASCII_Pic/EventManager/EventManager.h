//
// Created by Ed on 11/11/13.
// Copyright (c) 2013 Daniel Henderson. All rights reserved.
//



#include "EventListener.h"
#include <curses.h>


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

    EventListener* pListeners[8];
    static EventManager* _pManager;

};


#endif //__EventManager_H_
