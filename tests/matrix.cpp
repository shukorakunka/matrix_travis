#include "matrix.hpp"
#include "catch.hpp"

TEST_CASE("creat"){
    Matrix matrix;
    REQUIRE(matrix.rows() == 0);
    REQUIRE(matrix.rolumns() == 0);
}

TEST_CASE("read"){
    std::string input{
        "3, 3\n"
        "1 1 1\n"
        "2 2 2\n"
        "3 3 3" };
    matrix_t matrix;
    std::istringstream istream{ input };
    
    REQUIRE( matrix.read( istream ) );
    REQUIRE( matrix.rows() == 3 );
    REQUIRE( matrix.collumns() == 3 );
    
    std::ostringstream ostream;
    matrix.write( ostream );
    
    REQUIRE( input == ostream.str() );
}