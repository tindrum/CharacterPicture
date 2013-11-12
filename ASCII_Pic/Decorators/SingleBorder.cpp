//
// Created by Ed on 11/11/13.
// Copyright (c) 2013 Daniel Henderson. All rights reserved.
//


#include "SingleBorder.h"
#include "VisualItem.h"
#include <iostream>

using namespace std;

SingleBorder::SingleBorder(char border, VisualItem* pvi) : BorderDecorator( pvi ) {
    _border = border;

}

SingleBorder::SingleBorder(char border, const BorderDecorator& bd) : BorderDecorator( bd ) {
    _border = border;
}

SingleBorder::SingleBorder(char border, const SingleBorder& bd) : BorderDecorator( bd ) {
    _border = border;
}

void SingleBorder::draw() const {
    cout << "SingleBorder.draw() called\n";
    BorderDecorator::draw();
}

BorderDecorator *SingleBorder::clone() const {
    return new SingleBorder(_border,*this);
}
