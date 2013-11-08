//
//  P_Node.h
//  Frame
//
//  By Daniel Henderson and Josh Maguregui
//  11/7/13.
//

#ifndef __ASCII_Pic__P_Node__
#define __ASCII_Pic__P_Node__

#include <iostream>
#include "Picture.h"
using namespace std;

class P_Node{
protected:
    P_Node();
    P_Node(P_Node* other);
    virtual ~P_Node();
    virtual int height() const = 0;
    virtual int width() const = 0;
    virtual void display(ostream& os, int x, int y) const = 0;
    
public:
    virtual Picture reframe(char c, char s, char t) = 0;
    friend Picture reframe(const Picture& p, char c, char s, char t);
    
protected:
    int max(int m, int n) const;
    static void pad(ostream& os, int x, int y);
    
public:
    void showDebug() const;
    virtual Picture* getPic() = 0;
    
private:
    friend class Picture;
    friend class String_Pic;
    
    int _use;
    int _height;
    int _width;
    
};
#endif /* defined(__ASCII_Pic__P_Node__) */