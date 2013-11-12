//
// Created by Ed on 11/11/13.
// Copyright (c) 2013 Daniel Henderson. All rights reserved.
//


#include "BorderDecorator.h"
#include "VisualItem.h"

void BorderDecorator::draw() const {
    if (_pbd) {
        _pbd->draw();
    } else {
        _pvi->draw();
    }
}

BorderDecorator::BorderDecorator(VisualItem*  pvi) : _pvi( pvi ),_pbd(0) {
    _pvi->retain();
}

BorderDecorator::BorderDecorator( const BorderDecorator &rBD) {
    BorderDecorator* pnewBD = rBD.clone();
    _pbd = pnewBD->_pbd;
    _pvi = pnewBD->_pvi;
    return;

    if (rBD._pbd) {
        _pbd = rBD._pbd->clone();
        _pvi = nullptr;
    } else {
        _pbd = nullptr;
        _pvi = rBD._pvi;
        _pvi->retain();
    }
}

BorderDecorator* BorderDecorator::clone() const {
    return new BorderDecorator(_pvi);
}
