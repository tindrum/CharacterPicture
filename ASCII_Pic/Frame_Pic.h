//
//  Frame_Pic.h
//  ASCII_Pic
//
//  By Daniel Henderson and Josh Maguregui
//  11/7/13.
//

#ifndef __ASCII_Pic__Frame_Pic__
#define __ASCII_Pic__Frame_Pic__

#include <iostream>
#include "P_Node.h"
#include "Picture.h"
#include "EventListener.h"

using namespace std;

class Frame_Pic : public P_Node{
private:
    friend Picture frame(const Picture& picture);
    
    Frame_Pic(const Picture& pic, char c = '+', char s = '|', char t = '-');
    Frame_Pic(const Picture& other);
    
    int height() const;
    int width() const;
    void display(ostream& os, int row, int wd) const;
    Picture reframe(char c, char s, char t);
    
public:
    void showDebug() const;
    Picture* getPic();
    
private:
    Picture _pic;
    char _corner;
    char _sideborder;
    char _topborder;

protected:

    class MyListener: public EventListener {
    public:
        MyListener(P_Node* pPN) { _pfp = pFP; };
        void onEvent(int e) { _psb->onEvent(e); }
        P_Node* _pPN;
    };

    void onEvent(int event);

};
#endif /* defined(__ASCII_Pic__Frame_Pic__) */