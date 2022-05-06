#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>

#define FILE_COUNT 3
#define PATH_SIZE 1000
#define COMMAND_SIZE 2000

int main() {
    const std::string FILES[FILE_COUNT] = {"helloworld.cpp", "helloworld.h", "README.md"};
    char path[PATH_SIZE] = {'\0'}; // Buffer to hold the filepath
    char command[COMMAND_SIZE] = {'\0'}; // Buffer to hold our command

    
    for (size_t i = 0; i < FILE_COUNT; ++i) {
        // Set up the path in the form of ./file-name
        strcpy(path, "./");
        strcat(path, FILES[i].c_str());

        // Set up the commmand, starting with the bash "test" cmd to check for file existence
        strcpy(command, "test -f ");
        strcat(command, path);
        
        // Check if we found the file in the current directory, exit status = 0 if tested condition is true
        if (system(command) == 0) {
            std::cout << FILES[i] << " exists in the current directory.\n";
        }
        else {
            std::cout << FILES[i] << " does not exist in the current directory.\n";
        }
    }

    std::cout << "\n\n";

    return 0;
}