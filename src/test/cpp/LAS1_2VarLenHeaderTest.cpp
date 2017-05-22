/////////////////////////////////////////////////////////////////////////////// 
// File: LAS1_2VarLenHeaderTest.cpp
//
// 
/////////////////////////////////////////////////////////////////////////////// 

#include <gtest/gtest.h>
#include <LAS1_2VarLenHeader.h>
#include <LAS1_2.h>

#include <vector>
#include <iostream>
#include <fstream>

class LAS1_2VarLenHeaderTest : public ::testing::Test {
}; using namespace std; TEST_F( LAS1_2VarLenHeaderTest, mutatorsAndAccessors) {
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

TEST_F( LAS1_2VarLenHeaderTest, readFile) {
    std::string file = "/Users/omegarain64/Downloads/ARRA-NRCS_Illinois_2010_000061.las";
//    std::string file = "/Users/telabru/Downloads/ARRA-NRCS_Illinois_2010_000061/ARRA-NRCS_Illinois_2010_000061.las"
    std::ifstream fileStream( file, ios::in );// |ios::binary);
    ASSERT_TRUE(fileStream.is_open());
//        cout << " i am open" <<endl;
    LAS1_2 las12;
    las12.Read( fileStream );
    fileStream.close();

//    // just print 
    cout << las12.ToString() << endl;

}
