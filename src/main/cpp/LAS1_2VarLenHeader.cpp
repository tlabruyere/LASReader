/////////////////////////////////////////////////////////////////////////////// 
// File: LAS1_2VarLenHeader.cpp
//
// 
/////////////////////////////////////////////////////////////////////////////// 

#include "LAS1_2VarLenHeader.h"

#include <sstream>

using namespace std;

LAS1_2VarLenHeader::LAS1_2VarLenHeader() :
    mReserved(), 
    mUserID(),
    mRecordID(),
    mRecordLengthAfterHeader(), 
    mDescription()
{
}

LAS1_2VarLenHeader::~LAS1_2VarLenHeader()
{
}

void LAS1_2VarLenHeader::Read( std::istream& inStream )
{
}

void LAS1_2VarLenHeader::Write( std::ostream& outStream )
{
}

string LAS1_2VarLenHeader::ToString()
{
    stringstream ss;
    ss << "Reserved : " << mReserved  << "\n"
        << "UserID: " << mUserID << "\n"
        << "RecordID: " << mRecordID << "\n"
        << "RecordLengthAfterHeader: " << mRecordLengthAfterHeader << "\n"
        << "Description: " << mDescription << "\n";
    return ss.str();
}
