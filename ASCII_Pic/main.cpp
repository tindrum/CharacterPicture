//
//  main.cpp
//  ASCII_Pic
//
//  Created by Daniel Henderson on 11/7/13.
//  Copyright (c) 2013 Daniel Henderson. All rights reserved.
//

#include <iostream>
#include "Picture.h"
#include <iostream>
using namespace std;

const char* init[] = { "Paris", "in the", "Spring" };
const char* joju[] = { "London", "is best", "when Christmas", "comes to call" };
const char* knkv[] = { "Fidling", "with a program", "until it appears to work", "is a reliable way", "of obtaining a program", " that almost works."};

int main(int argc, const char * argv[])
{
    const Picture&  pic = Picture ( init, 3);
    const Picture& fpic = frame( pic );
    
    Picture rke(knkv, 6);
    const Picture&  frke = frame( rke );
    
    Picture qjd( joju, 4);
    const Picture&  fqjd = frame ( qjd );
    
    cout << fpic << endl;
    const Picture&  re_fpic = reframe( fpic, 'o', '!', '~' );
    cout << re_fpic << endl;
    
    cout << fqjd << endl;
    const Picture& re_fqjd = reframe( fqjd, '$', '@', '=');
    cout << re_fqjd << endl;
    
    cout << frke << endl;
    
    const Picture&  left_right = re_fpic | re_fqjd;
    
    const Picture&  top_bottom = frke & re_fqjd;
    cout << top_bottom << endl;
    
    const Picture& tblr = top_bottom | left_right;
    cout << tblr << endl;
    
    const Picture& ftblr = frame( tblr );
    cout << ftblr << endl;
    
    const Picture&  ftblr_paris = ftblr & re_fpic;
    const Picture& f_ftblr_paris = frame( ftblr_paris );
    cout << f_ftblr_paris << endl;
    
    cout << "...done." << endl;
    
    return 0;
}

