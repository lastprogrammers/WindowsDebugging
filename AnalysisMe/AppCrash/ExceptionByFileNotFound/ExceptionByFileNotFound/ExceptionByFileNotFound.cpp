// ExceptionByFileNotFound.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <direct.h>
#include <string>
#include <exception>

class FileNotFoundound : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "FileNotFound";
    }
};

void LoadConfigFile()
{
    char dirPath[_MAX_PATH];
    _getcwd(dirPath, sizeof(dirPath));
    
    std::string configPath;
    std::string configName = "MyConfigFile.txt";

    configPath = dirPath;
    configPath += "\\" + configName;

    FILE* file;
    fopen_s(&file, configPath.c_str(), "r");
    if (file)
    {
        std::cout << configName << std::endl;        
        fclose(file);
        system("pause");
    }
    else 
    {
        throw FileNotFoundound();
    }
}

int main()
{
    LoadConfigFile();
    return 0;
}
