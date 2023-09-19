#pragma once
#include <cstdint>
#include <typeinfo>

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

    return firstSlot->data;

}

template < typename Type >
Type List< Type >::back() {
    if( firstSlot == nullptr ) {
        return firstSlot->data;
    } else   {

        Slot< Type >* currentSlot = this->firstSlot;
        while( currentSlot->ptrNext != nullptr ) {
            currentSlot = currentSlot->ptrNext;
        }
        return currentSlot->data;
    }

}
