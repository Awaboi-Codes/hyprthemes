#ifndef FILESYS_HPP
#define FILESYS_HPP

#include "imports.hpp"

str getFileContents(const str& filename);

bool copyFile(const str& source, const str& destination);

#endif