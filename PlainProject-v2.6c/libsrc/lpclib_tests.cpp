#include "lpclib.h"
#include "lexicon.h"
#include "scanner.h"
#include <map>
using namespace std;

typedef void (*FnPtr)();
static map<string, FnPtr> _examples;

static void GraphicsExample()
{
    GraphicsWindow(500, 500, "black");
    char buf[50];
    DrawCircle(35, 35, 30, "red");
    DrawCircle(95, 35, 30, "red", true);
    
    DrawEllipse(200, 35, 60, 30, "cyan");
    DrawEllipse(320, 35, 60, 30, "cyan", true);
    
    DrawRectangle(400, 20, 30, 30, "yellow", true);
    DrawTriangle(450, 50, 470, 20, 490, 50, "white", true);
    
    DrawImage("bunny.bmp", 200, 100);
    
    DisplayImage("bunny.bmp", 300, 300);
    
    DrawString("Testing graphics - click to draw", 15, 70, "white", 24);
    
    UpdateDisplay();
    
    int x = -1;
    int y = -1;
    
    while (1)
    {
        WaitForMouseDown();
        DrawRectangle(15, 95, 100, 25, "black", true);
        sprintf(buf, "(%i, %i)", MouseX(), MouseY());
        DrawString(string(buf), 15, 95, "white", 24);
        if (x == -1)
        {
            x = MouseX();
            y = MouseY();
        }
        else
        {
            int newx = MouseX();
            int newy = MouseY();
            DrawLine(x, y, newx, newy, "green");
            x = newx;
            y = newy;
        }
        UpdateDisplay();
    }
}

static void MouseExample()
{
    GraphicsWindow(500, 500, "black");
    cout << "Click the mouse up and down 5 times.\n";
    int n = 0;
    while (n < 5)
    {
        WaitForMouseDown();
        printf("Down at (%i, %i). ", MouseX(), MouseY());
        fflush(stdout);
        WaitForMouseUp();
        printf("Up at (%i, %i). Clicks: %i\n", MouseX(), MouseY(), ++n);
    }
    cout << "Hold mouse button down to reverse ball motion\n";
    double x = 8;
    double y = GetHeight() - 8;
    double vy = -15;
    while (x > 7 && x < GetWidth() - 7)
    {
        DrawCircle(x, y, 7, "black", true);

        if (MouseIsDown())
            x -= 3;
        else
            x += 3;
        

        if ((y+vy) > GetHeight())
        {
            vy = -vy;
            vy *= 0.9;
        }
        y += vy;
        vy += 0.7;
        
        DrawCircle(x, y, 7, "white", true);
        DrawCircle(x, y, 7, "green");
        Pause(0.1);
    }
    cout << "--- mouse example done. ---\n";
}

static void KeyExample()
{
    GraphicsWindow(300, 100, "white");
    DrawString("Press any key (Q to quit).", 5, 5, "black", 24);
    UpdateDisplay();
    while (1)
    {
        char key = toupper(GetChar());
        string str = string("You pressed: ") + key;
        DrawRectangle(5, 30, 300, 50, "white", true);
        DrawString(str, 5, 30, "black", 24);
        UpdateDisplay();
        if (key == 'Q')
            break;
    }
    CloseGraphicsWindow();
}

static void FindWord (string sofar, string rest, Lexicon * lex)
{
    if (! lex->containsPrefix(sofar))
        return;
    if (lex->containsWord(sofar))
        cout << sofar << endl;
    for (int i = 0; i < rest.length(); i++)
        FindWord(sofar + rest[i], rest.substr(0, i) + rest.substr(i+1), lex);
}

static void LexiconExample()
{
    Lexicon lex("lexicon.dat");
    cout << "Checking some words...\n";
    cout << "cat: " << (lex.containsWord("cat") ? "Yes" : "No") << endl;
    cout << "cab: " << (lex.containsWord("cab") ? "Yes" : "No") << endl;
    cout << "tac: " << (lex.containsWord("tac") ? "Yes" : "No") << endl;
    cout << "\n";
    cout << "Enter a word or phrase: ";
    string text = GetLine();
    cout << "Words found with that:\n";
    FindWord("", text, &lex);
}

static void ScannerExample()
{
    ifstream infile;
    infile.open("story.txt");
    if (!infile)
        Error ("Could not open the file 'story.txt'");
    
    Scanner s;
    cout << "-- Scanning story.txt with options set to defaults --\n";
    s.setInput(infile);
    
    while (s.hasMoreTokens())
    {
        cout << "Token: " << s.nextToken() << endl;
    }
    
    cout << "-- Scanning story.txt with spaces skipped, quotes scanned as --\n";
    cout << "-- whole strings, and numbers scanned as reals               --\n";
    
    s.setStringOption(Scanner::ScanQuotesAsStrings);
    s.setSpaceOption(Scanner::IgnoreSpaces);
    s.setNumberOption(Scanner::ScanNumbersAsReals);
    
    s.setInput(infile);
    
    while (s.hasMoreTokens())
    {
        cout << "Token: " << s.nextToken() << endl;
    }
}

static void SetupExamples()
{
    if (_examples.size() == 0)
    {
        _examples["graphics"] = GraphicsExample;
        _examples["mouse"] = MouseExample;
        _examples["lexicon"] = LexiconExample;
        _examples["scanner"] = ScannerExample;
        _examples["key"] = KeyExample;
    }
}

void ShowExample(string topic)
{
    SetupExamples();
    map<string, FnPtr>::iterator it = _examples.find(topic);
    if (it == _examples.end())
    {
        cerr << "** There is no example for the topic '" <<  topic << "'\n";
        cerr << "** Topics available:\n";
        for (it = _examples.begin(); it != _examples.end(); it++)
        {
            cout << "     " << it->first << endl;
        }
        Error("ShowExample() must be called with one of the topics above.");
    }
    (it->second)();
}
