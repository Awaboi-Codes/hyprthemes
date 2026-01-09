#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

namespace fs = std::filesystem;

std::string getFileContents(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open the file " << filename << '\n';
        return "";
    }

    std::ostringstream content_stream;
    content_stream << file.rdbuf();
    return content_stream.str();
}

bool copyFile(const std::string& source, const std::string& destination) {
    try {
        fs::copy_file(
            source,
            destination,
            fs::copy_options::overwrite_existing
        );
        return true;
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Copy failed: " << e.what() << '\n';
        return false;
    }
}

int main() {
    const char* home = std::getenv("HOME");
    if (!home) {
        std::cerr << "HOME not set\n";
        return 1;
    }

    std::string path = std::string(home) + "/.config/hyprthemes/config.txt";

    std::string contents = getFileContents(path);
    std::cout << contents << '\n';
}