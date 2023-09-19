#pragma once
#include <cstdint>
#include <typeinfo>

template < typename Type >
class List {
public:
    List();
    ~List() {
    }

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



