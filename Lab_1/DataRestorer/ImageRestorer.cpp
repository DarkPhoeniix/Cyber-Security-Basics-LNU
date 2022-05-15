
#include "ImageRestorer.h"

#include <algorithm>
#include <fstream>
#include <filesystem>
#include <iostream>

namespace Recovering
{
    namespace
    {
        bool checkBytes(const std::vector<char>& buffer)
        {
            return ((buffer[0] == static_cast<char>(0xff)) &&
                    (buffer[1] == static_cast<char>(0xd8)) &&
                    (buffer[2] == static_cast<char>(0xff)));
        }
    }

    int ImageRestorer::execute(int argc, char* argv[])
    {
        try
        {
            validateArguments(argc, argv);
        }
        catch(const std::exception& ex)
        {
            std::cout << ex.what() << std::endl;
            return 1;
        }

        ImageWriter::write(recover(argv[1]));

        return 0;
    }

    bool ImageRestorer::validateArguments(int argc, char* argv[])
    {
        if (argc > 2)
        {
            throw std::invalid_argument("Invalid number of arguments");
        }
        else if (!std::filesystem::exists(argv[1]))
        {
            throw std::invalid_argument("Invalid file to read: " + std::string(argv[1]));
        }

        return true;
    }

    std::vector<Image> ImageRestorer::recover(const std::string &filename)
    {
        std::vector<Image> images;

        std::ifstream input(filename, std::ios_base::in | std::ios_base::binary);

        bool isFirst = true;
        std::vector<char> buffer(512);

        while(!input.eof())

        while (!input.eof())
        {
            input.read(reinterpret_cast<char*>(buffer.data()), 512);
            if (checkBytes(buffer)) {
                isFirst = false;
                images.emplace_back(Image());
            }

            if (!isFirst)
            {
                std::copy(buffer.begin(), buffer.end(), std::back_inserter(*images.rbegin()));
            }
        }

        return images;
    }
}
