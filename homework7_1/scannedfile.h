#ifndef SCANNEDFILE_H
#define SCANNEDFILE_H

#include <iostream>
#include <vector>
#include <string>

#include <boost/filesystem.hpp>
#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/serialization/string.hpp>
#include <boost/format.hpp>

#include <boost/functional/hash.hpp>

class scannedFile
{
public:
    explicit scannedFile();
    scannedFile(const scannedFile&);
    scannedFile& operator=(const scannedFile&);
    ~scannedFile() = default;
    void setFileSize(const size_t);
    void setFileBlockSize(const size_t);
    void setFileFullPath(const std::string);
    void setFileName(const std::string);
    std::string readBlock(unsigned int block);
    const std::string operator << (const scannedFile&);
    const std::vector<std::string>& getFileData();
    const std::string& getFullPath();
    size_t & getBlockSize();
    size_t & getFileSize();
    size_t & getBlocksCount();

private:
    const boost::interprocess::mode_t fileReadMode = boost::interprocess::read_only;
    size_t fileSize;
    size_t blockSize;
    size_t blocksCount;
    std::string fullPath;
    std::string fileName;
    std::vector<std::string> fileData;
    void calculateDataSize();

};

#endif // SCANNEDFILE_H
