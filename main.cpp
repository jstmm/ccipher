#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

const int SHIFT = 3;

void print_usage()
{
    std::cout << "Usage: ccipher [encrypt | decrypt] <file_path>" << std::endl;
}

char process_character(char c, int shift)
{
    if (c >= 'a' && c <= 'z')
    {
        return ('a' + (c - 'a' + shift + 26) % 26);
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return ('A' + (c - 'A' + shift + 26) % 26);
    }
    else
    {
        return c;
    }
}

void transforming(std::string file_path, int shift)
{
    auto fp = fs::path{file_path};

    std::ifstream input_file(fp);
    if (!input_file)
    {
        std::cerr << "Error opening file for reading: " << file_path << std::endl;
        return;
    }

    std::string output = "";
    char c;
    while (input_file.get(c))
    {
        output += process_character(c, shift);
    }
    input_file.close();

    std::ofstream output_file(fp);
    if (!output_file)
    {
        std::cerr << "Error opening file for writing: " << file_path << std::endl;
        return;
    }

    output_file << output;
    output_file.close();
    std::cout << "File encrypted successfully!" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        print_usage();
        return 1;
    }

    std::string file_path = argv[2];

    if (!fs::exists(file_path))
    {
        std::cout << "Error: File '" << file_path << "' does not exist." << std::endl;
        return 1;
    }

    std::string direction = argv[1];

    if (direction == "encrypt")
    {
        transforming(file_path, SHIFT);
    }
    else if (direction == "decrypt")
    {
        transforming(file_path, -SHIFT);
    }
    else
    {
        print_usage();
        return 1;
    }
}
