#include <gtest/gtest.h>
#include "exampleclass/exampleclass.h"


TEST( ListTests, creating ) {
    List< int > list;
}

TEST( ListTests, push_back_AND_size ) {

    List< int > list;
    ASSERT_EQ( 0, list.size() );

    list.push_back( 7 );
    list.push_back( 8 );

    // std::cout << "adress of 8 is " << &list[ 1 ] << std::endl;
    int value = 5;
    list.push_back( value );
    ASSERT_EQ( 3, list.size() );

    // list.push_back( "hi" );

}

TEST( ListTests, empty ) {

    List< int > list;
    ASSERT_EQ( 1, list.empty() );

    list.push_back( 7 );
    list.push_back( 'a' );
    ASSERT_EQ( 0, list.empty() );

}

TEST( ListTests, front ) {

    List< char > list;


    list.front();




    list.push_back( 'a' );
    ASSERT_EQ( 'a', list.front() );
    list.push_back( 'b' );
    list.push_back( 'c' );
    ASSERT_EQ( 'a', list.front() );

}

TEST( ListTests, back ) {

    List< char > list;

    list.back();


    list.push_back( 'a' );
    ASSERT_EQ( 'a', list.back() );
    list.push_back( 'b' );
    list.push_back( 'c' );
    ASSERT_EQ( 'c', list.back() );

}

TEST( ListTests, pop_back ) {

    List< char > list;
    list.pop_back();

    list.push_back( 'a' );
    list.pop_back();
    ASSERT_EQ( 0, list.size() );

    list.push_back( 'a' );
    list.push_back( 'b' );
    list.push_back( 'c' );
    list.pop_back();
    ASSERT_EQ( 2, list.size() );
    ASSERT_EQ( 'b', list.back() );


}

TEST( ListTests, pop_front ) {

    List< char > list;

    list.pop_front();


    list.push_back( 'a' );
    list.pop_front();
    ASSERT_EQ( 0, list.size() );

    list.push_back( 'a' );
    list.push_back( 'b' );
    list.push_back( 'c' );
    list.pop_front();
    ASSERT_EQ( 2, list.size() );
    ASSERT_EQ( 'b', list.front() );


}

TEST( ListTests, clear ) {

    List< int > list;
    list.clean();
    ASSERT_EQ( 0, list.size() );

    list.push_back( 7 );
    list.push_back( 8 );
    list.clean();
    ASSERT_EQ( 0, list.size() );

}

TEST( ListTests, push_front ) {

    List< char > list;
    list.push_front( 'a' );
    ASSERT_EQ( 1, list.size() );
    ASSERT_EQ( 'a', list.front() );
    list.push_front( 'b' );
    list.push_front( 'c' );
    ASSERT_EQ( 'c', list.front() );
    ASSERT_EQ( 'a', list.back() );
    ASSERT_EQ( 3, list.size() );

}

TEST( ListTests, erase ) {

    List< char > list;


    list.erase( 0 );



    list.push_back( 'a' );
    list.erase( 0 );
    ASSERT_EQ( 0, list.size() );

    list.push_back( 'a' );
    list.push_back( 'b' );
    list.push_back( 'c' );
    list.push_back( 'd' );
    list.push_back( 'e' );
    list.erase( 4 );
    list.erase( 0 );
    list.erase( 1 );
    ASSERT_EQ( 2, list.size() );
    ASSERT_EQ( 'b', list.front() );
    ASSERT_EQ( 'd', list.back() );

    try {

        list.erase( 5 );

    } catch( std::runtime_error& e ) {

        ASSERT_STREQ( e.what(), "this position is out of range" );
        // std::cerr << e.what() << std::endl;

    }
}

TEST( ListTests, begin ) {

    List< char > list;

    list.begin();



    list.push_back( 'a' );
    list.push_back( 'b' );
    list.push_back( 'c' );
    char* myptr = list.begin();
    *myptr = 'g';

    ASSERT_EQ( 'g', list.front() );
    *myptr = 7;
    ASSERT_EQ( 7, list.front() );

}

TEST( ListTests, end ) {

    List< char > list;

    char* firstptr = list.end();



    list.push_back( 'a' );
    char* myptr = list.end();
    *myptr = 'g';
    ASSERT_EQ( 'g', list.back() );

    list.push_back( 'b' );
    list.push_back( 'c' );
    myptr = list.end();
    *myptr = 'z';
    ASSERT_EQ( 'z', list.back() );

}

TEST( ListTests, insert ) {

    List< char > list;

    try {
        list.insert( 5, 'a' );

    } catch( std::runtime_error& e ) {

        ASSERT_STREQ( e.what(), "this position is out of range" );
        // std::cerr << e.what() << std::endl;

    }

    list.insert( 0, 'g' );
    ASSERT_EQ( 'g', list.front() );
    list.pop_front();

    list.push_back( 'a' );
    list.insert( 1, 'b' );
    ASSERT_EQ( 2, list.size() );

    list.push_back( 'd' );
    list.insert( 2, 'c' );
    ASSERT_EQ( 4, list.size() );
    list.pop_back();
    ASSERT_EQ( 'c', list.back() );

    list.insert( 3, 'z' );
    ASSERT_EQ( 4, list.size() );



}

TEST( ListTests, resize ) {

    List< char > mylist;
    List< char > list;

    mylist.resize( 5 );
    ASSERT_EQ( 5, mylist.size() );

    list.push_back( 'a' );
    list.push_back( 'b' );
    list.push_back( 'c' );

    list.resize( 3 );
    ASSERT_EQ( 3, list.size() );

    list.resize( 2 );
    ASSERT_EQ( 2, list.size() );
    ASSERT_EQ( 'b', list.back() );

    list.resize( 5 );
    ASSERT_EQ( 5, list.size() );

    list.resize( 0 );
    ASSERT_EQ( 0, list.size() );

}

TEST( ListTests, value_resize ) {

    List< char > mylist;
    List< char > list;

    mylist.resize( 5, 'g' );
    ASSERT_EQ( 5, mylist.size() );
    ASSERT_EQ( 'g', mylist.front() );
    ASSERT_EQ( 'g', mylist.back() );

    list.push_back( 'a' );
    list.push_back( 'b' );
    list.push_back( 'c' );

    list.resize( 3, 'z' );
    ASSERT_EQ( 3, list.size() );
    ASSERT_EQ( 'c', list.back() );

    list.resize( 2, 'g' );
    ASSERT_EQ( 2, list.size() );
    ASSERT_EQ( 'b', list.back() );

    list.resize( 5, 'g' );
    ASSERT_EQ( 5, list.size() );
    ASSERT_EQ( 'g', mylist.back() );

    list.resize( 0, 'g' );
    ASSERT_EQ( 0, list.size() );

}

TEST( ListTests, brackets ) {

    List< char > list;

    try {
        char sym = list[ 2 ];

    } catch( std::runtime_error& e ) {

        ASSERT_STREQ( e.what(), "list is empty" );
        // std::cerr << e.what() << std::endl;

    }

    list.push_back( 'a' );
    list.push_back( 'b' );
    list.push_back( 'c' );
    list.push_back( 'd' );
    ASSERT_EQ( 'a', list[ 0 ] );
    ASSERT_EQ( 'c', list[ 2 ] );
    ASSERT_EQ( 'd', list[ 3 ] );

    list[ 2 ] = 'z';
    ASSERT_EQ( 'z', list[ 2 ] );

    // const char sym = list[ 2 ];

    try {
        char sym = list[ 4 ];

    } catch( std::runtime_error& e ) {

        ASSERT_STREQ( e.what(), "this position is out of range" );
        // std::cerr << e.what() << std::endl;

    }

}

TEST( ListTests, unique ) {

    List< char > list;

    unique( list );



    list.push_back( 'a' );
    unique( list );
    ASSERT_EQ( 1, list.size() );

    list.push_back( 'a' );
    unique( list );
    ASSERT_EQ( 1, list.size() );



    list.push_back( 'b' );
    list.push_back( 'c' );
    list.push_back( 'a' );
    list.push_back( 'b' );
    list.push_back( 'c' );
    list.push_back( 'c' );
    list.push_back( 'c' );
    list.push_back( 'a' );
    list.push_back( 'g' );


    unique( list );
    ASSERT_EQ( 4, list.size() );


}

TEST( ListTests, swap ) {

    List< char > myList;
    List< char > otherList;

    myList.swap( otherList );


    myList.pop_back();



    myList.push_back( 'a' );
    myList.swap( otherList );
    ASSERT_EQ( 'a', otherList.front() );
    ASSERT_EQ( 0, myList.size() );

    otherList.push_back( 'b' );
    otherList.push_back( 'c' );
    myList.push_back( '1' );
    myList.push_back( '2' );
    myList.push_back( '3' );
    myList.push_back( '4' );
    myList.swap( otherList );
    ASSERT_EQ( 3, myList.size() );
    ASSERT_EQ( '1', otherList.front() );




}


TEST( ListTests, copyConstr ) {

    List< int > otherlist;
    otherlist.push_back( 7 );
    otherlist.push_back( 8 );
    ASSERT_EQ( 2, otherlist.size() );

    List< int > mylist( otherlist );
// std::cout << otherlist[ 0 ] << std::endl;
// std::cout << otherlist[ 1 ] << std::endl;



    ASSERT_EQ( 2, mylist.size() );

}

TEST( ListTests, parameterConstr ) {


    List< int > mylist( 5, 111 );
    ASSERT_EQ( 5, mylist.size() );
// std::cout << mylist[ 0 ] << std::endl;
// std::cout << mylist[ 1 ] << std::endl;
// std::cout << mylist.size() << std::endl;

}

TEST( ListTests, moveConstr ) {

    ListWrap< int > mylistWrap = List< int >{ 3, 7 };
    mylistWrap.showList();

    ListWrap< int > otherlistWrap( List< int >{ 3, 6 } );
    otherlistWrap.showList();


}

TEST( ListTests, equConstr ) {

    List< int > mylist( 5, 7 );
    ASSERT_EQ( 5, mylist.size() );
    List< int > otherlist = mylist;

    std::cout << otherlist[ 0 ] << std::endl;
    std::cout << otherlist[ 1 ] << std::endl;
    ASSERT_EQ( 5, otherlist.size() );
}
