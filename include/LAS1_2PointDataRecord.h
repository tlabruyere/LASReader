/////////////////////////////////////////////////////////////////////////////// 
// File: LAS1_2PointDataRecord.h
//
// 
/////////////////////////////////////////////////////////////////////////////// 
#ifndef __LAS1_2_POINT_DATA_RECORD_H__
#define __LAS1_2_POINT_DATA_RECORD_H__

#include "GenericHeader.h"
class LAS1_2VarLenHeader : public GenericHeader {
public:
    LAS1_2VarLenHeader();
    virtual ~LAS1_2VarLenHeader();
    void Read(std::istream& inStream); 
    void Write( std::ostream& outStream ) const; 
    std::string ToString() const;
private:
    long X;
    long Y;
    long Z;
    short intensity;
    short retInfo; // (Return Number (bits 0, 1, 2),
                    // num of Ret (given pulse) (bits 3, 4, 5)
                    // Scan Direction Flag 1 bit (bit 6)
                    // Edge of Flight Line 1 bit (bit 7)
    unsigned char Classification;
    char ScanAngleRank // (-90 to +90) – Left side
    unsigned char UserData;
    unsigned short PointSourceID;
};

#endif


