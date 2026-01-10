#ifndef HYPRTHEMES_FILESYS_HPP
#define HYPRTHEMES_FILESYS_HPP

#include <filesystem>
#include <string>

namespace fs = std::filesystem;

using str = std::string;
using ostream = std::ostringstream;
using fstream = std::ifstream;

using str = std::string;

str getFileContents(const str& filename);

bool copyFile(const str& source, const str& destination);

#endif

