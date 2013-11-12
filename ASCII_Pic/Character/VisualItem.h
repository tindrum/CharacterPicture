//
// Created by Ed on 11/11/13.
// Copyright (c) 2013 Daniel Henderson. All rights reserved.
//



#ifndef __VisualItem_H_
#define __VisualItem_H_


class VisualItem {
public:
    virtual void draw() const = 0;
    virtual void release() = 0;
    virtual void retain() = 0;

};


#endif //__VisualItem_H_
