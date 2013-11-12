//
// Created by Daniel Henderson on 11/11/13.
// Copyright (c) 2013 Daniel Henderson. All rights reserved.
//



#include "Picture.h"

#ifndef __CharacterPicture_H_
#define __CharacterPicture_H_


class CharacterPicture : public Picture {
public:
    CharacterPicture(int w, int h, int nStrings, char** pStrings);

};


#endif //__CharacterPicture_H_
