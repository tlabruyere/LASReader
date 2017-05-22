/////////////////////////////////////////////////////////////////////////////// 
// File: LAS1_2VarLenHeader.cpp
//
// 
/////////////////////////////////////////////////////////////////////////////// 

#include <sstream>
#include <iostream>

#include "LAS1_2VarLenHeader.h"


using namespace std;

LAS1_2VarLenHeader::LAS1_2VarLenHeader() :
    mReserved(), 
    mUserID(),
    mRecordID(),
    mRecordLengthAfterHeader(), 
    mDescription() {
}

LAS1_2VarLenHeader::~LAS1_2VarLenHeader() {
}

void LAS1_2VarLenHeader::Read(std::istream& inStream) {
    char* buff = new char[VAR_HEADER_BYTE_SIZE];
    inStream.read(buff, VAR_HEADER_BYTE_SIZE);
    memcpy(&mReserved,(unsigned char*) &buff[0] , 2);
    mUserID = string(&buff[1], 16);
    memcpy(&mRecordID,(unsigned char*) &buff[18] , 2);
    memcpy(&mRecordLengthAfterHeader,&buff[20] , 2);
    mDescription = string(&buff[22],32);
    printf("%d\n", mRecordLengthAfterHeader);
    inStream.seekg(mRecordLengthAfterHeader, std::ios_base::cur);
    delete [] buff;
}

void LAS1_2VarLenHeader::Write( std::ostream& outStream ) const {
}

string LAS1_2VarLenHeader::ToString() const {
    stringstream ss;
    ss << "Reserved : " << mReserved  << "\n"
        << "UserID: " << mUserID << "\n"
        << "RecordID: " << mRecordID << "\n"
        << "RecordLengthAfterHeader: " << mRecordLengthAfterHeader << "\n"
        << "Description: " << mDescription << "\n";
    return ss.str();
}
