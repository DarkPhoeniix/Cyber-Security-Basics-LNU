
#ifndef DATARESTORER_H
#define DATARESTORER_H

#include "ImageWriter.h"

#include <string>
#include <vector>

namespace Recovering
{
    using Image = std::vector<char>;

    class ImageRestorer
    {
    public:
        ImageRestorer() = default;
        static int execute(int argc, char* argv[]);

    private:
        static bool validateArguments(int argc, char* argv[]) ;
        [[nodiscard]] static std::vector<Image> recover(const std::string& filename);
    };
} // namespace Recovering

#endif // DATARESTORER_H
