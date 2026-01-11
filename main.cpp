#include "src/filesys.cpp"
#include "src/json.cpp"
#include "src/imports.cpp"
#include "src/strings.cpp"

int main() {
    const char* home = std::getenv("HOME");
    str homestr = {home};
    if (!home) {
        std::cout << "HOME not set" << std::endl;
        return 1;
    }
    std::cout << "Input theme name: ";

    str themeName;
    std::cin >> themeName;

    str path = homestr + "/.config/hyprthemes/themes/" + themeName;
    str configcontents = getFileContents(path + "/config.json");
    if (configcontents != "") {
        std::cout << "Config file exists." << std::endl;
    } else {
        std::cout << "Config file either empty or doesn't exist." << std::endl;
    }

    configcontents = replaceInstances(configcontents, "", "\n");
    configcontents = replaceInstances(configcontents, "", " ");
    std::cout << configcontents << std::endl;
}