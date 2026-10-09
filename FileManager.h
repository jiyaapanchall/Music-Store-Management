
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>

class FileManager
{
public:
    // Save a collection of records to a text file
    static bool saveLines(
        const std::string& filename,
        const std::vector<std::string>& records
    );

    // Read records from a text file
    static std::vector<std::string> loadLines(
        const std::string& filename
    );
};

#endif