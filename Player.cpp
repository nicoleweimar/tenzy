//
//  Player.cpp
//  Tenzy
//
//

#include "Player.h"

namespace cs31
{
    
    Player::Player() : mMatchValue( 0 )  // match value not set
    {}
    
    // randomly toss all of this Player's Dies
    void Player::roll( )
    {
        mManager.roll();    //roll players die
    }
    
    // TODO - done
    // trivial setter
    void Player::setMatchValue( int matchvalue )
    {
        mMatchValue = matchvalue;   //set matchvalue
    }

    // TODO
    // trivial getter
    int  Player::getMatchValue( ) const
    {
        return( mMatchValue );
    }

    // TODO
    // how many of this Player's Dies hold the desired Match Value?
    int  Player::countMatchValue( ) const
    {
        return(mManager.count(mMatchValue));
    }

    // TODO
    // at the end of a turn, lock all of this Player's Dies that hold
    // the desired Match Value
    void Player::endTurn()
    {
        mManager.lock(mMatchValue);
    }
    
    // for display purposes and called by Board to show the current
    // state of the game
    DieManager Player::getDieManager() const
    {
        return( mManager );
    }

    // cheat by forcing values into this Player's Dies
    // the string should have the format:   nnnnnnnnnn
    // with each n being a digit character between 1-6
    // cheating will not change a locked Die
    bool Player::cheat( std::string cheatstring )
    {
        // there must be exactly 10 digits for any cheating to take place
        bool result = false;
        int  count = 0;
        for (size_t i = 0; i < cheatstring.size(); i++)
        {
            char c = cheatstring.at( i );
            // convert to int
            int value = c - '0';
            if (value >= 1 && value <= 6)
            {
                count++;
            }
        }
        if (count == DieManager::NUMBER)
        {
            int number = 0;
            result = true;
            for (size_t i = 0; i < cheatstring.size(); i++)
            {
                char c = cheatstring.at( i );
                // convert to int
                int value = c - '0';
                if (value >= 1 && value <= 6)
                {
                    mManager.setValue( number, value );
                    number++;
                }
            }
        }
        return( result );
    }


}
