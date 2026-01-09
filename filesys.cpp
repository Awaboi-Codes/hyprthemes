#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

namespace fs = std::filesystem;

using str = std::string;

str getFileContents(const str& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open the file " << filename << '\n';
        return "";
    }

    std::ostringstream content_stream;
    content_stream << file.rdbuf();
    return content_stream.str();
}

bool copyFile(const str& source, const str& destination) {
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