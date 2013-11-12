//
// Created by Ed on 11/11/13.
// Copyright (c) 2013 Daniel Henderson. All rights reserved.
//

#include "VisualItem.h"

#ifndef __BorderDecorator_H_
#define __BorderDecorator_H_


class BorderDecorator {
public:
    virtual void draw() const;
    BorderDecorator( VisualItem* pvi );
    BorderDecorator ( const BorderDecorator& rBD );

    ~BorderDecorator() { if (_pvi) { _pvi->release();} }
protected:

    virtual BorderDecorator* clone() const;
    VisualItem* _pvi;
    BorderDecorator* _pbd;
};


#endif //__BorderDecorator_H_
