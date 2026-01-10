#ifndef HYPRTHEMES_FILESYS_HPP
#define HYPRTHEMES_FILESYS_HPP

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

str getFileContents(const str& filename);

bool copyFile(const str& source, const str& destination);

#endif

