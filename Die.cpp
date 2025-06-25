//
//  Die.cpp
//  Tenzy
//
//

#include "Die.h"
#include <random>

// CS 31 Students need to complete the methods marked with TODO
namespace cs31
{
    
    Die::Die( int sides ) : mSides( sides ), mValue( 0 ), mLocked( false )
    {

    }
    
    // toss this Die
    void Die::roll()
    {
        if (! isLocked())
        {
            std::random_device rd;
            std::mt19937 e2(rd());
            std::uniform_int_distribution<> dist(1, mSides);
            mValue = dist(e2);
        }
    }
    
    // get the value from the most recent toss
    int  Die::getValue( ) const
    {
        return( mValue );
    }

    //TODO - done
    void Die::lock()
    {
        mLocked = true; //sets bool mLocked to true when function is called
    }

    // TODO - done
    // has this Die been locked?
    bool Die::isLocked() const
    {
        return mLocked; //is locked true if locked, else false
    }

    // cheat by forcing a value into this Die
    bool Die::setValue( int value )
    {
        bool result = false;
        if (!isLocked())
        {
            mValue = value;
            result = true;
        }
        return( result );
    }

}
