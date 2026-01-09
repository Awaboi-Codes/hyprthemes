#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "filesys.hpp"

namespace fs = std::filesystem;

using str = std::string;

int main() {
    const char* home = std::getenv("HOME");
    if (!home) {
        std::cerr << "HOME not set\n";
        return 1;
    }
    std::cout << "Input theme name: ";

    str themeName;
    std::cin >> themeName;

    str path = str(home) + "/.config/hyprthemes/themes/" + themeName + "/config.json";

    str contents = getFileContents(path);
    std::cout << contents << '\n';
}