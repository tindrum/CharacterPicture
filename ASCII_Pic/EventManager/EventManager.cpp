//
//  By Daniel Henderson and Josh Maguregui
// Copyright (c) 2013 Daniel Henderson. All rights reserved.
//


#include <sys/_types/_null.h>
#include <sys/_types.h>
#include "EventManager.h"
#include <iostream>
#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

using namespace std;


EventManager* EventManager::_pManager = NULL;

EventManager *EventManager::getManager() {

    if (EventManager::_pManager == NULL) {
        EventManager::_pManager = new EventManager();
    }
    return EventManager::_pManager;
}

void EventManager::registerForEvent(wchar_t event, EventListener *pL) {
     pListeners[event] = pL;
}

EventManager::~EventManager() {

}

EventManager::EventManager() {
    for (wchar_t i = 0; i < (KEY_MAX); i++){
        pListeners[i] = NULL;
    }

}

void EventManager::run() {
    struct termios old_tio, new_tio;
    wchar_t c;
    // bigEvent = c;
    // get terminal settings for stdin
    tcgetattr(STDIN_FILENO, &old_tio);

    // we want to keep the old setting to restore them at the end
    new_tio = old_tio;

    // disable canonical mode (buffered i/o) and local echo
    new_tio.c_lflag &=(~ICANON & ~ECHO);

    // set the new settings immediately
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);

    //initscr();
    //keypad(stdscr, true);

    do {
        c= getchar();
        if (pListeners[c] != NULL) {
         pListeners[c]->onEvent(c);
        }
        // test to see which number the arrows key generates
//        if ( c >= bigEvent ) {
//            bigEvent = c;
//            cout << "largest event handler number is " << int(bigEvent) << endl;
//        }
        // terminfo not set right, I think, so arrow keys
        // don't generate anything that getchar() can detect.
        // TODO: experiment with terminfo flag k- capability
        // (whatever that may mean. phrase from curses.h)
    }   while(c!='q');

//    // TODO: get to work with unbuffered input from keyboard
//    // using getch() or some other direct keyboard scanner
//    // cout << "Event handler started. Press < or > to scroll\n";
//    // cout << "Press 'q' to quit event loop (and program).\n";
//    // char eventCode = 0;
//    // event loop that listens for keyboard input
//    // uses ncurses.h to getch()
//
//
//    while ( eventCode != 'q' ){
//        // read one fricken char from the terminal!
//        eventCode = getchar();
//        cin >> flush;
//        // cin >> eventCode;
//        // cout << "not quit yet\n";
//            if (pListeners[eventCode] != NULL) {
//                cout << "Event Handler for " << eventCode << " found.\n";
//                // TODO: execute function at pListeners[eventCode];
//                pListeners[(int)eventCode]->onEvent((int)eventCode);
//            }   else {
//                cout << "no-op\n";
//            }
//        // cout << eventCode;
//    }

    // restore the former settings
    tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);
    cout << "\n\nquit pressed\n\n\n";
}
