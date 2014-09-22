#ifndef __GENERIC_HEADER_H__
#define __GENERIC_HEADER_H__

#include "ImageIO.h"
#include <string>

class GenericHeader : public ImageIO
{
    public: 
        virtual std::string ToString() = 0;
};

#endif
