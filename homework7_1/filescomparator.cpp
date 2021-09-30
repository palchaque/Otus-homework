#include "filescomparator.h"

filesComparator::filesComparator()
{
    fileBlockSize = 5;
    scanMode = 0;
    minimalFileSize = 1;
    fileMask = "";
}

void filesComparator::setFileBlockSize(const size_t size)
{
    fileBlockSize = size;
}

void filesComparator::setExcludedDirectories(const std::vector<std::string> excludedDirs)
{
    excludedDirectories = excludedDirs;
}

void filesComparator::setFileMask(const std::string mask)
{
    fileMask = mask;
}

void filesComparator::setMinimalFileSize(const size_t size)
{
    minimalFileSize = size;
}

void filesComparator::setScanMode(const unsigned int mode)
{
    scanMode = mode;
}

void filesComparator::setScannedDirectory(const std::string scannedDir)
{
    scannedDirectory = scannedDir;
}

std::map<std::string, std::vector<std::string>> filesComparator::getEqualFiles()
{
    scanDirectory(bfs::path(scannedDirectory));

    std::vector<std::string> tempCommonFilesPathes;
    tempCommonFilesPathes.reserve(comparedFiles.size());

    std::map<std::string, std::vector<std::string>> commonFiles;

    for(auto fileIterator = std::begin(comparedFiles); fileIterator != std::end(comparedFiles); ++fileIterator)
    {
        if(std::find(std::cbegin(tempCommonFilesPathes), std::cend(tempCommonFilesPathes), fileIterator->get()->getFullPath()) != std::end(tempCommonFilesPathes)) continue;;

        std::vector otherFiles(std::next(fileIterator), std::end(comparedFiles));

        for(auto otherFile : otherFiles)
        {
            size_t minimalBlockSize = std::min(otherFile->getBlocksCount(), fileIterator->get()->getBlocksCount());
            for(int block = 0; block <= minimalBlockSize; block++)
            {
                if(fileIterator->get()->readBlock(block) != otherFile->readBlock(block))
                {
                    block = minimalBlockSize;
                    continue;
                }
                if(block == minimalBlockSize && block != 0)
                {
                    commonFiles[fileIterator->get()->getFullPath()].push_back(otherFile.get()->getFullPath());
                    tempCommonFilesPathes.push_back(fileIterator->get()->getFullPath());
                    tempCommonFilesPathes.push_back(otherFile.get()->getFullPath());
                }
            }
        }

    }

    return commonFiles;

}

void filesComparator::scanDirectory(const bfs::path path)
{
    if(!bfs::exists(path)) return;

    for (bfs::directory_entry& dirContent : bfs::directory_iterator(path))
    {

        if (bfs::is_directory(dirContent) && scanMode == 1)
        {            
            if(!excludedDirectories.empty() && (std::find(std::cbegin(excludedDirectories), std::cend(excludedDirectories), dirContent.path()) == std::cend(excludedDirectories)))
            scanDirectory(bfs::path(dirContent));
        }

        if (bfs::is_regular_file(dirContent))
        {
            if (bfs::file_size(dirContent) < minimalFileSize) continue;

            std::string fileName = dirContent.path().filename().string();
            if (!fileMask.empty())
            {
                boost::regex fileMaskExp(fileMask, boost::regex::icase);
                if (!boost::regex_match(fileName, fileMaskExp)) continue;
            }

            scannedFile file;
            file.setFileSize(bfs::file_size(dirContent.path()));
            file.setFileFullPath(dirContent.path().string());
            file.setFileName(fileName);
            file.setFileBlockSize(fileBlockSize);

            comparedFiles.push_back(std::make_shared<scannedFile>(file));

        }

    }

}

