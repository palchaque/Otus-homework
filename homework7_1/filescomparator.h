#ifndef FILESCOMPARATOR_H
#define FILESCOMPARATOR_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include <boost/filesystem.hpp>
#include <boost/regex.hpp>

#include "scannedfile.h"

namespace bfs = boost::filesystem;
namespace bip = boost::interprocess;

class filesComparator
{
public:    
    filesComparator();
    std::map<std::string, std::vector<std::string>> getEqualFiles();
    void setFileBlockSize(const size_t);
    void setScannedDirectory(const std::string);
    void setExcludedDirectories(const std::vector<std::string>);
    void setScanMode(const unsigned int);
    void setMinimalFileSize(const size_t);
    void setFileMask(const std::string);

private:
    size_t fileBlockSize;
    std::vector<std::shared_ptr<scannedFile>> comparedFiles;
    std::string scannedDirectory;
    std::vector<std::string> excludedDirectories;
    unsigned int scanMode; // 0 - scan only scannedDirectory, 1 - with subDirectories;
    size_t minimalFileSize;
    std::string fileMask; //regex

    void scanDirectory(const bfs::path);
};

#endif // FILESCOMPARATOR_H
