#include "filesys.cpp"
#include "imports.cpp"

int main() {
    const char* home = std::getenv("HOME");
    str homestr = {home};
    if (!home) {
        std::cout << "HOME not set" << std::endl;
        return 1;
    }
    std::cout << "Input theme name: " << std::endl;

    str themeName;
    std::cin >> themeName;

    str path = homestr + "/.config/hyprthemes/themes/" + themeName;
    str configcontents = getFileContents(path + "/config.json");
    if (configcontents != "") {
        std::cout << "Config file exists." << std::endl;
    } else {
        std::cout << "Config file either empty or doesn't exist." << std::endl;
    }

    std::cout << configcontents << std::endl;
}