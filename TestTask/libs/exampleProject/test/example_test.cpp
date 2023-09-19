#include <gtest/gtest.h>
#include "exampleclass/exampleclass.h"


TEST( ListTests, creating ) {
    List< int > list;
}


TEST( ListTests, push_backANDsize ) {
    List< int > list;
    list.push_back( 7 );
    list.push_back( 8 );
    ASSERT_EQ( 2, list.size() );

    List< int > listNull;
    ASSERT_EQ( 0, listNull.size() );

    list.push_back( 5.5 );


}
/*
   // TEST( ListTests, brackets) {
   // List< int > list;
   // list.push_back( 7 );
   // list.push_back( 10 );
   // list.push_back( 18 );

   // ASSERT_EQ( 3, list.size() );
   // ASSERT_EQ( 10, list[ 2 ] );
   // }


   TEST( ListTests, empty ) {
    List< int > list;
    ASSERT_EQ( true, list.empty() );
    list.push_back( 7 );
    list.push_back( 18 );
    ASSERT_EQ( false, list.empty() );
   }


   TEST( ListTests, front ) {
    List< int > list;
    list.push_back( 7 );
    list.push_back( 18 );
    ASSERT_EQ( 7, list.front() );
   }

   TEST( ListTests, pop_front ) {
    List< int > list;
    list.push_back( 7 );
    list.push_back( 18 );
    list.push_back( 4 );
    list.pop_front();
    ASSERT_EQ( 18, list.front() );

   }

   TEST( ListTests, clean ) {
    List< int > list;
    list.push_back( 7 );
    list.push_back( 18 );
    list.push_back( 4 );
    list.clean();
    ASSERT_EQ( 0, list.size() );

   }

   TEST( ListTests, push_front ) {
    List< int > list;
    list.push_back( 1 );
    list.push_back( 2 );
    list.push_back( 3 );
    list.push_front( 0 );
    ASSERT_EQ( 4, list.size() );
    ASSERT_EQ( 0, list.front() );

   }

   TEST( ListTests, pop_back ) {
    List< int > list;
    list.push_back( 1 );
    list.push_back( 2 );
    list.push_back( 3 );
    list.pop_back();
    ASSERT_EQ( 2, list.size() );
    ASSERT_EQ( 2, list.back() );

   }

   TEST( ListTests, begin ) {
    List< int > list;
    list.push_back( 0 );
    list.push_back( 5 );
    const int* temp = list.begin();
    ASSERT_EQ( 0, *temp );

   }

   TEST( ListTests, end ) {
    List< char > list;
    list.push_back( 'a' );
    list.push_back( 'b' );
    list.push_back( 'c' );
    const char* temp = list.end();
    ASSERT_EQ( 'c', *temp );

   }

   TEST( ListTests, erase ) {
    List< int > list;
    list.push_back( 10 );
    list.push_back( 20 );
    list.push_back( 999 );
    list.push_back( 40 );
    list.erase( 3 );
    ASSERT_EQ( 3, list.size() );
    ASSERT_EQ( 40, list[ 3 ] );

   }

   TEST( ListTests, insert ) {
    List< int > list;
    list.push_back( 10 );
    list.push_back( 20 );
    list.push_back( 30 );
    list.push_back( 40 );
    list.insert( 4, 999 );
    ASSERT_EQ( 5, list.size() );
    ASSERT_EQ( 999, list[ 4 ] );

   }

   TEST( ListTests, unique ) {
    List< int > list;
    list.push_back( 1 );
    list.push_back( 2 );
    list.push_back( 2 );
    list.push_back( 0 );
    list.push_back( 0 );
    list.push_back( 0 );
    list.push_back( 9 );
    list.unique();
    ASSERT_EQ( 4, list.size() );


   }




   // TEST( ListTests, zxx ) {

   // List< int > a;

   // uint32_t testCount = 100;

   // for( int var = 0; var < testCount; ++var ) {
   // a.push_back( var * 77 );

   // ASSERT_EQ( var * 77, a[ var ] );

   // ASSERT_EQ( var, a.size() );

   // }
   // }


   // template < typename T >
   // void readElementFromListByIdx( size_t id, const List< T >& list ) {
   // std::cerr << list[ 0 ] << std::endl;
   // }
   // T&& - универсальная ссылка
   // int&& - rvalue-ссылка
   // int& - ссылка, значение по которой доступно для изменения
   // const int& - константная ссылка

   // template < typename T >
   // void writeElementToListByIdx( T&& element, size_t id, List< T >& list ) {
   // list[ id ] = element;
   // }

   // TEST( ListTests, zzxx ) {
   // List< int > intList;

   // writeElementToListByIdx( 7, 0, intList );
   // }



 */
