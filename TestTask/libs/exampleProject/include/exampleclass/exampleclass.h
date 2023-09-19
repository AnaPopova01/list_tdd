#pragma once
#include <cstdint>
#include <typeinfo>
#include <stdexcept>

template < typename Type >
class List {
public:
    List();
    ~List() {
    }


    void push_back( Type data );
    int size();
    bool empty();
    Type front();
    Type back();
    void pop_back();


private:

    template < typename >
    class Slot {
public:

        Slot( Type data = Type(), Slot* ptrNext = nullptr ) : data( data ), ptrNext( ptrNext ) {
        }
        ~Slot() {
        }
        Slot< Type >* ptrNext;
        Type data;
    };

    Slot< Type >* firstSlot;
    std::size_t listSize;
};

template < typename Type >
List< Type >::List() {

    listSize = 0;
    firstSlot = nullptr;
}

template < typename Type >
int List< Type >::size() {
    return listSize;
}

template < typename Type >
void List< Type >::push_back( Type data ) {

    if( firstSlot == nullptr ) {
        firstSlot = new Slot< Type >( data );
    } else {

        Slot< Type >* currentSlot = this->firstSlot;
        while( currentSlot->ptrNext != nullptr ) {
            currentSlot = currentSlot->ptrNext;
        }
        currentSlot->ptrNext = new Slot< Type >( data );
    }
    listSize++;

}

template < typename Type >
bool List< Type >::empty() {
    if( listSize == 0 ) {
        return 1;
    } else {
        return 0;
    }
}

template < typename Type >
Type List< Type >::front() {

    if( listSize == 0 ) {

        throw std::runtime_error( "list is empty" ); // need to check
    }
    return firstSlot->data;


}

template < typename Type >
Type List< Type >::back() {

    if( listSize == 0 ) {

        throw std::runtime_error( "list is empty" ); // need to check
    }
    if( listSize == 1 ) {
        return firstSlot->data;
    } else   {

        Slot< Type >* currentSlot = this->firstSlot;
        while( currentSlot->ptrNext != nullptr ) {
            currentSlot = currentSlot->ptrNext;
        }
        return currentSlot->data;
    }

}

// template < typename Type >
// void List< Type >::pop_back() {

// if( firstSlot == nullptr ) {


// Slot< Type >* currentSlot = firstSlot;
// for( uint32_t i = 1; i < listSize - 1; i++ ) {
// currentSlot = currentSlot->ptrNext;
// }
// delete currentSlot->ptrNext;
// currentSlot->ptrNext = nullptr;
// listSize--;
// }
