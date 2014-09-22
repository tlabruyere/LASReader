/////////////////////////////////////////////////////////////////////////////// 
// File: LAS1_2PubHeaderTest.cpp
//
// 
/////////////////////////////////////////////////////////////////////////////// 

#include <gtest/gtest.h>
#include <LAS1_2PubHeader.h>

#include <vector>
#include <iostream>
#include <fstream>

class LAS1_2PubHeaderTest : public ::testing::Test
{
};

using namespace std;
TEST_F( LAS1_2PubHeaderTest, mutatorsAndAccessors)
{
    LAS1_2PubHeader pubHeader;

    pubHeader.FileSignature( "LASF" );
    EXPECT_EQ( "LASF", pubHeader.FileSignature() );
    pubHeader.FileSourceID( 15 );
    EXPECT_EQ( 15, pubHeader.FileSourceID() );
    pubHeader.GlobalEncoding( 15 );
    EXPECT_EQ( 15, pubHeader.GlobalEncoding() );
    pubHeader.ProjectIDGUIDdata1( 12 );
    EXPECT_EQ( 12, pubHeader.ProjectIDGUIDdata1() );
    pubHeader.ProjectIDGUIDdata2( 14 );
    EXPECT_EQ( 14, pubHeader.ProjectIDGUIDdata2() );
    pubHeader.ProjectIDGUIDdata3( 14 );
    EXPECT_EQ( 14, pubHeader.ProjectIDGUIDdata3() );
    unsigned char tmp[] = { 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55 };
    vector<unsigned char> myUnsignChar(tmp, tmp+LAS1_2PubHeader::PROJECT_ID_GUID_DATA_4_SIZE);
    pubHeader.ProjectIDGUIDdata4( myUnsignChar );
    EXPECT_EQ( myUnsignChar, pubHeader.ProjectIDGUIDdata4() );
    pubHeader.VersionMajor( 12 );
    EXPECT_EQ( 12, pubHeader.VersionMajor() );
    pubHeader.VersionMinor( 12 );
    EXPECT_EQ( 12, pubHeader.VersionMinor() );
    pubHeader.SystemIdentifier( "thisIsasystem" );
    EXPECT_EQ(  "thisIsasystem", pubHeader.SystemIdentifier() );
    pubHeader.GeneratingSoftware( "thisIsSoftware" );
    EXPECT_EQ( "thisIsSoftware", pubHeader.GeneratingSoftware() );
    pubHeader.FileCreationDayOfYear( 12 );
    EXPECT_EQ(  12, pubHeader.FileCreationDayOfYear() );
    pubHeader.FileCreationYear( 12 );
    EXPECT_EQ( 12, pubHeader.FileCreationYear() );
    pubHeader.HeaderSize( 12 );
    EXPECT_EQ( 12, pubHeader.HeaderSize() );
    pubHeader.OffsetToPointData( 12 );
    EXPECT_EQ( 12, pubHeader.OffsetToPointData() );
    pubHeader.NumberOfVariableLengthRecords( 12 );
    EXPECT_EQ( 12, pubHeader.NumberOfVariableLengthRecords() );
    pubHeader.PointDataFormatID( 12 );
    EXPECT_EQ( 12, pubHeader.PointDataFormatID() );
    pubHeader.PointDataRecordLength( 12 );
    EXPECT_EQ( 12, pubHeader.PointDataRecordLength() );
    pubHeader.NumberOfPointRecord( 12 );
    EXPECT_EQ( 12, pubHeader.NumberOfPointRecord() );
    unsigned long tmp1[] = { 12, 12, 12, 12, 12 };
    vector<unsigned long> myUnsignLong(tmp1, tmp1+LAS1_2PubHeader::NUMBER_OF_POINTS_BY_RETURN_SIZE );
    pubHeader.NumberOfPointsByReturn( myUnsignLong );
    EXPECT_EQ( myUnsignLong, pubHeader.NumberOfPointsByReturn() );
    pubHeader.XScaleFactor( 12 );
    EXPECT_EQ( 12, pubHeader.XScaleFactor() );
    pubHeader.YScaleFactor( 12 );
    EXPECT_EQ( 12, pubHeader.YScaleFactor() );
    pubHeader.ZScaleFactor( 12 );
    EXPECT_EQ( 12, pubHeader.ZScaleFactor() );
    pubHeader.XOffset( 12 );
    EXPECT_EQ( 12, pubHeader.XOffset() );
    pubHeader.YOffset( 12 );
    EXPECT_EQ( 12, pubHeader.YOffset() );
    pubHeader.ZOffset( 12 );
    EXPECT_EQ( 12, pubHeader.ZOffset() );
    pubHeader.XMax( 12 );
    EXPECT_EQ( 12, pubHeader.XMax() );
    pubHeader.XMin( 12 );
    EXPECT_EQ( 12, pubHeader.XMin() );
    pubHeader.YMax( 12 );
    EXPECT_EQ( 12, pubHeader.YMax() );
    pubHeader.YMin( 12 );
    EXPECT_EQ( 12, pubHeader.YMin() );
    pubHeader.ZMax( 12 );
    EXPECT_EQ( 12, pubHeader.ZMax() );
    pubHeader.ZMin( 12 );
    EXPECT_EQ( 12, pubHeader.ZMin() );
    
    // just print 
    cout << pubHeader.ToString() << endl;
}

TEST_F( LAS1_2PubHeaderTest, readFile)
{
    ifstream FileStream( "/Users/telabru/Downloads/ARRA-NRCS_Illinois_2010_000061/ARRA-NRCS_Illinois_2010_000061.las");
    LAS1_2PubHeader pubHeader;
    pubHeader.Read( FileStream );
    pubHeader.ToString();
    // just print 
    cout << pubHeader.ToString() << endl;
}


