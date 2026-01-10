#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "filesys.cpp"

int main() {
    const char* home = std::getenv("HOME");
    if (!home) {
        std::cerr << "HOME not set\n";
        return 1;
    }
    std::cout << "Input theme name: ";

    str themeName;
    std::cin >> themeName;

    str path = "~/.config/hyprthemes/themes/" + themeName + "/config.json";

    str contents = getFileContents(path);
    std::cout << contents << '\n';
}