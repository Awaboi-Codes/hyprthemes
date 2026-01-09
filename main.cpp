#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
    fs::copy_file(
        "source.txt",
        "dest.txt",
        fs::copy_options::overwrite_existing
    );
}
