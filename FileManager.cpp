
#include "FileManager.h"

#include <fstream>
#include <iostream>

using namespace std;

// Save records to a text file
bool FileManager::saveLines(
    const string& filename,
    const vector<string>& records)
{
    ofstream file(filename);

    if (!file.is_open())
    {
        cerr << "Error: Could not open "
             << filename << " for saving.\n";
        return false;
    }

    for (const string& record : records)
    {
        file << record << '\n';

        if (!file)
        {
            cerr << "Error while writing to "
                 << filename << ".\n";
            return false;
        }
    }

    file.close();

    if (file.fail())
    {
        cerr << "Error while closing "
             << filename << ".\n";
        return false;
    }

    return true;
}

// Load records from a text file
vector<string> FileManager::loadLines(
    const string& filename)
{
    vector<string> records;
    ifstream file(filename);

    // A missing file is treated as an empty file.
    if (!file.is_open())
        return records;

    string line;

    while (getline(file, line))
        records.push_back(line);

    if (file.bad())
    {
        cerr << "Error while reading "
             << filename << ".\n";
        records.clear();
    }

    return records;
}