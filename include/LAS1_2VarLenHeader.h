//
// 
/////////////////////////////////////////////////////////////////////////////// 
#ifndef __LAS1_2_VAR_LEN_HEADER_H__
#define __LAS1_2_VAR_LEN_HEADER_H__

#include "GenericHeader.h"
#include <string>
#include <vector>

class LAS1_2VarLenHeader : public GenericHeader {
 public:
    LAS1_2VarLenHeader();
    ~LAS1_2VarLenHeader();
    void Read(std::istream& inStream); 
    void Write( std::ostream& outStream ) const; 
    std::string ToString() const;

    unsigned short  Reserved() const {return mReserved;} 
    void  Reserved(unsigned short pReserved) {
        mReserved = pReserved;
    } 
    std::string UserID() const {return mUserID;}
    void UserID( const std::string& pUserID) {
        mUserID = pUserID;
    }
    unsigned short  RecordID() const {return mRecordID;}
    void RecordID(unsigned short pRecordID) {
        mRecordID = pRecordID;
    }
    unsigned short  RecordLengthAfterHeader() const {
        return mRecordLengthAfterHeader;
    }
    void RecordLengthAfterHeader(unsigned short pRecordLengthAfterHeader) {
        mRecordLengthAfterHeader = pRecordLengthAfterHeader; 
    }
    std::string Description() const {return mDescription;}
    void Description(const std::string& pDescription ) { 
        mDescription = pDescription; 
    }

    static const int USER_ID_MAX_SIZE = 16;
    static const int DESCRIPTION_MAX_SIZE = 32;
    static const int VAR_HEADER_BYTE_SIZE = 54;

 private:
    unsigned short mReserved; 
    std::string mUserID;
    unsigned short mRecordID;
    unsigned short mRecordLengthAfterHeader; 
    std::string mDescription; 
};
                    
#endif
