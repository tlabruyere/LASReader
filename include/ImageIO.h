#ifndef ___IMAGE_IO_H__
#define ___IMAGE_IO_H__

#include <istream>
#include <ostream>

class ImageIO
{
    public: 
        virtual void Read( std::istream& inStream ) = 0; 
        virtual void Write( std::ostream& outStream ) = 0; 
};


#endif
