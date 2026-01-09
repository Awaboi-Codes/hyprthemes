#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "filesys.hpp"

namespace fs = std::filesystem;

int main() {
    const char* home = std::getenv("HOME");
    if (!home) {
        std::cerr << "HOME not set\n";
        return 1;
    }
    std::cout << "Input theme name: ";

    std::string themeName;
    std::cin >> themeName;

    std::string path = std::string(home) + "/.config/hyprthemes/themes/" + themeName + "/config.json";

    std::string contents = getFileContents(path);
    std::cout << contents << '\n';
}