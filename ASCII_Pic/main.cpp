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
//             -x <x-offset>     offset from the left of the windowed area of text
//             -y <y-offset>     offset from the top of the windowed area of text
//  [optional] -s <string>       quoted text string with dashes for each desired newline
//                               Each desired line must end with a dash:
//                               "Print each-line followed-by a-dash or the-last line-won't show up-"
//                               Notice the final dash.
//                                                     ( if not given, defaults to built-in text strings,
//                                                       if -s switch is used, string must be provided    )
//  TODO: implement file reading
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
#include "VCat_Pic.h"
#include "HCat_Pic.h"
#include "BorderDecorator.h"
#import "SingleBorder.h"
#include "CharacterPicture.h"

#include <iostream>
#include <unistd.h>

using namespace std;

const char* init[] = { "Paris", "in the", "Spring" };
const char* joju[] = { "London", "is best", "when Christmas", "comes to call" };
const char* knkv[] = { "Fidling", "with a program", "until it appears to work", "is a reliable way", "of obtaining a program", " that almost works."};

void doTest1(int nStrings, char** stringsPArray) {
    VisualItem* pVI = new CharacterPicture( -1,-1, nStrings, stringsPArray);

    //pVI->draw();

}

void doTest2 (int nStrings, char** stringsPArray) {
    CharacterPicture* pCP = new CharacterPicture( -1,-1, nStrings, stringsPArray);
    {
        const BorderDecorator &bd = SingleBorder('@', pCP);
        bd.draw();
        //const BorderDecorator &bd2 = SingleBorder('&', bd);
        //bd2.draw();
    }
    pCP->release();
    cout << "Done!\n";
}

void doTest() {
    const Picture &pic = Picture(init, 3);
    const Picture &fpic = frame(pic);

    Picture rke(knkv, 6);
    const Picture &frke = frame(rke);

    Picture qjd(joju, 4);
    const Picture &fqjd = frame(qjd);

    cout << fpic << endl;
    const Picture &re_fpic = reframe(fpic, 'o', '!', '~');
    cout << re_fpic << endl;

    cout << fqjd << endl;
    const Picture &re_fqjd = reframe(fqjd, '$', '@', '=');
    cout << re_fqjd << endl;

    cout << frke << endl;

    const Picture &left_right = re_fpic | re_fqjd;

    const Picture &top_bottom = frke & re_fqjd;
    cout << top_bottom << endl;

    const Picture &tblr = top_bottom | left_right;
    cout << tblr << endl;

    const Picture &ftblr = frame(tblr);
    cout << ftblr << endl;

    const Picture &ftblr_paris = ftblr & re_fpic;
    const Picture &f_ftblr_paris = frame(ftblr_paris);
    cout << f_ftblr_paris << endl;
}


int main(int argc, char * argv[])
{
    //  begin getopt section
    //  getting parameters from the command line with getopt
    //
    int hflag = 0;
    char *hvalue;
    int wflag = 0;
    char *wvalue;
    int xflag = 0;
    char *xvalue;
    int yflag = 0;
    char *yvalue;
    char *svalue = NULL;
    char *fvalue = NULL;
    int index;
    int c;
    
    opterr = 0;
    
    while (( c = getopt (argc, argv, "h::w::x::y::s:f:")) != -1 )
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
                // wvalue = "";
            }
            break;
        case 'x':
            if (optarg) {
                xflag = 1;
                xvalue = optarg;
            } else {
                xflag = 0;
                // xvalue = "";
            }
            break;
        case 'y':
            if (optarg) {
                yflag = 1;
                yvalue = optarg;
            } else {
                yflag = 0;
                // yvalue = "";
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
    
    
/*      // Example of dynamic string
    int mylen = strlen(argv[0]);
    char * astring = char[100]; // This will go out of scope later.. if it's in a function.
    char * dynamicString = new char[mylen+1];

    strcpy(dynamicString,argv[0]);
    cout << "This is my new string " << dynamicString << endl; 
*/

    
    
    //  end getopt section
    int idx = 0;
    int nStrings = argc-optind;

    char ** myStrings = new char*[argc-optind];
    for (int x=optind;x<argc;x++) {
        myStrings[idx++] = argv[x];
    }



    //  Verbatim text from class assignment
    if (svalue || fvalue ) {
        if (svalue ) {      // passed a string on the command line
            const Picture &ed = Picture( svalue );
            cout << ed;
            const Picture &fed = frame(ed);
            cout << fed;
            const Picture &hfed = ed | fed;
            cout << hfed;
            const Picture &re_fed = reframe(fed, '#', '|', '_');
            cout << hfed;
            cout << re_fed;
        }   else {
            // passed a file
        }
    }
        else
    {
        //doTest();
        doTest1( nStrings, myStrings );
        doTest2( nStrings, myStrings );

    }
    // end verbatim text from class assignment


    cout << "...done." << endl;
    
    return 0;
}

