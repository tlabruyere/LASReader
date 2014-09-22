/////////////////////////////////////////////////////////////////////////////// 
// File: LAS1_2VarLenHeaderTest.cpp
//
// 
/////////////////////////////////////////////////////////////////////////////// 

#include <gtest/gtest.h>
#include <LAS1_2VarLenHeader.h>

#include <vector>
#include <iostream>

class LAS1_2VarLenHeaderTest : public ::testing::Test
{
};

using namespace std;
TEST_F( LAS1_2VarLenHeaderTest, mutatorsAndAccessors)
{
    LAS1_2VarLenHeader varLenHeader;

    varLenHeader.Reserved(15); 
    EXPECT_EQ( 15, varLenHeader.Reserved() ); 
    varLenHeader.UserID("himynameis");
    EXPECT_EQ( "himynameis", varLenHeader.UserID() );
    varLenHeader.RecordID(15);
    EXPECT_EQ( 15, varLenHeader.RecordID() );
    varLenHeader.RecordLengthAfterHeader(15); 
    EXPECT_EQ( 15, varLenHeader.RecordLengthAfterHeader() ); 
    varLenHeader.Description("himynameis"); 
    EXPECT_EQ( "himynameis", varLenHeader.Description() ); 

    // just print 
    cout << varLenHeader.ToString() << endl;
}
