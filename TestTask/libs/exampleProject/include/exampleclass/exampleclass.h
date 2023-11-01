#pragma once
#include <cstdint>
#include <iostream>
#include <stdexcept>




template < typename Type >
class List {
public:
    List(); // default
    List( size_t n, Type data = Type() ); // with parameters

    List( const List& other );// copy
    List(  List&& other );// move
    void operator=(  List& other );// присваиваниe копированием
    void operator=(  List&& other );// присваиваниe переносом


    ~List() {

        std::cout << "destructor for object  " << this << std::endl;
        clean();
    }

    void push_back( const Type& data );
    void push_back( const List< Type >& data );
    void push_back( Type&& data );

    int size()const;
    bool empty();
    Type front();
    Type back();
    void pop_back();
    void pop_front();
    void clean();

    void push_front( const Type& value  );
    void push_front( Type&& value );

    void erase( size_t pos );
    Type* begin();
    Type* end();

    void insert( size_t pos, const Type& value );
    void insert( size_t pos, Type&& value );

    void resize( size_t n );
    void resize( size_t n, const Type& value );
    void resize( size_t n, Type&& value );

    void swap( List& other_list );

    Type& operator[]( size_t index );
    const Type& operator[]( size_t index ) const;

// size_t getSize() {
// return listSize;
// }


private:

    template < typename >
    class Slot {
public:

        Slot( const Type& data = Type(), Slot* ptrNext = nullptr ) : data( data ), ptrNext( ptrNext ) {
        }
        Slot( Type&& data = Type(), Slot* ptrNext = nullptr ) : data( data ), ptrNext( ptrNext ) {
        }

        Slot( const List< Type >& data, Slot* ptrNext = nullptr ) : data( data ), ptrNext( ptrNext ) {
        }


        ~Slot() {
        }
        Slot< Type >* ptrNext;
        // Slot< List< Type > >* l_ptrNext;
        Type data;
        // List< Type > l_data;
    };

    Slot< Type >* firstSlot = nullptr;
    // Slot< List< Type > >* l_firstSlot = nullptr;
    size_t listSize = 0;

    void placeSlot( size_t pos, const Type& value );
    void placeSlot( size_t pos, const List< Type >& value );
    void placeSlot( size_t pos, Type&& value );

    void deleteSlot( size_t pos );
    Type* returnPos( size_t pos );
    void swapValue(  Type& a, Type& b  );

    void plusSize() {
        listSize++;
    }
    void minusSize() {
        listSize--;
    }
};



template < typename Type >
List< Type >::List() {

    std::cout << "default constructor for object  " << this  << std::endl;
    listSize = 0;
    firstSlot = nullptr;
    // l_firstSlot = nullptr;
}

template < typename Type >
List< Type >::List( size_t n, Type data ) {

    listSize = 0;
    firstSlot = nullptr;
    std::cout << "constructor with parameters for object  " << this  << std::endl;
    this->resize( n, data );
}


template < typename Type >
List< Type >::List( const List& other ) {

    std::cout << "copy constructor for object  " << this << std::endl;
    this->listSize = 0;
    this->firstSlot = nullptr;
    int otherSize = other.size();

    for( int i = 0; i < otherSize; i++ ) {

        this->push_back( other[ i ] );
    }
}

template < typename Type >
List< Type >::List( List&& other ) {

    std::cout << "move constructor for object " << this << std::endl;
    this->listSize = other.size();
    this->firstSlot = other.firstSlot;
    other.firstSlot = nullptr;
    other.listSize = 0;
}


template < typename Type >
void List< Type >::operator=(  List& other ) {

    int otherSize = other.size();

    for( int i = 0; i < otherSize; i++ ) {

        this->push_back( other[ i ] );
    }
}

template < typename Type >
void List< Type >::operator=(  List&& other ) {

    this->listSize = other.size();
    this->firstSlot = other.firstSlot;
    other.firstSlot = nullptr;
}
///////////////////////////////////////////////////////////////////////


template < typename Type >
int List< Type >::size() const {
    return listSize;
}

template < typename Type >
void List< Type >::placeSlot( size_t pos, const Type& value ) {

    if( this->listSize == 0 ) {

        firstSlot = new Slot< Type >( value );
    } else {
        if(  pos == 0  ) {

            Slot< Type >* temp = firstSlot; // создаем еще один указатель на первый слот
            firstSlot = new Slot< Type >( value, temp ); // создаем новый первый слот

        } else if( pos == listSize ) {

            Slot< Type >* currentSlot = this->firstSlot; // итерируемся по элементам списка
            while( currentSlot->ptrNext != nullptr ) { // ищем конец списка
                currentSlot = currentSlot->ptrNext;
            }
            currentSlot->ptrNext = new Slot< Type >( value ); // добавляем в конец списка элемент

        } else {

            Slot< Type >* currentSlot = this->firstSlot; // итерируемся по элементам списка
            for( std::size_t counter = 0; counter < pos - 1; counter++ ) { // ищем нужный элемент
                currentSlot = currentSlot->ptrNext;
            }
            Slot< Type >* nSlot = new Slot< Type >( value, currentSlot->ptrNext ); // создаем новый слот
            currentSlot->ptrNext = nSlot; // встраиваем новый слот в список

        }
    }

}


template < typename Type >
void List< Type >::placeSlot( size_t pos, const List< Type >& value ) {

    if( this->listSize == 0 ) {

        firstSlot = new Slot< List< Type > >( value );
    } else {
        if(  pos == 0  ) {

            Slot< List< Type > >* temp = firstSlot; // создаем еще один указатель на первый слот
            firstSlot = new Slot< List< Type > >( value, temp ); // создаем новый первый слот

        } else if( pos == listSize ) {

            Slot< List< Type > >* currentSlot = this->firstSlot; // итерируемся по элементам списка
            while( currentSlot->ptrNext != nullptr ) { // ищем конец списка
                currentSlot = currentSlot->ptrNext;
            }
            currentSlot->ptrNext = new Slot< List< Type > >( value ); // добавляем в конец списка элемент

        } else {

            Slot< List< Type > >* currentSlot = this->firstSlot; // итерируемся по элементам списка
            for( std::size_t counter = 0; counter < pos - 1; counter++ ) { // ищем нужный элемент
                currentSlot = currentSlot->ptrNext;
            }
            Slot< List< Type > >* nSlot = new Slot< List< Type > >( value, currentSlot->ptrNext ); // создаем новый слот
            currentSlot->ptrNext = nSlot; // встраиваем новый слот в список

        }
    }

}


template < typename Type >
void List< Type >::placeSlot( size_t pos, Type&& value ) {

    if( listSize == 0 ) {

        firstSlot = new Slot< Type >( std::move( value ) );
    } else {
        if(  pos == 0  ) {

            Slot< Type >* temp = firstSlot; // создаем еще один указатель на первый слот
            firstSlot = new Slot< Type >( std::move( value ), temp ); // создаем новый первый слот

        } else if( pos == listSize ) {

            Slot< Type >* currentSlot = this->firstSlot; // итерируемся по элементам списка
            while( currentSlot->ptrNext != nullptr ) { // ищем конец списка
                currentSlot = currentSlot->ptrNext;
            }
            currentSlot->ptrNext = new Slot< Type >( std::move( value ) ); // добавляем в конец списка элемент

        } else {

            Slot< Type >* currentSlot = this->firstSlot; // итерируемся по элементам списка
            for( std::size_t counter = 0; counter < pos - 1; counter++ ) { // ищем нужный элемент
                currentSlot = currentSlot->ptrNext;
            }
            Slot< Type >* nSlot = new Slot< Type >( std::move( value ), currentSlot->ptrNext ); // создаем новый слот
            currentSlot->ptrNext = nSlot; // встраиваем новый слот в список

        }
    }

}

template < typename Type >
void List< Type >::deleteSlot( size_t pos ) {

    if( listSize == 1 ) {

        delete firstSlot;
        firstSlot = nullptr;
        minusSize();

    } else if( pos == listSize - 1 ) {
        Slot< Type >* currentSlot = firstSlot;
        for( uint32_t i = 0; i < listSize - 2; i++ ) {
            currentSlot = currentSlot->ptrNext;
        }
        delete currentSlot->ptrNext;
        currentSlot->ptrNext = nullptr;
        minusSize();
    } else if( pos == 0 ) {

        Slot< Type >* temp = firstSlot;
        firstSlot = firstSlot->ptrNext;
        delete temp;
        temp = nullptr;
        minusSize();
    } else {

        Slot< Type >* currentSlot = firstSlot;
        for( std::size_t counter = 0; counter != pos - 1; counter++ ) {
            currentSlot = currentSlot->ptrNext;
        }
        Slot< Type >* temp = currentSlot->ptrNext;
        currentSlot->ptrNext = temp->ptrNext;
        delete temp;
        temp = nullptr;
        minusSize();
    }

}


template < typename Type >
void List< Type >::push_back( const Type& data ) {


    if( listSize == 0 ) { // проверка наличия элементов в списке

        placeSlot( 0, data ); // размещаем новый элемент
    } else {

        placeSlot( listSize, data );
    }

    plusSize();
}

template < typename Type >
void List< Type >::push_back( const List< Type >& data ) {


    if( listSize == 0 ) { // проверка наличия элементов в списке

        placeSlot( 0, data ); // размещаем новый элемент
    } else {

        placeSlot( listSize, data );
    }

    plusSize();
}




template < typename Type >
void List< Type >::push_back( Type&& data ) {

// std::cout << "&& version" << std::endl;

    if( listSize == 0 ) { // проверка наличия элементов в списке

        placeSlot( 0,  std::move( data ) );// размещаем новый элемент
    } else {

        placeSlot( listSize, std::move( data )   );
    }

    plusSize();
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

    if( listSize != 0 ) {

        return *returnPos( 0 );
    }

}


template < typename Type >
Type List< Type >::back() {

    if( listSize != 0 ) {

        if( listSize == 1 ) {
            return *returnPos( 0 );
        } else {

            return *returnPos( listSize - 1 );
        }
    }
}

template < typename Type >
void List< Type >::pop_back() {

    if( listSize != 0 ) {
        deleteSlot( listSize - 1 );
    }

}

template < typename Type >
void List< Type >::pop_front() {

    if( listSize != 0 ) {
        deleteSlot( 0 );
    }


}

template < typename Type >
void List< Type >::clean() {

    while( listSize != 0 ) {
        this->pop_front();
    }
}

template < typename Type >
void List< Type >::push_front( const Type& value ) {

    placeSlot( 0, value );
    plusSize(); // увеличиваем размер списка
}

template < typename Type >
void List< Type >::push_front( Type&& value ) {

    // std::cout << "&& version" << std::endl;

    placeSlot( 0, value );
    plusSize(); // увеличиваем размер списка
}

template < typename Type >
void List< Type >::erase( size_t pos ) {


    if( listSize != 0 ) {
        if( pos >= listSize ) {

            throw std::runtime_error( "this position is out of range" ); // need to check

        } else {

            deleteSlot( pos );
        }
    }
}

template < typename Type >
Type* List< Type >::returnPos( size_t pos ) {

    if( pos == 0 ) {
        return &( firstSlot->data );
    } else if( pos == listSize - 1 ) {

        Slot< Type >* currentSlot = this->firstSlot;
        while( currentSlot->ptrNext != nullptr ) {
            currentSlot = currentSlot->ptrNext;
        }

        return &( currentSlot->data );
    }
}


template < typename Type >
Type* List< Type >::begin() {

    if( listSize != 0 ) {

        return returnPos( 0 );
    }

}

template < typename Type >
Type* List< Type >::end() {

    if( listSize != 0 ) {

        if( listSize == 1 ) {

            return returnPos( 0 );

        } else {

            return returnPos( listSize - 1 );
        }
    }
}

template < typename Type >
void List< Type >::insert( std::size_t pos, const Type& value ) {

    if( pos > listSize ) {

        throw std::runtime_error( "this position is out of range" );

    } else {

        placeSlot( pos, value );
        plusSize();
    }
}

template < typename Type >
void List< Type >::insert( std::size_t pos, Type&& value ) {

    if( pos > listSize ) {

        throw std::runtime_error( "this position is out of range" );

    } else {

        placeSlot( pos, value );
        plusSize();
    }
}

template < typename Type >
void List< Type >::resize( size_t n ) {

    if( n == 0 ) {

        clean();

    } else if( n > listSize ) {

        while( n != listSize ) {

            Type data = Type();
            push_back( data );
        }
    } else if( n < listSize ) {
        while( n != listSize ) {
            pop_back();
        }
    }
}

template < typename Type >
void List< Type >::resize( size_t n, const Type& value ) {

    if( n < listSize ) {

        while( n != listSize ) {
            pop_back();
        }
    } else {

        while( n != listSize ) {

            push_back( value );
        }
    }
}

template < typename Type >
void List< Type >::resize( size_t n, Type&& value ) {

    if( n < listSize ) {

        while( n != listSize ) {
            pop_back();
        }
    } else {

        while( n != listSize ) {

            push_back( value );
        }
    }
}

template < typename Type >
const Type&  List< Type >::operator[]( size_t index ) const {

    if( listSize == 0 ) {

        throw std::runtime_error( "list is empty" ); // need to check

    } else if( index >= listSize ) {

        throw std::runtime_error( "this position is out of range" ); // need to check

    } else {

        Slot< Type >* currentSlot = this->firstSlot;
        for( std::size_t i = 0; i < index; i++ ) {
            currentSlot = currentSlot->ptrNext;
        }
        return currentSlot->data;

    }

}

template < typename Type >
Type&  List< Type >::operator[]( size_t index ) {

    if( listSize == 0 ) {

        throw std::runtime_error( "list is empty" ); // need to check

    } else if( index >= listSize ) {

        throw std::runtime_error( "this position is out of range" ); // need to check

    } else {

        Slot< Type >* currentSlot = this->firstSlot;
        for( std::size_t i = 0; i < index; i++ ) {
            currentSlot = currentSlot->ptrNext;
        }
        return currentSlot->data;

    }

}

template < typename Type >
void unique( List< Type >& list ) {

    size_t lSize = list.size();

    if( lSize > 1 ) {

        for( size_t newN = 0; newN < lSize - 1; newN++ ) {
            for( size_t oldN = newN + 1; oldN < lSize;) {

                if( list[ oldN ] == list[ newN ] ) {
                    list.erase( oldN );
                    lSize--;

                } else {
                    oldN++;
                }

            }
        }

    }


}

template < typename Type >
void List< Type >::swapValue( Type& a, Type& b ) {

    Type tempValue = a;
    a = b;
    b = tempValue;
}

template < typename Type >
void List< Type >::swap( List& other_list ) {

    size_t mySize = this->listSize;
    size_t otherSize = other_list.size();
    if( mySize > otherSize ) {

        other_list.resize( mySize );
        for( size_t i = 0; i < mySize; i++ ) {

            swapValue( this->operator[]( i ), other_list[ i ] );
        }
        this->resize( otherSize );

    } else if( mySize < otherSize ) {

        resize( otherSize );
        for( size_t i = 0; i < mySize; i++ ) {

            swapValue( this->operator[]( i ), other_list[ i ] );
        }
        other_list.resize( mySize );

    } else if( mySize == otherSize ) {


        for( size_t i = 0; i < mySize; i++ ) {

            swapValue( this->operator[]( i ), other_list[ i ] );
        }

    }
}



template < typename Type >
class ListWrap {

public:

    ListWrap(  List< Type > alist ) : oneList{ std::move( alist ) } {
    }
    void showList() {

        std::cout << "list: ";
        for( size_t i = 0; i < this->oneList.size(); i++ ) {

            std::cout << oneList[ i ] << " ";
        }
        std::cout << std::endl;
    }
private:

    List< Type > oneList;
};
