//
//  Tenzy.cpp
//  Tenzy
//
//
#include "Tenzy.h"
#include <iostream>

namespace cs31
{
    Tenzy::Tenzy() : mHumanMatchSet(false), mComputerMatchSet(false)
    {}
        
    // set the human player's match value
    // a match value can only be set once during the life of a game
    void Tenzy::setHumanMatchValue( int matchvalue )
    {
        // only accepts match value exactly once
        if (!mHumanMatchSet)
        {
            mHumanMatchSet = true;
            mHuman.setMatchValue( matchvalue );
        }
    }

    // show the current state of the game by printing out the Board
    void Tenzy::display( std::string msg )
    {
        using namespace std;
        std::string s = mBoard.display( mHuman.getDieManager(), mComputer.getDieManager() );
        
        if (isGameOver())
        {
            if (determineGameOutcome() == HUMANWONGAME)
            {
                s += "\n\t\tyou won Tenzy!\n";
            }
            else
            {
                s += "\n\t\tyou lost Tenzy!\n";
            }
        }
        else
        {
            // only show the msg parameter if the game is not over
            s += msg;
        }
        cout << s << endl;
    }
    
    // TODO
    // randomly roll the human Player's Dies
    void Tenzy::humanPlay( )
    {
        mHuman.roll();  //roll human dies
    }
    
    // TODO
    // end the human Player's turn by locking all the Dies whose
    // value matches the human Player's desired matchvalue
    void Tenzy::humanEndTurn()
    {
        mHuman.endTurn();   //end turn for human
    }
    
    // set the computer player's match value
    // a match value can only be set once during the life of a game
    void Tenzy::setComputerMatchValue( int matchvalue )
    {
        // only accepts match value exactly once
        if (!mComputerMatchSet)
        {
            mComputerMatchSet = true;
            mComputer.setMatchValue( matchvalue );
        }
    }

    // TODO
    // randomly roll the computer Player's Dies
    void Tenzy::computerPlay( )
    {
        mComputer.roll();   //roll computer dies
    }

    // TODO
    // end the computer Player's turn by locking all the Dies whose
    // value matches the computer Player's desired matchvalue
    void Tenzy::computerEndTurn()
    {
        mComputer.endTurn();    //end computer turn
    }
    
    // TODO
    // what is the current game outcome?
    Tenzy::GAMEOUTCOME  Tenzy::determineGameOutcome( ) const
    {
        GAMEOUTCOME result = GAMEOUTCOME::GAMENOTOVER;     //default game not over
        if (mComputer.countMatchValue() == DieManager::NUMBER)  //over if computer matched all values
            result = GAMEOUTCOME::COMPUTERWONGAME;              //then computer won
        else if (mHuman.countMatchValue() == DieManager::NUMBER) //over if human matched all values
            result = GAMEOUTCOME::HUMANWONGAME;                  //then computer won
        return( result );
    }
    
    // TODO
    // is there a winner?
    bool Tenzy::isGameOver()
    {
        if (determineGameOutcome() == GAMEOUTCOME::GAMENOTOVER) //if game is still being played, bool is false
            return false;
        else
            return( true );                                     //game over then there is a winner, bool true
    }

    // for cheating purposes
    // 10 digits between 1-6 required to set any die
    // cheating will not change a locked die
    bool Tenzy::humanPlay( std::string cheatstring )
    {
        return( mHuman.cheat( cheatstring ) );
    }

    // for cheating purposes
    // 10 digits between 1-6 required to set any die
    // cheating will not change a locked die
    bool Tenzy::computerPlay( std::string cheatstring )
    {
        return( mComputer.cheat( cheatstring ) );
    }

}
