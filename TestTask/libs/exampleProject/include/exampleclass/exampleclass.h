#pragma once
#include <cstdint>
#include <typeinfo>

template < typename Type, typename T >
class List {
public:
    List();
    ~List() {
        clean();
    }


    void push_back( T data );


    void datacheck( T data );

    int size();
    bool empty();
    Type front();
    Type back();
    void pop_front();
    void clean();
    void push_front( Type value );
    void pop_back();
    const Type* begin();
    const Type* end();

    const Type& operator[]( const int index ) const;
    const Type& operator[]( const int index );

    void erase( std::size_t pos );
    void insert( std::size_t pos, Type value );
    void unique();

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



template < typename Type, typename T >
List< Type, T >::List() {

    listSize = 0;
    firstSlot = nullptr;
}

template < typename Type, typename T  >
void List< Type >::datacheck( T data ) {

// if( typeid( data ) != typeid( this->firstSlot->data ) ) {
// throw  "list and data have different types";
// }

    if( T != Type ) {
        throw  "list and data have different types";
    }

}



template < typename Type, typename T  >
void List< Type >::push_back( T data ) {


    this->datacheck();
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
int List< Type >::size() {
    return listSize;
}

template < typename Type >
Type List< Type >::front() {
    return firstSlot->data;
}

template < typename Type >
Type List< Type >::back() {
    if( firstSlot == nullptr ) {
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
void List< Type >::pop_front() {

    Slot< Type >* temp = firstSlot;
    firstSlot = firstSlot->ptrNext;
    delete temp;
    temp = nullptr;
    listSize--;

}

template < typename Type >
void List< Type >::clean() {

    while( listSize != 0 ) {
        this->pop_front();
    }
}

template < typename Type >
void List< Type >::push_front( Type value ) {

    Slot< Type >* temp = firstSlot;
    firstSlot = new Slot< Type >( value, temp );
    listSize++;

}

template < typename Type >
void List< Type >::pop_back() {

    Slot< Type >* currentSlot = firstSlot;
    for( uint32_t i = 1; i < listSize - 1; i++ ) {
        currentSlot = currentSlot->ptrNext;
    }
    delete currentSlot->ptrNext;
    currentSlot->ptrNext = nullptr;
    listSize--;
}

template < typename Type >
const Type*  List< Type >::begin() {

    Type* dataptr = &( firstSlot->data );
    return dataptr;
}

template < typename Type >
const Type*  List< Type >::end() {

    Slot< Type >* currentSlot = this->firstSlot;
    while( currentSlot->ptrNext != nullptr ) {
        currentSlot = currentSlot->ptrNext;
    }
    Type* dataptr = &( currentSlot->data );
    return dataptr;
}

template < typename Type >
const Type& List< Type >::operator[]( const int index ) {

    uint32_t counter = 1;
    Slot< Type >* currentSlot = this->firstSlot;
    while( currentSlot != nullptr ) {
        if( counter == ( index ) ) {
            return currentSlot->data;

        } else {
            currentSlot = currentSlot->ptrNext;
            counter++;
        }
    }
    // throw (smth)
}

template < typename Type >
void List< Type >::erase( std::size_t pos ) {

    Slot< Type >* currentSlot = this->firstSlot;
    for( std::size_t counter = 0; counter < pos; counter++ )
        if( counter == ( pos - 1 ) ) {
            Slot< Type >* temp = currentSlot->ptrNext;
            currentSlot->ptrNext = temp->ptrNext;
            delete temp;
            temp = nullptr;
            listSize--;
        } else {
            currentSlot = currentSlot->ptrNext;
            counter++;
        }
}

template < typename Type >
void List< Type >::insert( std::size_t pos, Type value ) {

    Slot< Type >* currentSlot = this->firstSlot;
    for( std::size_t counter = 1; counter < pos - 1; counter++ ) {
        currentSlot = currentSlot->ptrNext;
    }
    Slot< Type >* nSlot = new Slot< Type >( value, currentSlot->ptrNext );
    currentSlot->ptrNext = nSlot;
    listSize++;
}

template < typename Type >
void List< Type >::unique() {

    Slot< Type >* currentSlot = this->firstSlot;
    while( currentSlot->ptrNext != nullptr ) {
        currentSlot = currentSlot->ptrNext;
    }
    // currentSlot->ptrNext = new Slot< Type >( data );

}





