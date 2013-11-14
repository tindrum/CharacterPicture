CharacterPicture
================

CPSC 121 Fall 2013 Group Assignment Two

Daniel Henderson and Josh Maguregui
2013 Nov. 7

Working on the event loop. The only decorator that takes an event is HScrollbar.
Right now, it can register its events '<' and '>', which is good. Actually scrolling isn't finished.

I'd like to have unbuffered input, though.
That way, users can push the arrows on the keyboard and 'KEY_LEFT' and 'KEY_RIGHT' would be the events.
These keys are defined in curses.h, but I can't get curses or ncurses 'getch()' function to compile.
/me is doing it wrong.



