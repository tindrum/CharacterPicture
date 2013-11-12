//
// Created by Ed on 11/11/13.
// Copyright (c) 2013 Daniel Henderson. All rights reserved.
//

#include <curses.h>


#ifndef __EventListener_H_
#define __EventListener_H_


class EventListener {
public:
    virtual void onEvent(int event) = 0;

};


#endif //__EventListener_H_
