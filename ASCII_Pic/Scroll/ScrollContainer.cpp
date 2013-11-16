//
// Created by Daniel Henderson on 11/14/13.
// Copyright (c) 2013 Daniel Henderson. All rights reserved.
//


#include "ScrollContainer.h"
#include "P_Node.h"


Picture ScrollContainer::addScrollContainer(const Picture &textArea) {
    return Picture();
}

void ScrollContainer::onEvent(wchar_t event) {

}

ScrollContainer::ScrollContainer(const Picture& other) : P_Node(), _textArea(other){

}

ScrollContainer::ScrollContainer(const Picture& other, int winH, int winW, int winX, int winY )
: P_Node(), _textArea(other), _h(winH), _w(winW), _x(winX), _y(winY) {

}

int ScrollContainer::height() const{
    return _textArea.height() + 2;
}

int ScrollContainer::width() const{
    return _textArea.width() + 2;
}

void ScrollContainer::display(ostream& os, int row, int wd) const{

}


Picture* ScrollContainer::getPic(){
    return &_textArea;
}

void ScrollContainer::showDebug() const{
    cout << "ScrollContainer{" << this << ",_pic: ";
    _textArea.showDebug();
    cout << "]" << endl;
}

void ScrollContainer::setH(int i) {
    _h = i;
}

int ScrollContainer::getH() {
    return _h;
}

void ScrollContainer::setW(int i) {
             _w = i;
}

int ScrollContainer::getW() {
    return _w;
}

void ScrollContainer::setX(int i) {
             _x = i;
}

int ScrollContainer::getX() {
    return _x;
}

void ScrollContainer::setY(int i) {
             _y = i;
}

int ScrollContainer::getY() {
    return _y;
}
