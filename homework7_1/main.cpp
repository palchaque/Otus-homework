#include <iostream>
#include <boost/program_options.hpp>

#include "filescomparator.h"

namespace bpo = boost::program_options;

int main(int argc, char* argv[])
{

    bpo::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        ("scanDir", bpo::value<std::string>(), "set scanned directory")
        ("excludedDirs", bpo::value<std::vector<std::string>>()->multitoken(), "set excluded directories")
        ("level", bpo::value<int>()->default_value(0), "set scan level: 0 - scan only scanDir, 1 - scan with subdirs")
        ("fileSize", bpo::value<size_t>()->default_value(1), "set minimal file size in bytes")
        ("fileMasks", bpo::value<std::string>(), "set regular expression for files")
        ("blockSize", bpo::value<size_t>()->default_value(5), "set readed block size in bytes");

    bpo::variables_map vm;
    bpo::store(bpo::parse_command_line(argc, argv, desc), vm);
    bpo::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    filesComparator comparator;

    if (vm.count("scanDir")) {
        comparator.setScannedDirectory(vm["scanDir"].as<std::string>());
    } else {
        std::cout << "Compression level was not set.\n";
        return 1;
    }

    if (vm.count("excludedDirs")) {
        comparator.setExcludedDirectories(vm["excludedDirs"].as<std::vector<std::string>>());
    }

    if (vm.count("level")) {
        comparator.setScanMode(vm["level"].as<int>());
    }

    if (vm.count("fileSize")) {
        comparator.setMinimalFileSize(vm["fileSize"].as<size_t>());
    }

    if (vm.count("blockSize")) {
        comparator.setFileBlockSize(vm["blockSize"].as<size_t>());
    }

    auto commonFiles = comparator.getEqualFiles();

    for (const auto& [key, value] : commonFiles) {
            std::cout << key;
        for (const auto& val : value){
            std::cout<<val;
        }
        std::cout<<std::endl;
    }

    return 0;

}
