//
//  By Daniel Henderson and Josh Maguregui
// Copyright (c) 2013 Daniel Henderson. All rights reserved.
//


#include <sys/_types/_null.h>
#include <sys/_types.h>
#include "EventManager.h"
#include <iostream>
#include <ncurses.h>

using namespace std;


EventManager* EventManager::_pManager = NULL;

EventManager *EventManager::getManager() {

    if (EventManager::_pManager == NULL) {
        EventManager::_pManager = new EventManager();
    }
    return EventManager::_pManager;
}

void EventManager::registerForEvent(int event, EventListener *pL) {
     pListeners[event] = pL;
}

EventManager::~EventManager() {

}

EventManager::EventManager() {
    for (int i = 0; i < KEY_MAX; i++){
        pListeners[i] = NULL;
    }

}

void EventManager::run() {
    // TODO: get to work with unbuffered input from keyboard
    // using getch() or some other direct keyboard scanner
    cout << "Event handler started. Press < or > to scroll\n";
    cout << "Press 'q' to quit event loop (and program).\n";
    char eventCode = 0;
    // event loop that listens for keyboard input
    // uses ncurses.h to getch()
    while ( eventCode != 'q' ){
        // read one fricken char from the terminal!
        eventCode = getchar();
        cin >> flush;
        // cin >> eventCode;
        // cout << "not quit yet\n";
            if (pListeners[eventCode] != NULL) {
                cout << "Event Handler for " << eventCode << " found.\n";
                // TODO: execute function at pListeners[eventCode];
                pListeners[(int)eventCode]->onEvent((int)eventCode);
            }   else {
                cout << "no-op\n";
            }
        // cout << eventCode;
    }
    cout << "quit pressed\n\n\n";
}
