#include "imports.cpp"

str replaceInstances(str input, str replacer, str tobereplaced) {
    size_t pos = 0;
    while ((pos = input.find(tobereplaced, pos)) != std::string::npos) {
        input.replace(pos, 1, replacer);
    }
    return input;
}