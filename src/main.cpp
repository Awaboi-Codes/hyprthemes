#include <iostream>
#include <filesystem> // C++17
#include <string>

namespace fs = std::filesystem;

int main() {
    std::string source_folder = "~/.hyprthemes";
    std::string destination_folder = "~/.config";

    try {
        // Make sure destination exists
        if (!fs::exists(destination_folder)) {
            fs::create_directories(destination_folder);
        }

        for (const auto& entry : fs::directory_iterator(source_folder)) {
            const auto& path = entry.path();

            if (fs::is_regular_file(path)) { // only copy files, not directories
                fs::copy_file(path, destination_folder + "/" + path.filename().string(),
                              fs::copy_options::overwrite_existing);
                std::cout << "Copied " << path << " to " << destination_folder << "\n";
            }
        }

    } catch (fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << "\n";
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}

