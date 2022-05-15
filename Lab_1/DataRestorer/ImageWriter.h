
#ifndef IMAGEPARSER_H
#define IMAGEPARSER_H

#include "ImageRestorer.h"

#include <vector>

namespace Recovering
{
    class ImageWriter
    {
    public:
        ImageWriter() = default;
        static void write(const std::vector<std::vector<char>>& images);
    };
}

#endif // IMAGEPARSER_H
