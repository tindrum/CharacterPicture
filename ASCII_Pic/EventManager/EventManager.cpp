//
// Created by Ed on 11/11/13.
// Copyright (c) 2013 Daniel Henderson. All rights reserved.
//


#include <sys/_types/_null.h>
#include <sys/_types.h>
#include "EventManager.h"

EventManager *EventManager::getManager() {

    if (_pManager == NULL) {
        _pManager = new EventManager();
    }

    return _pManager;
}

void EventManager::registerForEvent(int event, EventListener *pL) {

}

EventManager::~EventManager() {

}

EventManager::EventManager() {

}

void EventManager::run() {

}
