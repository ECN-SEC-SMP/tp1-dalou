#include <iostream>
#include <string>

#include "ANSI.h"
#include "utilitaire.hpp"
#include "Lexique.hpp"

/**
 * @brief Create a lexique from a file
 * 
 * @param filepath (IN) Path of the file to read
 * @param lexique_name (IN) Name of the new lexique
 * @param output_filepath (IN) Path of the output file
 * @return Lexique& 
 */
Lexique create_lexique_from_file(
    std::string file_path, 
    std::string lexique_name, 
    std::string output_file_path
);

int main(int argc, char const *argv[])
{
    // Lexique lexique_LesMiserables("Lexique_LesMiserables");
    // std::string file_path_LesMiserables = "../../tp1-Lexique-fichiers/lesMiserables_A.txt";
    // std::string file_content_LesMiserables;

    // Lexique lexique_NotreDameDeParis("Lexique_NotreDameDeParis");
    // std::string file_path_NotreDameDeParis = "../../tp1-Lexique-fichiers/NotreDameDeParis_A.txt";
    // std::string file_content_NotreDameDeParis;

    Lexique lexique_LesMiserables = create_lexique_from_file(
        "../../tp1-Lexique-fichiers/lesMiserables_A.txt",
        "Lexique_LesMiserables",
        "../../lexique_LesMiserables.txt"
    );

    Lexique lexique_NotreDameDeParis = create_lexique_from_file(
        "../../tp1-Lexique-fichiers/notreDameDeParis_A.txt",
        "Lexique_NotreDameDeParis",
        "../../lexique_NotreDameDeParis.txt"
    );

    /* Test unique words counter */
    std::cout << std::endl;
    int unique_words_count = lexique_LesMiserables.get_unique_words_count();
    std::cout << "Unique words count (LesMiserables):    " << unique_words_count << std::endl;
    unique_words_count = lexique_NotreDameDeParis.get_unique_words_count();
    std::cout << "Unique words count (NotreDameDeParis): " << unique_words_count << std::endl;

    /* Print lexiques */
    std::cout << std::endl << lexique_LesMiserables << std::endl;
    std::cout << std::endl << lexique_NotreDameDeParis << std::endl;

    /* Test += operator */
    /* Create empty lexique, add existing lexique and check that they are equal */
    Lexique lexique_sum("lexique_sum");
    lexique_sum += lexique_LesMiserables;
    bool check = lexique_sum.get_unique_words_count() == lexique_LesMiserables.get_unique_words_count();
    std::cout << "+= operator: " << (check ? "OK" : "FAILED") << std::endl;

    /* Test -= operator */
    Lexique lexique_diff("lexique_diff");
    lexique_diff += lexique_LesMiserables;
    lexique_diff -= lexique_NotreDameDeParis;
    check = lexique_diff.get_word_occurence("Author") == 0;
    std::cout << "-= operator (Author): " << (check ? "OK" : "FAILED") << std::endl;
    check = lexique_diff.get_word_occurence("abjure") > 0;
    std::cout << "-= operator (abjure): " << (check ? "OK" : "FAILED") << std::endl;

    return 0;
}


Lexique create_lexique_from_file(std::string file_path, std::string lexique_name, std::string output_file_path)
{
    Lexique lexique(lexique_name);
    std::string file_content;

    std::cout << "Reading file " ANSI_CYAN << file_path << ANSI_RESET " ";
    if (!util::readFileIntoString(file_path, file_content))
    {
        std::cout << ANSI_RED "FAILED" ANSI_RESET << std::endl;
        std::cout << "Error reading file - Aborting" << std::endl;
        return lexique;
    }
    std::cout << ANSI_GREEN "DONE" ANSI_RESET << std::endl;

    std::cout << "Lowering file content... ";
    util::to_lower(file_content);
    std::cout << ANSI_GREEN "DONE" ANSI_RESET << std::endl;

    std::cout << "Creating lexique from file content... ";
    lexique.load_from_string(file_content);
    std::cout << ANSI_GREEN "DONE" ANSI_RESET << std::endl;

    std::cout << "Saving lexique into file ";
    std::cout << ANSI_CYAN << output_file_path << ANSI_RESET;
    lexique.save_into_file(output_file_path);
    std::cout << ANSI_GREEN " DONE" ANSI_RESET << std::endl;

    return lexique;
}