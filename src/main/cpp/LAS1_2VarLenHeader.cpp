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
    inStream.read(
        reinterpret_cast<char*>(&mReserved),
        SIZE_OF_SHORT);
    inStream.read(buff, SIZE_OF_CHAR*USER_ID_MAX_SIZE);
    int i = 0;
    for (i=0;i<SIZE_OF_CHAR*USER_ID_MAX_SIZE;i++) {
        if (buff[i] == '\0') {
//            cout << "fouund null at " << i <<endl;
            cout << "break " << i << endl;
            break;
        }
        cout << buff[i];
    }
//     mUserID = string(buff, buff+SIZE_OF_CHAR*USER_ID_MAX_SIZE);
    mUserID = string(buff, buff+i);
//    inStream.seekg(SIZE_OF_CHAR*USER_ID_MAX_SIZE-i+1);
    inStream.read(
        reinterpret_cast<char*>(&mRecordID), 
        SIZE_OF_SHORT);
    inStream.read(
        reinterpret_cast<char*>(&mRecordLengthAfterHeader), 
        SIZE_OF_SHORT);
    inStream.read(buff, SIZE_OF_CHAR*DESCRIPTION_MAX_SIZE);
//    int i = 0;
    for (i=0;i<SIZE_OF_CHAR*DESCRIPTION_MAX_SIZE;i++) {
        if (buff[i] == '\0') {
//            cout << "fouund null at " << i <<endl;
            cout << "break" << endl;
            break;
        }
        cout << buff[i];
    }
//    inStream.seekg(SIZE_OF_CHAR*DESCRIPTION_MAX_SIZE-i+1);

    cout <<endl;
    mDescription = string(buff, buff+i);
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
