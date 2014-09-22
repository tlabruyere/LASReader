/////////////////////////////////////////////////////////////////////////////// 
// File: LAS1_2.cpp
// 
// 
/////////////////////////////////////////////////////////////////////////////// 
#include "LAS1_2.h" 

#include <sstream>

using namespace std;

LAS1_2::LAS1_2() :
    mPubHeader(),
    mVarLenHeader()
{
}

LAS1_2::~LAS1_2()
{
}

string LAS1_2::ToString()
{
    stringstream ss;
    ss << "PUBLIC HEADER ===================" << endl
        << mPubHeader.ToString() << endl
        << "VARIABLE LENGTH HEADER ==========" << endl
        << mVarLenHeader.ToString();
    return ss.str();
}

void LAS1_2::Read( std::istream& inStream )
{
    mPubHeader.Read( inStream );
    mVarLenHeader.Read( inStream );
}

void LAS1_2::Write( std::ostream& outStream )
{
    mPubHeader.Write( outStream );
    mVarLenHeader.Write( outStream );
}
