/////////////////////////////////////////////////////////////////////////////// 
// File: LAS1_2PubHeader.cpp
//
// 
/////////////////////////////////////////////////////////////////////////////// 
#include "LAS1_2PubHeader.h"

#include <sstream>
#include <iostream>

using namespace std;

LAS1_2PubHeader::LAS1_2PubHeader() :
    mFileSignature(),
    mFileSourceID(),
    mGlobalEncoding(),
    mProjectIDGUIDdata1(),
    mProjectIDGUIDdata2(),
    mProjectIDGUIDdata3(),
    mProjectIDGUIDdata4( PROJECT_ID_GUID_DATA_4_SIZE ),
    mVersionMajor(),
    mVersionMinor(),
    mSystemIdentifier(),
    mGeneratingSoftware(),
    mFileCreationDayOfYear(),
    mFileCreationYear(),
    mHeaderSize(),
    mOffsetToPointData(),
    mNumberOfVariableLengthRecords(),
    mPointDataFormatID(),
    mPointDataRecordLength(),
    mNumberOfPointRecord(),
    mNumberOfPointsByReturn( NUMBER_OF_POINTS_BY_RETURN_SIZE ),
    mXScaleFactor(),
    mYScaleFactor(),
    mZScaleFactor(),
    mXOffset(),
    mYOffset(),
    mZOffset(),
    mXMax(),
    mXMin(),
    mYMax(),
    mYMin(),
    mZMax(),
    mZMin()
{
}

LAS1_2PubHeader::~LAS1_2PubHeader()
{
}


void LAS1_2PubHeader::Read( istream& inStream )
{
    char* buff = new char[PUB_HEADER_BYTE_SIZE];
//    inStream.read(buff, FILE_SIGNATURE_SIZE );

    inStream.read( buff, FILE_SIGNATURE_SIZE );
//    buff[FILE_SIGNATURE_SIZE+1] = '\0';
//    cout << "buff = " << buff << endl;
    mFileSignature = string(buff, buff+FILE_SIGNATURE_SIZE );
//    cout << "size = " << mFileSignature.size() <<endl;
    inStream.read(reinterpret_cast<char*>(&mFileSourceID), sizeof(unsigned short) );
    inStream.read(reinterpret_cast<char*>(&mGlobalEncoding), sizeof(unsigned short) );
    inStream.read(reinterpret_cast<char*>(&mProjectIDGUIDdata1), sizeof(unsigned long) );
    inStream.read(reinterpret_cast<char*>(&mProjectIDGUIDdata2), sizeof(unsigned short) );
    inStream.read(reinterpret_cast<char*>(&mProjectIDGUIDdata3), sizeof(unsigned short) );
    // get project id data 4
    for( int i =0;i<mProjectIDGUIDdata4.size();i++)
    {
        inStream.read(reinterpret_cast<char*>(&mProjectIDGUIDdata4[i]), sizeof(unsigned char)*PROJECT_ID_GUID_DATA_4_SIZE );
    }
    inStream.read(reinterpret_cast<char*>( &mVersionMajor ), sizeof( mVersionMajor ));
    inStream.read(reinterpret_cast<char*>( &mVersionMinor ), sizeof( mVersionMinor ));

    inStream.read( buff, SYSTEM_IDENTIFIER_SIZE );
    mSystemIdentifier = string(buff, buff+SYSTEM_IDENTIFIER_SIZE );
    inStream.read( buff, SYSTEM_IDENTIFIER_SIZE );
    mGeneratingSoftware = string( buff, buff+GENERATING_SOFTWARE_SIZE );

    inStream.read(reinterpret_cast<char*>( &mFileCreationDayOfYear), sizeof( mFileCreationDayOfYear ));
    inStream.read(reinterpret_cast<char*>( &mFileCreationYear), sizeof( mFileCreationYear ));
    inStream.read(reinterpret_cast<char*>( &mHeaderSize), sizeof( mHeaderSize ));
    inStream.read(reinterpret_cast<char*>( &mOffsetToPointData), sizeof( mOffsetToPointData ));
    inStream.read(reinterpret_cast<char*>( &mNumberOfVariableLengthRecords), sizeof( mNumberOfVariableLengthRecords ));
    inStream.read(reinterpret_cast<char*>( &mPointDataFormatID), sizeof( mPointDataFormatID ));
    inStream.read(reinterpret_cast<char*>( &mPointDataRecordLength), sizeof( mPointDataRecordLength ));
    inStream.read(reinterpret_cast<char*>( &mNumberOfPointRecord), sizeof( mNumberOfPointRecord ));
    for( int i =0;i<mNumberOfPointsByReturn.size();i++)
    {
        inStream.read(reinterpret_cast<char*>( &mNumberOfPointsByReturn[i]), sizeof( unsigned long ));
    }
    inStream.read(reinterpret_cast<char*>( &mXScaleFactor), sizeof( mXScaleFactor ));
    inStream.read(reinterpret_cast<char*>( &mYScaleFactor), sizeof( mYScaleFactor ));
    inStream.read(reinterpret_cast<char*>( &mZScaleFactor), sizeof( mZScaleFactor ));
    inStream.read(reinterpret_cast<char*>( &mXOffset), sizeof( mXOffset ));
    inStream.read(reinterpret_cast<char*>( &mYOffset), sizeof( mYOffset ));
    inStream.read(reinterpret_cast<char*>( &mZOffset), sizeof( mZOffset ));
    inStream.read(reinterpret_cast<char*>( &mXMax), sizeof( mXMax ));
    inStream.read(reinterpret_cast<char*>( &mXMin), sizeof( mXMin ));
    inStream.read(reinterpret_cast<char*>( &mYMax), sizeof( mYMax ));
    inStream.read(reinterpret_cast<char*>( &mYMin), sizeof( mYMin ));
    inStream.read(reinterpret_cast<char*>( &mZMax), sizeof( mZMax ));
    inStream.read(reinterpret_cast<char*>( &mZMin), sizeof( mZMin ));
}

void LAS1_2PubHeader::Write( std::ostream& outStream )
{
} 

std::string LAS1_2PubHeader::ToString()
{
    stringstream ss;
    ss << "FileSignature: " << mFileSignature << "\n"
        << "FileSourceID: " << mFileSourceID << "\n"
        << "GlobalEncoding: " << mGlobalEncoding << "\n"
        << "ProjectIDGUIDdata1: " << mProjectIDGUIDdata1 << "\n"
        << "ProjectIDGUIDdata2: " << mProjectIDGUIDdata2 << "\n"
        << "ProjectIDGUIDdata3: " << mProjectIDGUIDdata3 << "\n"
        << "ProjectIDGUIDdata4: <";
    for( int i =0; i<mProjectIDGUIDdata4.size()-1; i++)
    {
        ss << mProjectIDGUIDdata4[i] << ",";
    }
    ss << mProjectIDGUIDdata4[mProjectIDGUIDdata4.size()-1] << ">\n";

    ss << "VersionMajor: " << static_cast<int>(mVersionMajor) << "\n"
        << "VersionMinor: " << static_cast<int>(mVersionMinor) << "\n"
        << "SystemIdentifier: " << mSystemIdentifier << "\n"
        << "GeneratingSoftware: " << mGeneratingSoftware << "\n"
        << "FileCreationDayOfYear: " << mFileCreationDayOfYear << "\n"
        << "FileCreationYear: " << mFileCreationYear << "\n"
        << "HeaderSize: " << mHeaderSize << "\n"
        << "OffsetToPointData: " << mOffsetToPointData << "\n"
        << "NumberOfVariableLengthRecords;: " << mNumberOfVariableLengthRecords << "\n"
        << "PointDataFormatID: " << static_cast<int>(mPointDataFormatID) << "\n"
        << "PointDataRecordLength: " << mPointDataRecordLength << "\n"
        << "NumberOfPointRecord: " << mNumberOfPointRecord << "\n"
        << "NumberOfPointsByReturn: <";
    for( int i =0; i<mNumberOfPointsByReturn.size()-1; i++)
    {
        ss << mNumberOfPointsByReturn[i] << ",";
    }
    ss << mNumberOfPointsByReturn[mNumberOfPointsByReturn.size()-1] << ">\n";

    ss << "XScaleFactor: " << mXScaleFactor << "\n"
        << "YScaleFactor: " << mYScaleFactor << "\n"
        << "ZScaleFactor: " << mZScaleFactor << "\n"
        << "XOffset: " << mXOffset << "\n"
        << "YOffset: " << mYOffset << "\n"
        << "ZOffset: " << mZOffset << "\n"
        << "XMax: " << mXMax << "\n"
        << "XMin: " << mXMin << "\n"
        << "YMax: " << mYMax << "\n"
        << "YMin: " << mYMin << "\n"
        << "ZMax: " << mZMax << "\n"
        << "ZMin: " << mZMin << "\n";
    return ss.str();
}

