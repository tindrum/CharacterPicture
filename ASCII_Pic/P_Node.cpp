//
//  P_Node.cpp
//  ASCII_Pic
//
//  Created by Daniel Henderson on 11/7/13.
//  Copyright (c) 2013 Daniel Henderson. All rights reserved.
//

#include "P_Node.h"

P_Node::P_Node() : _use( 1 ) { }

P_Node::P_Node( P_Node* other ) : _use( 1 ) {  }

P_Node::~P_Node() {  }

int P_Node::max(int m, int n ) const { return m > n ? m : n; }

void P_Node::pad( ostream& os, int x, int y ) {
    for (int i = x; i < y; i++) {
        os << " ";
    }
}

void P_Node::showDebug() const { cout << "P_Node[" << this << ",use:" << _use << "]" << endl; }
