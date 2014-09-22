/////////////////////////////////////////////////////////////////////////////// 
// File: LAS1_2.h
//
// 
/////////////////////////////////////////////////////////////////////////////// 
#ifndef __LAS_1_2_PUBLIC_HEADER_H__
#define __LAS_1_2_PUBLIC_HEADER_H__
#include "GenericHeader.h"

#include <vector>
#include <string>
#include <sstream>
#include <exception>
#include <iostream>

class LAS1_2PubHeader : public GenericHeader
{
    public:
        LAS1_2PubHeader();
        ~LAS1_2PubHeader();
        void Read( std::istream& inStream ); 
        void Write( std::ostream& outStream ); 
        std::string ToString(); 

        std::string FileSignature() const {return mFileSignature;}
        void FileSignature(const std::string& pFileSignature)
        {
            if( pFileSignature.size() <= FILE_SIGNATURE_SIZE )
            {
                mFileSignature = pFileSignature;
            }
            else
            {
//                std::stringstream ss;
//                ss << "parameter not equal to " << FILE_SIGNATURE_SIZE ;
                throw;// std::exception( ss.str().c_str());
            }
        }
        unsigned short FileSourceID() const {return mFileSourceID;}
        void FileSourceID(unsigned short pFileSourceID)
        {
            mFileSourceID = pFileSourceID;
        }
        unsigned short GlobalEncoding() const {return mGlobalEncoding;}
        void GlobalEncoding(unsigned short pGlobalEncoding)
        {
            mGlobalEncoding = pGlobalEncoding;
        }
        unsigned long ProjectIDGUIDdata1() const {return mProjectIDGUIDdata1;}
        void ProjectIDGUIDdata1(unsigned long pProjectIDGUIDdata1)
        {
            mProjectIDGUIDdata1 = pProjectIDGUIDdata1;
        }
        unsigned short ProjectIDGUIDdata2() const {return mProjectIDGUIDdata2;}
        void ProjectIDGUIDdata2(unsigned short pProjectIDGUIDdata2)
        {
            mProjectIDGUIDdata2 = pProjectIDGUIDdata2;
        }
        unsigned short ProjectIDGUIDdata3() const {return mProjectIDGUIDdata3;}
        void ProjectIDGUIDdata3(unsigned short pProjectIDGUIDdata3)
        {
            mProjectIDGUIDdata3 = pProjectIDGUIDdata3;
        }
        std::vector<unsigned char> ProjectIDGUIDdata4() const {return mProjectIDGUIDdata4;}
        void ProjectIDGUIDdata4(const std::vector<unsigned char>& pProjectIDGUIDdata4)
        {
            if( pProjectIDGUIDdata4.size() ==  PROJECT_ID_GUID_DATA_4_SIZE) 
            {
                mProjectIDGUIDdata4 = pProjectIDGUIDdata4;
            }
            else
            {
                throw;
            }
        }
        unsigned char VersionMajor() const {return mVersionMajor;}
        void VersionMajor(unsigned char pVersionMajor)
        {
            mVersionMajor = pVersionMajor;
        }
        unsigned char VersionMinor() const {return mVersionMinor;}
        void VersionMinor(unsigned char pVersionMinor)
        {
            mVersionMinor = pVersionMinor;
        }
        std::string SystemIdentifier() const {return mSystemIdentifier;}
        void SystemIdentifier(const std::string pSystemIdentifier)
        {
            if( pSystemIdentifier.size() <= SYSTEM_IDENTIFIER_SIZE) 
            {
                mSystemIdentifier = pSystemIdentifier;
            }
            else
            {
                throw;
            }
        }
        std::string GeneratingSoftware() const {return mGeneratingSoftware;}
        void GeneratingSoftware(const std::string& pGeneratingSoftware)
        {
            if( pGeneratingSoftware.size() <= GENERATING_SOFTWARE_SIZE )
            {   
                mGeneratingSoftware = pGeneratingSoftware;
            }
            else
            {
                throw;
            }
        }
        unsigned short FileCreationDayOfYear() const {return mFileCreationDayOfYear;}
        void FileCreationDayOfYear(unsigned short pFileCreationDayOfYear)
        {
            mFileCreationDayOfYear = pFileCreationDayOfYear;
        }
        unsigned short FileCreationYear() const {return mFileCreationYear;}
        void FileCreationYear(unsigned short pFileCreationYear)
        {
            mFileCreationYear = pFileCreationYear;
        }
        unsigned short HeaderSize() const {return mHeaderSize;}
        void HeaderSize(unsigned short pHeaderSize)
        {
            mHeaderSize = pHeaderSize;
        }
        unsigned long OffsetToPointData() const {return mOffsetToPointData;}
        void OffsetToPointData(unsigned long pOffsetToPointData)
        {
            mOffsetToPointData = pOffsetToPointData;
        }
        unsigned long NumberOfVariableLengthRecords() const {return mNumberOfVariableLengthRecords;}
        void NumberOfVariableLengthRecords(unsigned long pNumberOfVariableLengthRecords)
        {
            mNumberOfVariableLengthRecords = pNumberOfVariableLengthRecords;
        }
        unsigned char PointDataFormatID() const {return mPointDataFormatID;}
        void PointDataFormatID(unsigned char pPointDataFormatID)
        {
            mPointDataFormatID = pPointDataFormatID;
        }
        unsigned short PointDataRecordLength() const {return mPointDataRecordLength;}
        void PointDataRecordLength(unsigned short pPointDataRecordLength)
        {
            mPointDataRecordLength = pPointDataRecordLength;
        }
        unsigned long NumberOfPointRecord() const {return mNumberOfPointRecord;}
        void NumberOfPointRecord(unsigned long pNumberOfPointRecord)
        {
            mNumberOfPointRecord = pNumberOfPointRecord;
        }
        std::vector<unsigned long> NumberOfPointsByReturn() const {return mNumberOfPointsByReturn;}
        void NumberOfPointsByReturn(const std::vector<unsigned long>& pNumberOfPointsByReturn)
        {
            if( pNumberOfPointsByReturn.size() == NUMBER_OF_POINTS_BY_RETURN_SIZE )
            {
                mNumberOfPointsByReturn = pNumberOfPointsByReturn;
            }
            else
            {
                throw;
            }
        }
        double XScaleFactor() const {return mXScaleFactor;}
        void XScaleFactor(double pXScaleFactor)
        {
            mXScaleFactor = pXScaleFactor;
        }
        double YScaleFactor() const {return mYScaleFactor;}
        void YScaleFactor(double pYScaleFactor)
        {
            mYScaleFactor = pYScaleFactor;
        }
        double ZScaleFactor() const {return mZScaleFactor;}
        void ZScaleFactor(double pZScaleFactor)
        {
            mZScaleFactor = pZScaleFactor;
        }
        double XOffset() const {return mXOffset;}
        void XOffset(double pXOffset)
        {
            mXOffset = pXOffset;
        }
        double YOffset() const {return mYOffset;}
        void YOffset(double pYOffset)
        {
            mYOffset = pYOffset;
        }
        double ZOffset() const {return mZOffset;}
        void ZOffset(double pZOffset)
        {
            mZOffset = pZOffset;
        }
        double XMax() const {return mXMax;}
        void XMax(double pXMax)
        {
            mXMax = pXMax;
        }
        double XMin() const {return mXMin;}
        void XMin(double pXMin)
        {
            mXMin = pXMin;
        }
        double YMax() const {return mYMax;}
        void YMax(double pYMax)
        { mYMax = pYMax;
        }
        double YMin() const {return mYMin;}
        void YMin(double pYMin)
        {
            mYMin = pYMin;
        }
        double ZMax() const {return mZMax;}
        void ZMax(double pZMax)
        {
            mZMax = pZMax;
        }
        double ZMin() const {return mZMin;}
        void ZMin(double pZMin)
        {
            mZMin = pZMin;
        }
        
        static const int FILE_SIGNATURE_SIZE = 4;
        static const int PROJECT_ID_GUID_DATA_4_SIZE = 8;
        static const int SYSTEM_IDENTIFIER_SIZE = 32;
        static const int GENERATING_SOFTWARE_SIZE = 32;
        static const int NUMBER_OF_POINTS_BY_RETURN_SIZE = 5;
        static const int PUB_HEADER_BYTE_SIZE = 227;

    private:
        std::string                 mFileSignature;
        unsigned short              mFileSourceID;
        unsigned short              mGlobalEncoding;
        unsigned long               mProjectIDGUIDdata1;
        unsigned short              mProjectIDGUIDdata2;
        unsigned short              mProjectIDGUIDdata3;
        std::vector<unsigned char>  mProjectIDGUIDdata4;
        unsigned char               mVersionMajor;
        unsigned char               mVersionMinor;
        std::string                 mSystemIdentifier;
        std::string                 mGeneratingSoftware;
        unsigned short              mFileCreationDayOfYear;
        unsigned short              mFileCreationYear;
        unsigned short              mHeaderSize;
        unsigned long               mOffsetToPointData;
        unsigned long               mNumberOfVariableLengthRecords;
        unsigned char               mPointDataFormatID;
        unsigned short              mPointDataRecordLength;
        unsigned long               mNumberOfPointRecord;
        std::vector<unsigned long>  mNumberOfPointsByReturn;
        double                      mXScaleFactor;
        double                      mYScaleFactor;
        double                      mZScaleFactor;
        double                      mXOffset;
        double                      mYOffset;
        double                      mZOffset;
        double                      mXMax;
        double                      mXMin;
        double                      mYMax;
        double                      mYMin;
        double                      mZMax;
        double                      mZMin;
};

#endif
