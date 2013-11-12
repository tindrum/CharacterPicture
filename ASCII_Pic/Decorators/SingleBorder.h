//
// Created by Ed on 11/11/13.
// Copyright (c) 2013 Daniel Henderson. All rights reserved.
//



#include "BorderDecorator.h"
#include "VisualItem.h"

#ifndef __SingleBorder_H_
#define __SingleBorder_H_

class SingleBorder : public BorderDecorator {
public:
    SingleBorder( char border, VisualItem * pvi );
    SingleBorder( char border, const BorderDecorator& bd);
    SingleBorder( char border, const SingleBorder& bd);

    virtual void draw() const;
    virtual BorderDecorator* clone() const;

private:
    char _border;
};

#endif //__SingleBorder_H_
