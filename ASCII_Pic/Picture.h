//
//  Picture.h
//  Frame
//
//  By Daniel Henderson and Josh Maguregui
//  11/7/13.
//

#ifndef __ASCII_Pic__Picture__
#define __ASCII_Pic__Picture__

#include <iostream>
#include "VisualItem.h"

using namespace std;

class P_Node;

class Picture;

Picture frame(const Picture& pic);
Picture reframe(const Picture&, char, char, char);

class Picture : public VisualItem {
public:
    Picture();
    Picture(const char* const *pLines, int nLines);
    Picture( char* phrase );
    
    Picture(const Picture& other);   // copy constructor
    Picture& operator=(const Picture& other);
    
    ~Picture();
    
    friend ostream& operator<<(ostream& os, const Picture& pic);
    friend Picture frame(const Picture& pic);
    friend Picture reframe(const Picture&, char, char, char);
    friend Picture operator&(const Picture& top, const Picture& bottom);
    friend Picture operator|(const Picture& left, const Picture& right);

    virtual void draw() const;
    virtual void release() { if (--_refcnt == 0) {
            delete this;
        }
    }

    virtual void retain() { _refcnt++ ;}
    
private:
    Picture(P_Node* pnode);
    
    friend class String_Pic;
    friend class Frame_Pic;
    friend class HCat_Pic;
    friend class VCat_Pic;
    
    int height() const;
    int width() const;
    void display(ostream& os, int x, int y) const;



public:
    void showDebug() const;
private:
    P_Node* _pnode;
    int _refcnt;
};

#endif /* defined(__ASCII_Pic__Picture__) */