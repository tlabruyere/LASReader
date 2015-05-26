#ifndef __GENERIC_HEADER_H__
#define __GENERIC_HEADER_H__

#include "ImageIO.h"
#include <string>

class GenericHeader : public ImageIO {
 public: 
    virtual std::string ToString() const = 0;

    static const int SIZE_OF_CHAR = sizeof(char);
//    static const int SIZE_OF_CHAR = 1;
    static const int SIZE_OF_SHORT = SIZE_OF_CHAR*2;
    static const int SIZE_OF_LONG = SIZE_OF_CHAR*4;
    static const int SIZE_OF_DOUBLE = SIZE_OF_CHAR*8;
};

#endif
