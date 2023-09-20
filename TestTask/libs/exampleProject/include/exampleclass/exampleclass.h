#pragma once
#include <cstdint>
#include <typeinfo>
#include <stdexcept>

template < typename Type >
class List {
public:
    List();
    ~List() {
        clean();
    }


    void push_back( Type data );
    int size();
    bool empty();
    Type front();
    Type back();
    void pop_back();
    void pop_front();
    void clean();
    void push_front( Type value );
    void erase( size_t pos );
    Type* begin();
    Type* end();



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
    } else {

        Slot< Type >* currentSlot = this->firstSlot;
        while( currentSlot->ptrNext != nullptr ) {
            currentSlot = currentSlot->ptrNext;
        }
        return currentSlot->data;
    }

}

template < typename Type >
void List< Type >::pop_back() {

    if( listSize == 0 ) {

        throw std::runtime_error( "list is empty" ); // need to check

    }

    if( listSize == 1 ) {

        delete firstSlot;
        firstSlot = nullptr;
        listSize--;

    }

    if( listSize > 1 ) {

        Slot< Type >* currentSlot = firstSlot;
        for( uint32_t i = 0; i < listSize - 2; i++ ) {
            currentSlot = currentSlot->ptrNext;
        }
        delete currentSlot->ptrNext;
        currentSlot->ptrNext = nullptr;
        listSize--;
    }

}

template < typename Type >
void List< Type >::pop_front() {

    if( listSize == 0 ) {

        throw std::runtime_error( "list is empty" ); // need to check

    }

    if( listSize == 1 ) {

        delete firstSlot;
        firstSlot = nullptr;
        listSize--;

    }
    if( listSize > 1 ) {
        Slot< Type >* temp = firstSlot;
        firstSlot = firstSlot->ptrNext;
        delete temp;
        temp = nullptr;
        listSize--;
    }

}

template < typename Type >
void List< Type >::clean() {

    while( listSize != 0 ) {
        this->pop_front();
    }
}

template < typename Type >
void List< Type >::push_front( Type value ) {

    if( firstSlot == nullptr ) {
        firstSlot = new Slot< Type >( value );
    }   else {
        Slot< Type >* temp = firstSlot;
        firstSlot = new Slot< Type >( value, temp );

    }
    listSize++;
}

template < typename Type >
void List< Type >::erase( size_t pos ) {

    if( listSize == 0 ) {

        throw std::runtime_error( "list is empty" ); // need to check

    }
    if( pos > listSize ) {

        throw std::runtime_error( "this position is out of range" ); // need to check

    }
    if( pos == 0 ) {

        throw std::runtime_error( "did you mean 1st position" ); // need to check

    }

    if( pos == 1 ) {
        pop_front();
    } else if( pos == listSize ) {
        pop_back();
    } else {
        Slot< Type >* currentSlot = firstSlot; // или this->firstSlot?
        for( std::size_t counter = 1; counter != pos - 1; counter++ ) {
            currentSlot = currentSlot->ptrNext;
        }
        Slot< Type >* temp = currentSlot->ptrNext;
        currentSlot->ptrNext = temp->ptrNext;
        delete temp;
        temp = nullptr;
        listSize--;
    }
}

template < typename Type >
Type* List< Type >::begin() {

    if( listSize == 0 ) {

        throw std::runtime_error( "list is empty" ); // need to check
    }
    Type* dataptr = &( firstSlot->data );
    return dataptr;


}

template < typename Type >
Type* List< Type >::end() {

    if( listSize == 0 ) {

        throw std::runtime_error( "list is empty" ); // need to check
    }
    if( listSize == 1 ) {

        Type* dataptr = &( firstSlot->data );
        return dataptr;
    } else   {
        Slot< Type >* currentSlot = this->firstSlot;
        while( currentSlot->ptrNext != nullptr ) {
            currentSlot = currentSlot->ptrNext;
        }
        Type* dataptr = &( currentSlot->data );
        return dataptr;
    }
}

