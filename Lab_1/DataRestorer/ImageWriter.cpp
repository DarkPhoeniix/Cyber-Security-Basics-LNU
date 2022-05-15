
#include "ImageWriter.h"

#include <iomanip>
#include <fstream>
#include <iterator>

namespace Recovering
{
    namespace
    {
        void writeImage(const std::vector<char>& image, const std::string& filename)
        {
            std::ofstream output(filename + ".jpeg");

            std::copy(image.begin(), image.end(), std::ostream_iterator<char>(output));
        }

        std::string makeValidFilename(int number, int stringLength = 3)
        {
            std::ostringstream oss;
            oss << std::setw(stringLength) << std::setfill('0') << number;
            return oss.str();
        }
    }

    void ImageWriter::write(const std::vector<std::vector<char>>& images)
    {
        int counter = 0;

        for (const auto& image : images)
        {
            writeImage(image, makeValidFilename(counter++));
        }
    }
}
