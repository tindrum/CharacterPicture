//
//  Picture.cpp
//  ASCII_Pic
//
//  By Daniel Henderson and Josh Maguregui
//  11/7/13.
//


#include "Picture.h"
#include "String_Pic.h"
#include "Frame_Pic.h"
#include "P_Node.h"
#include "HScrollbar.h"
#include "VCat_Pic.h"
#include <iostream>
#include <regex>
#include <regex.h>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <regex>



using namespace std;

Picture::Picture(P_Node* pnode) : _pnode(pnode){
    pnode->_use++;
}

Picture::Picture(const char* const * pLines, int nLines) : _pnode( new String_Pic(pLines, nLines)){
    
}

Picture::Picture ( char* phrase ) {
    char* pch;
    int dashCount = 0;
    for (int j = 0; j < strlen(phrase); j++){
        if (phrase[j] == '-' ) {
            dashCount++;
        }

    }


//
//    http://www.cplusplus.com/reference/cstring/strtok/
//    {
//        char str[] ="- This, a sample string.";
//        char * pch;
//        printf ("Splitting string \"%s\" into tokens:\n",str);
//        pch = strtok (str," ,.-");
//        while (pch != NULL)
//        {
//            printf ("%s\n",pch);
//            pch = strtok (NULL, " ,.-");
//        }
//        return 0;
//    }
//

    // TODO: fix that it needs a newline at the end of every line
    //       this might be the way strtok works, though
    char** sap = new char*[dashCount];
    pch = strtok(phrase, "-");
    int c = 0;
    while (pch != NULL)
    {
        sap[c++] = pch;
        pch = strtok(NULL, "-");
    }

    _pnode = ( new String_Pic(sap, dashCount)) ;
    
    delete sap;
}





Picture::Picture(const Picture& other) : _pnode(other._pnode){
    other._pnode->_use++;
}

Picture::~Picture(){
    if(--_pnode->_use == 0){
        delete _pnode;
    }
}

Picture& Picture::operator=(const Picture& other){
    other._pnode->_use++;
    if(--_pnode->_use ==0){
        delete _pnode;
    }
    
    _pnode = other._pnode;
    
    return *this;
}

Picture frame(const Picture& pic){
    return new Frame_Pic(pic._pnode, '+', '|', '-');
}

Picture reframe(const Picture& pic, char c, char s, char t){
    return pic._pnode->reframe(c,s,t);
}

Picture addScrollbar(const Picture& pic){
    return new HScrollbar(pic._pnode);
}

int Picture::height() const{
    return _pnode->height();
}
int Picture::width() const {
    return _pnode->width();
}

void Picture::display(ostream& os, int x, int y) const{
    _pnode->display(os,x,y);
}

ostream& operator<<(ostream& os, const Picture& pic){
    int ht = pic.height();
    for(int i = 0; i < ht; i++) {
        pic.display(os,i,0);
        os << endl;
    }
    return os;
}

void Picture::showDebug() const{
    P_Node* pn = _pnode;
    Picture* pic;
    while((pic=pn->getPic()) != NULL){
        cout << "---> ";
        pic->showDebug();
        pn = pic->_pnode;
    }
    cout << "]" << endl;
}

