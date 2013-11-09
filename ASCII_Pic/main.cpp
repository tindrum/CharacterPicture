//
//  main.cpp
//  ASCII_Pic
//
//  By Daniel Henderson and Josh Maguregui
//  11/7/13.
//
//  ***********************************************
//  Command line arguments:
//  [optional] -h <height>       height of text window ( default value: number of lines in input text )
//  [optional] -w <width>        width of text window  ( default value: twelve or so )
//  [optional] -s <string>       quoted text string with embedded newlines
//                                                     ( if not given, defaults to built-in text strings,
//                                                       if -s switch is used, string must be provided    )
//  [optional] -f <file>         file name to use. If used, file name must be given.
//                                                     ( postfix parsing of single-char operators
//                                                       and B[xxxx] special bordering lines in file
//                                                       to be added later )
//                               If -f is used, other options are ignored.
//                               Special syntax within files:
//                                 First line must contain a string of more than one character
//                                 that doesn't start with the characters
//                                 |, &, ^, +, <, >, #,
//                                 the pattern B[xxxx] (x being any single-space ascii character),
//

#include <iostream>
#include <ctype.h>
#include "Picture.h"
#include <iostream>
#include <unistd.h>

using namespace std;

const char* init[] = { "Paris", "in the", "Spring" };
const char* joju[] = { "London", "is best", "when Christmas", "comes to call" };
const char* knkv[] = { "Fidling", "with a program", "until it appears to work", "is a reliable way", "of obtaining a program", " that almost works."};

int main(int argc, char * argv[])
{
    //  begin getopt section
    //  getting parameters from the command line with getopt
    //
    int hflag = 0;
    char *hvalue;
    int wflag = 0;
    char *wvalue;
    char *svalue = NULL;
    char *fvalue = NULL;
    int index;
    int c;
    
    opterr = 0;
    
    while (( c = getopt (argc, argv, "h::w::s:f:")) != -1 )
        switch (c)
    {
        case 'h':
            if (optarg) {
                hflag = 1;
                hvalue = optarg;
            } else {
                hflag = 0;
                // hvalue = "";
            }
            break;
        case 'w':
            if (optarg) {
                wflag = 1;
                wvalue = optarg;
            } else {
                wflag = 0;
                // hvalue = "";
            }
            break;
        case 's':
            svalue = optarg;
            break;
        case 'f':
            fvalue = optarg;
            break;
            case '?':
            if (optopt == 's')
                fprintf(stderr, "Option -%c requires an argument.\n", optopt);
            else if (optopt == 'f')
                fprintf(stderr, "Option -%c requires an argument.\n", optopt);
            else if (isprint(optopt))
                fprintf(stderr, "Unknown option `-%c'.\n", optopt);
            else
                fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
            return 1;
        default:
            abort ();
    }
    
    
    
    
    
    
    
    //  end getopt section
    
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

