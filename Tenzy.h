//
//  Tenzy.h
//  Tenzy
//
//

#ifndef Tenzy_h
#define Tenzy_h

#include <string>
#include "Player.h"
#include "Board.h"

// CS 31 Students need to complete the methods marked with TODO
// url of online game:  https://www.playonlinedicegames.com/tenzy
namespace cs31
{
    // A Tenzy game has two Players and a Board
    class Tenzy
    {
    public:
        Tenzy();
        
        // the outcome possibilities
        enum GAMEOUTCOME { HUMANWONGAME, COMPUTERWONGAME, GAMENOTOVER };
        
        // show the current state of the game by printing out the Board
        void display( std::string msg = "" );
        
        // set the human player's match value
        // a match value can only be set once during the life of a game
        void setHumanMatchValue( int matchvalue );
        // TODO
        // randomly roll the human Player's Dies
        void humanPlay( );
        // for cheating purposes
        // 10 digits between 1-6 required to set any die
        // cheating will not change a locked die
        bool humanPlay( std::string cheatstring );
        // TODO
        // end the human Player's turn by locking all the Dies whose
        // value matches the human Player's desired matchvalue
        void humanEndTurn( );
        
        // set the computer player's match value
        // a match value can only be set once during the life of a game
        void setComputerMatchValue( int matchvalue );
        // TODO
        void computerPlay( );
        // for cheating purposes
        // 10 digits between 1-6 required to set any die
        // cheating will not change a locked die
        bool computerPlay( std::string cheatstring );
        // TODO
        // end the computer Player's turn by locking all the Dies whose
        // value matches the computer Player's desired matchvalue
        void computerEndTurn();
        
        // TODO
        // what is the current game outcome?
        GAMEOUTCOME  determineGameOutcome( ) const;
        // TODO
        // is there a winner?
        bool isGameOver();
        
        
    private:
        Player mHuman;
        Player mComputer;
        Board  mBoard;
        
        // these booleans are used to ensure that a matchValue can only
        // be set once during the lifetime of a Tenzy game
        bool   mHumanMatchSet;
        bool   mComputerMatchSet;
    };
    
}

#endif /* Tenzy_h */
