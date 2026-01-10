#include "filesys.cpp"
#include <iostream>

int main() {
    const char* home = std::getenv("HOME");
    str homestr = {home};
    if (!home) {
        std::cout << "HOME not set\n";
        return 1;
    }
    std::cout << "Input theme name: ";

    str themeName;
    std::cin >> themeName;

    str path = homestr + "/.config/hyprthemes/themes/" + themeName + "/config.json";
    str contents = getFileContents(path);
    if (contents != "") {
        std::cout << "Config file exists.";
    } else {
        std::cout << "Config file either empty or doesn't exist.";
    }

    std::cout << contents << '\n';
}