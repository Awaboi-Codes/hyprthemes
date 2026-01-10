#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

namespace fs = std::filesystem;

using str = std::string;
using ostream = std::ostringstream;
using fstream = std::ifstream;

str getFileContents(const str& filename) {
    fstream file(filename);
    if (!file) {
        std::cerr << "Could not open the file " << filename << '\n';
        return "";
    }
    ostream content_stream;
    content_stream << file.rdbuf();
    return content_stream.str();
}

bool copyFile(const str& source, const str& destination) {
    try {
        // fs::copy_file(from: source, to: destination, option: fs::copy_options::option)
        fs::copy_file(
            source,
            destination,
            fs::copy_options::overwrite_existing
        );
        return true;
    } 
    // Error Catching
    catch (const fs::filesystem_error& e) {
        std::cerr << "Copy failed: " << e.what() << '\n';
        return false;
    }
}