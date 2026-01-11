#include "src/filesys.hpp"
#include "src/imports.hpp"
#include "src/strings.hpp"
#include "src/simdjson.h"

simdjson::dom::element parseJson(const std::string &contents) {
    simdjson::dom::parser parser;
    simdjson::dom::element jsonfile;
    auto error = parser.parse(contents).get(jsonfile);
    if (error) {
        throw std::runtime_error(std::string("JSON parse error: ") + simdjson::error_message(error));
    }
    return jsonfile;
}

int main() {
    const char* home = std::getenv("HOME");
    if (!home) {
        std::cout << "HOME not set" << std::endl;
        return 1;
    }
    std::string homestr = home;

    std::cout << "Input theme name: ";
    std::string themeName;
    std::cin >> themeName;

    std::string path = homestr + "/.config/hyprthemes/themes/" + themeName + "/config.json";
    std::string configcontents = getFileContents(path);

    if (configcontents.empty()) {
        std::cout << "Config file either empty or doesn't exist." << std::endl;
        return 1;
    }
    std::cout << "Config file exists.\nReading config.json..." << std::endl;

    simdjson::dom::element configjson;
    try {
        configjson = parseJson(configcontents);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    // Safely get "folders" array
    simdjson::dom::element folders_element;
    auto err = configjson["folders"].get(folders_element);
    if (err) {
        std::cerr << "'folders' key missing or invalid: " << simdjson::error_message(err) << std::endl;
        return 1;
    }

    if (!folders_element.is_array()) {
        std::cerr << "'folders' is not an array!" << std::endl;
        return 1;
    }

    simdjson::dom::array arr = folders_element;
    std::vector<std::string> folders;

    for (simdjson::dom::element e : arr) {
        std::string_view folder;
        if (e.get(folder)) {
            std::cerr << "Invalid element in folders array\n";
            continue;
        }
        folders.emplace_back(folder); // safe copy
    }

    std::cout << "Folders found:\n";
    for (const auto &f : folders) {
        std::cout << f << "\n";
    }

    return 0;
}
