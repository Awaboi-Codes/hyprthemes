#include "imports.cpp"

str getFileContents(const str& filename) {
    fstream file(filename);
    if (!file) {
        std::cout << "Could not open the file " << filename << std::endl;
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
        std::cout << "Copy failed: " << e.what() << std::endl;
        return false;
    }
}