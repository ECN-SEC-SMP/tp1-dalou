#include <iostream>
#include <string>

#include "ANSI.h"
#include "utilitaire.hpp"
#include "Lexique.hpp"

int main(int argc, char const *argv[])
{
    Lexique lexique_LesMiserables = Lexique("Lexique_LesMiserables");
    std::string file_path = "../../tp1-Lexique-fichiers/lesMiserables_A.txt";
    std::string file_content;

    std::cout << "Reading file " << ANSI_CYAN << file_path << ANSI_RESET << std::endl;
    if(!util::readFileIntoString(file_path, file_content))
    {
        std::cout << "Error reading file" << std::endl;
        return -1;
    }
    std::cout << "File read successfully" << std::endl;

    std::cout << "Lowering file content...";
    util::to_lower(file_content);
    std::cout << ANSI_GREEN << "DONE" << ANSI_RESET << std::endl;

    std::cout << "Creating lexique from file content...";
    lexique_LesMiserables.load_from_string(file_content);
    std::cout << ANSI_GREEN << "DONE" << ANSI_RESET << std::endl;

    std::cout << std::endl;
    int unique_words_count = lexique_LesMiserables.get_unique_words_count();
    std::cout << "Unique words count: " << unique_words_count << std::endl;

    std::cout << lexique_LesMiserables << std::endl;
    
    return 0;
}
