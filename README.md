CharacterPicture
================

CPSC 121 Fall 2013 Group Assignment Two

Daniel Henderson and Josh Maguregui
2013 Nov. 7

Getting HScrollbar decorator to display correctly.

Next: give it a width and x-offset, and have it display that sub-section of the parent info.
Might restrict it to only decorating a String_Pic object at first.

Next Next: make a similar VScrollbar decorator. 
This might require a decorator between the H- and V- scrollbars and the parent object, just to act as a frame for them
both, or it might not. Probably will, though, since I don't want to scroll the HScrollbar as part of the 
VScrollbar functionality, or vice versa. Passing the scrolling through a ScrollPane object would eliminate this.
Would need to use Singleton to only allow one H- or V- scrollbar per pane. *already have a singleton on EventHandler
=======
Working on the event loop. The only decorator that takes an event is HScrollbar.
Right now, it can register its events '<' and '>', which is good. Actually scrolling isn't finished.

I'd like to have unbuffered input, though.
That way, users can push the arrows on the keyboard and 'KEY_LEFT' and 'KEY_RIGHT' would be the events.
These keys are defined in curses.h, but I can't get curses or ncurses 'getch()' function to compile.
/me is doing it wrong.

