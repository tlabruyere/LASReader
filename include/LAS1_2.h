/////////////////////////////////////////////////////////////////////////////// 
// File: LAS1_2.h
//
// 
/////////////////////////////////////////////////////////////////////////////// 
#ifndef __LAS_1_2_H___
#define __LAS_1_2_H___

#include <GenericHeader.h>
#include <LAS1_2PubHeader.h>
#include <LAS1_2VarLenHeader.h>
#include <string>

class LAS1_2 : public GenericHeader
{
    public:
        LAS1_2();
        ~LAS1_2();
        void Read( std::istream& inStream ); 
        void Write( std::ostream& outStream ); 
        std::string ToString();

    private:
        LAS1_2PubHeader mPubHeader;
        LAS1_2VarLenHeader mVarLenHeader;
        
};

#endif
