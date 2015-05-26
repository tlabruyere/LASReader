/////////////////////////////////////////////////////////////////////////////// 
// File: LAS1_2.cpp
// 
// 
/////////////////////////////////////////////////////////////////////////////// 
#include "LAS1_2.h" 
#include <LAS1_2VarLenHeader.h>

#include <sstream>

using namespace std;

LAS1_2::LAS1_2() :
    mPubHeader(),
    mVarLenHeaders() {
}

LAS1_2::~LAS1_2() {
}

void LAS1_2::Read(std::istream& inStream) {
    mPubHeader.Read( inStream );
    for (int i=0;i<mPubHeader.NumberOfVariableLengthRecords();i++) {
        LAS1_2VarLenHeader varLenHeader;
        varLenHeader.Read(inStream);
        mVarLenHeaders.push_back(varLenHeader);
        int bytesLeftAferHeader = 0;
        if ((bytesLeftAferHeader = (varLenHeader.RecordLengthAfterHeader()
            - LAS1_2VarLenHeader::VAR_HEADER_BYTE_SIZE)) >=0) {
//            inStream.seekg(bytesLeftAferHeader);
        }
    }
}

void LAS1_2::Write(std::ostream& outStream) const {
    mPubHeader.Write( outStream );
    for (int i=0;i<mVarLenHeaders.size();i++) {
        mVarLenHeaders[i].Write(outStream);
    }
}

string LAS1_2::ToString() const {
    stringstream ss;
    ss << "PUBLIC HEADER ===================" << "\n"
        << mPubHeader.ToString() << "\n";
    for (int i=0;i<mVarLenHeaders.size();i++) {
        ss << "VARIABLE LENGTH HEADER("<< i << "} ==========" << "\n"
        << mVarLenHeaders[i].ToString();
    }
    return ss.str();
}


