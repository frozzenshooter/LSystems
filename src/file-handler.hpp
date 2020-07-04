#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

#include <string>
#include <vector>
#include "configuration.hpp"
#include "turtle-graphic.hpp"
#include "l-system-2d.hpp"

class FileHandler {

public:

    // === file handling ============================================
    Configuration parse_file(const std::string& input_filename);

};
#endif
