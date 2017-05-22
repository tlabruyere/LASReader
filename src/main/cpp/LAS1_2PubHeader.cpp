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
    mProjectIDGUIDdata4(PROJECT_ID_GUID_DATA_4_SIZE),
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
    mNumberOfPointsByReturn(NUMBER_OF_POINTS_BY_RETURN_SIZE),
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
    mZMin() {
}

LAS1_2PubHeader::~LAS1_2PubHeader() {
}

void LAS1_2PubHeader::Read(istream& inStream) {
    char* buff = new char[PUB_HEADER_BYTE_SIZE];
    inStream.read(buff, SIZE_OF_CHAR*FILE_SIGNATURE_SIZE);
    mFileSignature = string(buff, buff+SIZE_OF_CHAR*FILE_SIGNATURE_SIZE);
    inStream.read(
        reinterpret_cast<char*>(&mFileSourceID),
        SIZE_OF_SHORT);
    inStream.read(
        reinterpret_cast<char*>(&mGlobalEncoding),
        SIZE_OF_SHORT);
    inStream.read(
        reinterpret_cast<char*>(&mProjectIDGUIDdata1),
        SIZE_OF_LONG);
    inStream.read(
        reinterpret_cast<char*>(&mProjectIDGUIDdata2),
        SIZE_OF_SHORT);
    inStream.read(
        reinterpret_cast<char*>(&mProjectIDGUIDdata3),
        SIZE_OF_SHORT);
    // get project id data 4
    inStream.read(buff,SIZE_OF_CHAR*8);
    for (int i =0;i<PROJECT_ID_GUID_DATA_4_SIZE;i++) {
        mProjectIDGUIDdata4[i] = buff[i];
    }
    inStream.read(
        reinterpret_cast<char*>(&mVersionMajor),
        SIZE_OF_CHAR);
    inStream.read(
        reinterpret_cast<char*>(&mVersionMinor),
        SIZE_OF_CHAR);

    inStream.read(buff, SIZE_OF_CHAR*SYSTEM_IDENTIFIER_SIZE);
    mSystemIdentifier = string(buff, buff+SIZE_OF_CHAR*SYSTEM_IDENTIFIER_SIZE);
    inStream.read(buff, SIZE_OF_CHAR*SYSTEM_IDENTIFIER_SIZE);
    mGeneratingSoftware = string(buff, buff+SIZE_OF_CHAR*GENERATING_SOFTWARE_SIZE);

    inStream.read(
        reinterpret_cast<char*>(&mFileCreationDayOfYear),
        SIZE_OF_SHORT);
    inStream.read(
        reinterpret_cast<char*>(&mFileCreationYear),
        SIZE_OF_SHORT);
    inStream.read(
        reinterpret_cast<char*>(&mHeaderSize),
        SIZE_OF_SHORT);
    inStream.read(
        reinterpret_cast<char*>(&mOffsetToPointData),
        SIZE_OF_LONG);
    inStream.read(reinterpret_cast<char*>(
        &mNumberOfVariableLengthRecords),
        SIZE_OF_LONG);
    inStream.read(
        reinterpret_cast<char*>(&mPointDataFormatID),
        SIZE_OF_CHAR);
    inStream.read(
        reinterpret_cast<char*>(&mPointDataRecordLength),
        SIZE_OF_SHORT);
    inStream.read(
        reinterpret_cast<char*>(&mNumberOfPointRecord),
        SIZE_OF_LONG);
//    inStream.read(buff, SIZE_OF_CHAR*FILE_SIGNATURE_SIZE);
    for (int i =0;i<NUMBER_OF_POINTS_BY_RETURN_SIZE;i++) {
        inStream.read(
            reinterpret_cast<char*>(&mNumberOfPointsByReturn[i]),
            SIZE_OF_LONG);
    }
    inStream.read(
        reinterpret_cast<char*>(&mXScaleFactor),
        SIZE_OF_DOUBLE);
    inStream.read(
        reinterpret_cast<char*>(&mYScaleFactor),
        SIZE_OF_DOUBLE);
    inStream.read(
        reinterpret_cast<char*>(&mZScaleFactor),
        SIZE_OF_DOUBLE);
    inStream.read(
        reinterpret_cast<char*>(&mXOffset),
        SIZE_OF_DOUBLE);
    inStream.read(
        reinterpret_cast<char*>(&mYOffset),
        SIZE_OF_DOUBLE);
    inStream.read(
        reinterpret_cast<char*>(&mZOffset),
        SIZE_OF_DOUBLE);
    inStream.read(
        reinterpret_cast<char*>(&mXMax),
        SIZE_OF_DOUBLE);
    inStream.read(
        reinterpret_cast<char*>(&mXMin),
        SIZE_OF_DOUBLE);
    inStream.read(
        reinterpret_cast<char*>(&mYMax),
        SIZE_OF_DOUBLE);
    inStream.read(
        reinterpret_cast<char*>(&mYMin),
        SIZE_OF_DOUBLE);
    inStream.read(
        reinterpret_cast<char*>(&mZMax),
        SIZE_OF_DOUBLE);
    inStream.read(
        reinterpret_cast<char*>(&mZMin),
        SIZE_OF_DOUBLE);
    delete [] buff;
}

void LAS1_2PubHeader::Write(std::ostream& outStream) const {
}

std::string LAS1_2PubHeader::ToString() const {
    stringstream ss;
    ss << "FileSignature: " << mFileSignature << "\n"
        << "FileSourceID: " << mFileSourceID << "\n"
        << "GlobalEncoding: " << mGlobalEncoding << "\n"
        << "ProjectIDGUIDdata1: " << mProjectIDGUIDdata1 << "\n"
        << "ProjectIDGUIDdata2: " << mProjectIDGUIDdata2 << "\n"
        << "ProjectIDGUIDdata3: " << mProjectIDGUIDdata3 << "\n"
        << "ProjectIDGUIDdata4: <";
    for(int i =0; i<mProjectIDGUIDdata4.size()-1; i++)
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
        << "NumberOfVariableLengthRecords: " << mNumberOfVariableLengthRecords << "\n"
        << "PointDataFormatID: " << static_cast<int>(mPointDataFormatID) << "\n"
        << "PointDataRecordLength: " << mPointDataRecordLength << "\n"
        << "NumberOfPointRecord: " << mNumberOfPointRecord << "\n"
        << "NumberOfPointsByReturn: <";
    for (int i =0; i<mNumberOfPointsByReturn.size()-1; i++) {
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

