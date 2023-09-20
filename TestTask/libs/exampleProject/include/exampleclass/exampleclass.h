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
    void push_back();
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
    void insert( size_t pos, Type value );
    void resize( size_t n );
    void resize( size_t n, Type value );
    void swap( List& other_list ); // sxdcfvghbjnmk,l.;/

// Type& operator[]( size_t index );
// const Type& operator[]( size_t index ) const;



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
void List< Type >::push_back() {

    if( firstSlot == nullptr ) {
        firstSlot = new Slot< Type >();
    } else {

        Slot< Type >* currentSlot = this->firstSlot;
        while( currentSlot->ptrNext != nullptr ) {
            currentSlot = currentSlot->ptrNext;
        }
        currentSlot->ptrNext = new Slot< Type >();
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
    if( pos >= listSize ) {

        throw std::runtime_error( "this position is out of range" ); // need to check

    }

    if( pos == 0 ) {
        pop_front();
    } else if( pos == listSize - 1 ) {
        pop_back();
    } else {
        Slot< Type >* currentSlot = firstSlot; // или this->firstSlot?
        for( std::size_t counter = 0; counter != pos - 1; counter++ ) {
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
    // Type* dataptr = &( firstSlot->data );
    return &( firstSlot->data );


}

template < typename Type >
Type* List< Type >::end() {

    if( listSize == 0 ) {

        throw std::runtime_error( "list is empty" ); // need to check
    }
    if( listSize == 1 ) {

        Type* dataptr = &( firstSlot->data );
        return dataptr;
    } else {
        Slot< Type >* currentSlot = this->firstSlot;
        while( currentSlot->ptrNext != nullptr ) {
            currentSlot = currentSlot->ptrNext;
        }
        // Type* dataptr = &( currentSlot->data );
        return &( currentSlot->data );
    }
}

template < typename Type >
void List< Type >::insert( std::size_t pos, Type value ) {


    if(  pos == 0  ) {

        push_front( value );

    } else if( pos == listSize ) {

        push_back( value );

    } else if( pos > listSize ) {

        throw std::runtime_error( "this position is out of range" );

    } else {
        Slot< Type >* currentSlot = this->firstSlot;
        for( std::size_t counter = 0; counter < pos - 1; counter++ ) {
            currentSlot = currentSlot->ptrNext;
        }
        Slot< Type >* nSlot = new Slot< Type >( value, currentSlot->ptrNext );
        currentSlot->ptrNext = nSlot;
        listSize++;
    }
}

template < typename Type >
void List< Type >::swap( List& other_list ) {

    Slot< Type >* temp = this->firstSlot;
    this->firstSlot = other_list->firstSlot;
    other_list->firstSlot = temp;
}

template < typename Type >
void List< Type >::resize( size_t n ) {

    if( n == 0 ) {

        clean();
    } else if( n > listSize ) {

        while( n != listSize ) {

            push_back();
        }
    } else if( n < listSize ) {
        while( n != listSize ) {
            pop_back();
        }
    }
}

template < typename Type >
void List< Type >::resize( size_t n, Type value ) {

    if( n < listSize ) {
        resize( n );
    } else {

        while( n != listSize ) {

            push_back( value );
        }
    }
}

// template < typename Type >
// Type&  List< Type >::operator[]( size_t index ) {

// if( listSize == 0 ) {

// throw std::runtime_error( "list is empty" ); // need to check

// }
// if( index > listSize ) {

// throw std::runtime_error( "this position is out of range" ); // need to check

// }



// size_t counter = 0;
// Slot< Type >* currentSlot = this->firstSlot;
// while( currentSlot != nullptr ) {
// if( counter == ( index ) ) {
// return currentSlot->data;

// } else {
// currentSlot = currentSlot->ptrNext;
// counter++;
// }
// }
// }
