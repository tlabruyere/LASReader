/////////////////////////////////////////////////////////////////////////////// 
// File: LAS1_2.h
//
// 
/////////////////////////////////////////////////////////////////////////////// 
#ifndef __LAS_1_2_H___
#define __LAS_1_2_H___

#include <string>
#include <vector>
#include <memory>
#include <GenericHeader.h>
#include <LAS1_2PubHeader.h>
#include <LAS1_2VarLenHeader.h>

class LAS1_2 : public GenericHeader {
 public:
    LAS1_2();
    ~LAS1_2();
    void Read(std::istream& inStream);
    void Write(std::ostream& outStream) const;
    std::string ToString() const;
    std::shared_ptr<float> data();
    LAS1_2PubHeader publicHeader() const {return mPubHeader;}
    std::vector<LAS1_2VarLenHeader> varLenHeaders() const {
        return mVarLenHeaders;
    }

 private:
    LAS1_2PubHeader mPubHeader;
    std::vector<LAS1_2VarLenHeader> mVarLenHeaders;
};

#endif
