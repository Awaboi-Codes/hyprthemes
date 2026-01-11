#include "src/filesys.hpp"
#include "src/imports.hpp"
#include "src/strings.hpp"
#include "src/simdjson.h"

std::string execCommand(const std::string& cmd) {
    std::array<char, 128> buffer;
    std::string result;
    
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    
    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: hyprthemes <command>" << std::endl;
        return 1;
    }
    
    std::string command = argv[1];  // First argument after program name
    
    
    // "set" command
    if (command == "set") {
        std::cout << "Running 'set' command..." << std::endl;
        const char* home = std::getenv("HOME");
        if (!home) {
            std::cout << "HOME not set" << std::endl;
            return 1;
        }
        
        std::string homestr = home;
        std::string themeName = argv[2];
        
        std::string path = homestr + "/.config/hyprthemes/themes/" + themeName + "/config.json";
        std::string configcontents = getFileContents(path);
        
        if (configcontents.empty()) {
            std::cout << "Config file either empty or doesn't exist." << std::endl;
            return 1;
        }
        
        std::cout << "Config file exists.\nReading config.json..." << std::endl;
        
        // Keep parser alive for the lifetime of the document
        simdjson::dom::parser parser;
        simdjson::dom::element configjson;
        
        auto error = parser.parse(configcontents).get(configjson);
        if (error) {
            std::cerr << "JSON parse error: " << simdjson::error_message(error) << std::endl;
            return 1;
        }
        
        // Safely get "folders" object
        simdjson::dom::element folders_element;
        auto err = configjson["folders"].get(folders_element);
        if (err) {
            std::cerr << "'folders' key missing or invalid: " << simdjson::error_message(err) << std::endl;
            return 1;
        }
        
        if (!folders_element.is_object()) {
            std::cerr << "'folders' is not an object!" << std::endl;
            return 1;
        }

        

        // folders parsing
        simdjson::dom::object obj = folders_element;
        std::map<std::string, std::string> folders;
        
        for (auto field : obj) {
            std::string_view key = field.key;
            std::string_view value;
            
            if (field.value.get(value)) {
                std::cerr << "Invalid value for key: " << key << "\n";
                continue;
            }
            
            folders[std::string(key)] = std::string(value);
        }
        


        // folders going from themes -> .config
        std::cout << "Folders found:\n";
        for (const auto &[name, path] : folders) {
            std::cout << name << " = " << path << "\n";
            str command = "rm -r " + path;
            execCommand(command);
            command = "cp -r ~/.config/hyprthemes/themes/" + themeName + "/" + name + " " + path;
            execCommand(command);
        }
        
        return 0;
    } 
    

    // "get" command
    else if (command == "get") {
        std::cout << "Running 'get' command..." << std::endl;
        const char* home = std::getenv("HOME");
        if (!home) {
            std::cout << "HOME not set" << std::endl;
            return 1;
        }
        
        std::string homestr = home;
        std::string themeName = argv[2];
        
        std::string path = homestr + "/.config/hyprthemes/themes/" + themeName + "/config.json";
        std::string configcontents = getFileContents(path);
        
        if (configcontents.empty()) {
            std::cout << "Config file either empty or doesn't exist." << std::endl;
            return 1;
        }
        
        std::cout << "Config file exists.\nReading config.json..." << std::endl;
        
        // Keep parser alive for the lifetime of the document
        simdjson::dom::parser parser;
        simdjson::dom::element configjson;
        
        auto error = parser.parse(configcontents).get(configjson);
        if (error) {
            std::cerr << "JSON parse error: " << simdjson::error_message(error) << std::endl;
            return 1;
        }
        
        // Safely get "folders" object
        simdjson::dom::element folders_element;
        auto err = configjson["folders"].get(folders_element);
        if (err) {
            std::cerr << "'folders' key missing or invalid: " << simdjson::error_message(err) << std::endl;
            return 1;
        }
        
        if (!folders_element.is_object()) {
            std::cerr << "'folders' is not an object!" << std::endl;
            return 1;
        }
        
        simdjson::dom::object obj = folders_element;
        std::map<std::string, std::string> folders;
        
        for (auto field : obj) {
            std::string_view key = field.key;
            std::string_view value;
            
            if (field.value.get(value)) {
                std::cerr << "Invalid value for key: " << key << "\n";
                continue;
            }
            
            folders[std::string(key)] = std::string(value);
        }
        
        std::cout << "Folders found:\n";
        for (const auto &[name, path] : folders) {
            std::cout << name << " = " << path << "\n";
            str command = "cp -r " + path + " ~/.config/hyprthemes/themes/" + themeName + "/" + name;
            execCommand(command);
        }
        
        return 0;
        
    } else {
        std::cout << "Unknown command: " << command << std::endl;
        return 1;
    }
}