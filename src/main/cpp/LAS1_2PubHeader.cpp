/////////////////////////////////////////////////////////////////////////////// 
// File: LAS1_2PubHeader.cpp
//
// 
/////////////////////////////////////////////////////////////////////////////// 
#include "LAS1_2PubHeader.h"

#include <sstream>

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


void LAS1_2PubHeader::Read( std::istream& inStream )
{
    char* buff = new char[PUB_HEADER_BYTE_SIZE];
    inStream.read(buff, PUB_HEADER_BYTE_SIZE);
    mFileSignature = string(buff, buff+FILE_SIGNATURE_SIZE );
    mFileSourceID = buff[5];
    mFileSourceID = double(buff[6], buff[14]);
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

