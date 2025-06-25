//  main.cpp
//  Tenzy

#include <iostream>
#include <cassert>
#include "Die.h"
#include "Player.h"
#include "Board.h"
#include "Tenzy.h"

void clearScreen( );

int main()
{    
    using namespace cs31;
    using namespace std;
    
    clearScreen();
    
    Tenzy game;
    int matchvalue;
    
    // get an opening position for both players
    game.humanPlay();
    game.computerPlay();
    
    // set the match value for both players
    std::string message = "pick desired match value: ";
    // display( game, message );
    game.display( message );
    cin >> matchvalue;
    game.setHumanMatchValue( matchvalue );
    game.setComputerMatchValue( matchvalue );
    
    // lock the existing matches from the first round of play
    game.humanEndTurn();
    game.computerEndTurn();
    

    
    std::string action;
    message = "(r)oll (q)uit: ";
    game.display( message );

    // let each Player roll until the game is finally over
    do
    {
        getline( cin, action );
        while (action.size() == 0)
        {
            getline( cin, action );  // no blank entries allowed....
        }
        switch (action[0])
        {
            default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
            case 'Q':
            case 'q':
                return 0;
            case 'r':
            case 'R':
                // the human player always goes first
                game.humanPlay();
                game.humanEndTurn();
                if (!game.isGameOver())
                {
                    game.computerPlay();
                    game.computerEndTurn();
                }
                game.display( message );
                break;
        }
        
    } while( !game.isGameOver() );
    
    Die d;
    int value;
    bool answer;
    d.roll();
    value = d.getValue();
    answer = (value >= 1 && value <= 6);    //reason: test value is between 1 and 6
  
    Die a;
    
    Player p;
    p.cheat("3636366666" );
    p.getDieManager();
    p.setMatchValue( 2 );
    assert( p.getMatchValue() == 2 );
    assert( p.countMatchValue() == 0 );
    p.setMatchValue( 3 );
    p.endTurn();
    assert(p.getDieManager().isLocked(0));
    assert(!(p.getDieManager().isLocked(1)));
    assert( p.getMatchValue() == 3 );
    assert( p.countMatchValue() == 3 );
    assert(p.getDieManager().getValue(0) == 3 );
    assert(p.getDieManager().getValue(2) == 3 );
    assert(p.getDieManager().getValue(4) == 3 );
    assert(p.getDieManager().getValue(1) == 6 );
    assert(p.getDieManager().getValue(3) == 6 );
    assert(p.getDieManager().getValue(5) == 6 );
    assert(p.getDieManager().getValue(6) == 6 );
    assert(p.getDieManager().getValue(7) == 6 );
    assert(p.getDieManager().getValue(8) == 6 );
    assert(p.getDieManager().getValue(9) == 6 );
    
    Player w;
    Tenzy game2;
    game2.setHumanMatchValue( 1 );
    w.cheat("1111111111");
    w.getDieManager();
    answer = ( game2.isGameOver() );
    answer = answer && ( game2.determineGameOutcome() == Tenzy::GAMEOUTCOME::HUMANWONGAME );
    
    Tenzy game3;
    game3.setHumanMatchValue( 2 );
    game3.setComputerMatchValue( 2 );
    game3.humanPlay( "1111111111" );
    game3.humanEndTurn();
    answer = ( game3.isGameOver() );
    answer = answer && ( game3.determineGameOutcome() == Tenzy::GAMEOUTCOME::GAMENOTOVER );
    game3.computerPlay( "2222222222");
    game3.computerEndTurn();
    answer = answer && ( game3.determineGameOutcome() == Tenzy::GAMEOUTCOME::COMPUTERWONGAME );
    
    
    return( 0 );
}



///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                               &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif

