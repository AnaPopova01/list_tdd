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
    list.push_back( 8 );
    ASSERT_EQ( 0, list.empty() );

}

TEST( ListTests, front ) {

    List< char > list;
    list.push_back( 'a' );
    list.push_back( 'b' );
    list.push_back( 'c' );
    ASSERT_EQ( 'a', list.front() );

}

TEST( ListTests, back ) {

    List< char > list;
    list.push_back( 'a' );
    list.push_back( 'b' );
    list.push_back( 'c' );
    ASSERT_EQ( 'c', list.back() );

}
