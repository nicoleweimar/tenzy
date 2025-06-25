//
//  DieManager.cpp
//  Tenzy
//
//

#include "DieManager.h"
#include <stdexcept>

// CS 31 Students need to complete the methods marked with TODO
namespace cs31
{

DieManager::DieManager() {}

// TODO - done
// randomly roll all the Dies stored in this DieManager
void DieManager::roll()
{
    for(int i = 0; i < NUMBER ;i++){
        if (!mDice[i].isLocked())   //not locked then roll die
            mDice[i].roll();
    } //loops through all die
}

// TODO - done
// how many Dies have the desired match value?
int  DieManager::count( int matchValue ) const
{
    int result = 0;     //initialize result to 0
    for(int i = 0; i < NUMBER ;i++){
        if (mDice[i].getValue() == matchValue)  //if value is match then count it as a match
            result++;
    }
    return( result );   //return how many matched die
}

// TODO - done
// lock all the Dies in this DieManager that have the desired
// match value and return how many Dies were locked by this call
int  DieManager::lock( int matchValue )
{
    int result = 0;
    for(int i = 0; i < NUMBER ;i++){
        if (!mDice[i].isLocked() && mDice[i].getValue() == matchValue){
            result++;   //if the die is not locked and has the matchvalue, lock it and add it to
                        //number locked in this turn
            mDice[i].lock();
        }
    }
    return( result );   //return how many locked die
}

// return the value of the Die specified by its dieNumber
// which would be 0-DieManager::NUMBER-1
// If the dieNumber is out of range, throw a logic_error instead
int  DieManager::getValue( int dieNumber ) const
{
    if (dieNumber >= NUMBER || dieNumber < 0)
        throw std::logic_error( "bad dieNumber passed to DieManager::getValue" );
    return( mDice[ dieNumber ].getValue() );
}

// is the Die currently locked as specified by its dieNumber
// which would be 0-DieManager::NUMBER-1
// If the dieNumber is out of range, throw a logic_error instead
bool DieManager::isLocked( int dieNumber ) const
{
    if (dieNumber >= NUMBER || dieNumber < 0)
        throw std::logic_error( "bad dieNumber passed to DieManager::isLocked" );
    return( mDice[ dieNumber ].isLocked() );
}

// cheat by forcing a value into a particular Die as specified by its
// dieNumber which would be 0-DieManager::NUMBER-1
// If the dieNumber is out of range, throw a logic_error instead
void DieManager::setValue( int dieNumber, int value )
{
    if (dieNumber >= NUMBER || dieNumber < 0)
        throw std::logic_error( "bad dieNumber passed to DieManager::setValue" );

    mDice[ dieNumber ].setValue(value);
}

}
