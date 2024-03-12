#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>
#include <vector>

class CSVReader {
    std::string fileName;

public:
    CSVReader(const std::string& fileName)
        : fileName(fileName) {}

    std::vector<std::vector<std::string>> readFile();

    void writeFile(const std::vector<std::vector<std::string>>& data);
};

#endif // CSVREADER_H