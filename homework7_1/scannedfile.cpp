#include "scannedfile.h"

scannedFile::scannedFile()
{
    fileSize = 0;
    blockSize = 0;
    blocksCount = 0;

}

void scannedFile::setFileSize(const size_t size)
{
    fileSize = size;
    calculateDataSize();
}

void scannedFile::setFileBlockSize(const size_t size)
{
    blockSize = size;
    calculateDataSize();
}


void scannedFile::calculateDataSize()
{
    if(fileSize == 0 || blockSize == 0)
        return;

    blocksCount = std::ceil(fileSize/blockSize);
    fileData.reserve(blocksCount);

}

void scannedFile::setFileFullPath(const std::string path)
{
    fullPath = path;
}

void scannedFile::setFileName(const std::string path)
{
    fileName = path;
}

const std::string& scannedFile::getFullPath()
{
    return fullPath;
}

const std::vector<std::string>& scannedFile::getFileData()
{
    return fileData;
}

const std::string scannedFile::operator<<(const scannedFile &file)
{
    return file.fullPath;
}

scannedFile::scannedFile(const scannedFile &file)
{
    fileSize = file.fileSize;
    blockSize = file.blockSize;
    fullPath = file.fullPath;
    fileName = file.fileName;
    fileData = file.fileData;
    blocksCount = file.blocksCount;

}

scannedFile& scannedFile::operator=(const scannedFile &file)
{
    if (this == &file) return *this;

    fileSize = file.fileSize;
    blockSize = file.blockSize;
    fullPath = file.fullPath;
    fileName = file.fileName;
    fileData = file.fileData;
    blocksCount = file.blocksCount;

    return *this;

}

size_t & scannedFile::getBlockSize()
{
    return blockSize;
}

size_t & scannedFile::getBlocksCount()
{
    return blocksCount;
}

size_t & scannedFile::getFileSize()
{
    return fileSize;
}

std::string scannedFile::readBlock(unsigned int block)
{
    if (fileData.size() > block) return fileData.at(block);

    boost::interprocess::file_mapping mapping(fullPath.c_str(), fileReadMode);

    boost::interprocess::mapped_region blockRegion(mapping, fileReadMode, blockSize*block, blockSize);

    const char *begin = static_cast<const char*>(
        blockRegion.get_address()
    );

    boost::format formatter("%-0"+std::to_string(blockSize)+"x");

    std::string str = boost::str(formatter % begin);

    boost::hash<std::string> string_hash;

    std::string hashedString = std::to_string(string_hash(str));

    fileData.push_back(hashedString);

    return hashedString;

}


