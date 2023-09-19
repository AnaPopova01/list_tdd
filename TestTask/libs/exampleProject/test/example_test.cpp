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
    ASSERT_EQ( 2, list.size() );

    list.push_back( 5.5 );
    list.push_back( 'a' );
    // list.push_back( "hi" );


    ASSERT_EQ( 4, list.size() );

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
    try {
        list.front();

    } catch( std::runtime_error& e ) {

        ASSERT_STREQ( e.what(), "list is empty" );
        // std::cerr << e.what() << std::endl;

    }



    list.push_back( 'a' );
    ASSERT_EQ( 'a', list.front() );
    list.push_back( 'b' );
    list.push_back( 'c' );
    ASSERT_EQ( 'a', list.front() );

}

TEST( ListTests, back ) {

    List< char > list;
    try {
        list.back();

    } catch( std::runtime_error& e ) {

        ASSERT_STREQ( e.what(), "list is empty" );
        // std::cerr << e.what() << std::endl;

    }
    list.push_back( 'a' );
    ASSERT_EQ( 'a', list.back() );
    list.push_back( 'b' );
    list.push_back( 'c' );
    ASSERT_EQ( 'c', list.back() );

}

TEST( ListTests, pop_back ) {

    List< char > list;
    try {
        list.pop_back();

    } catch( std::runtime_error& e ) {

        ASSERT_STREQ( e.what(), "list is empty" );
        // std::cerr << e.what() << std::endl;

    }

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
    try {
        list.pop_front();

    } catch( std::runtime_error& e ) {

        ASSERT_STREQ( e.what(), "list is empty" );
        // std::cerr << e.what() << std::endl;

    }

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
    ASSERT_EQ( 'a', list.front() );
    list.push_front( 'b' );
    list.push_front( 'c' );
    ASSERT_EQ( 'c', list.front() );
    ASSERT_EQ( 'a', list.back() );
    ASSERT_EQ( 3, list.size() );

}
