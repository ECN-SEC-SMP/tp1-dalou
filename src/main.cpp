#include <iostream>
#include <string>

#include "ANSI.h"
#include "utilitaire.hpp"
#include "Lexique.hpp"
#include "LexiqueLine.hpp"

/**
 * @brief Create a lexique from a file
 * 
 * @param filepath (IN) Path of the file to read
 * @param lexique_name (IN) Name of the new lexique
 * @param output_filepath (IN) Path of the output file
 * @return Lexique& 
 */
Lexique create_Lexique_from_file(
    std::string file_path, 
    std::string lexique_name, 
    std::string output_file_path
);

/**
 * @brief Create a LexiqueLine from a file
 * 
 * @param filepath (IN) Path of the file to read
 * @param lexique_name (IN) Name of the new lexique
 * @param output_filepath (IN) Path of the output file
 * @return LexiqueLine&
 */
LexiqueLine create_LexiqueLine_from_file(
    std::string file_path, 
    std::string lexique_name, 
    std::string output_file_path
);

int tests_Lexique(void);
int tests_LexiqueLine(void);

int main(int argc, char const *argv[])
{
    int ret = tests_LexiqueLine();

    return ret;
}


Lexique create_Lexique_from_file(std::string file_path, std::string lexique_name, std::string output_file_path)
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

    std::cout << "Lowering file content... " << std::flush;
    util::to_lower(file_content);
    std::cout << ANSI_GREEN "DONE" ANSI_RESET << std::endl;

    std::cout << "Creating lexique from file content... " << std::flush;
    lexique.load_from_string(file_content);
    std::cout << ANSI_GREEN "DONE" ANSI_RESET << std::endl;

    std::cout << "Saving lexique into file " << std::flush;
    std::cout << ANSI_CYAN << output_file_path << ANSI_RESET;
    lexique.save_into_file(output_file_path);
    std::cout << ANSI_GREEN " DONE" ANSI_RESET << std::endl;

    return lexique;
}


LexiqueLine create_LexiqueLine_from_file(std::string file_path, std::string lexique_name, std::string output_file_path)
{
    LexiqueLine lexique(lexique_name);
    std::string file_content;

    std::cout << "Reading file " ANSI_CYAN << file_path << ANSI_RESET " " << std::flush;
    if (!util::readFileIntoString(file_path, file_content))
    {
        std::cout << ANSI_RED "FAILED" ANSI_RESET << std::endl;
        std::cout << "Error reading file - Aborting" << std::endl;
        return lexique;
    }
    std::cout << ANSI_GREEN "DONE" ANSI_RESET << std::endl;

    std::cout << "Lowering file content... " << std::flush;
    util::to_lower(file_content);
    std::cout << ANSI_GREEN "DONE" ANSI_RESET << std::endl;

    std::cout << "Creating lexique from file content... " << std::flush;
    lexique.load_from_string(file_content);
    std::cout << ANSI_GREEN "DONE" ANSI_RESET << std::endl;

    std::cout << "Saving lexique into file ";
    std::cout << ANSI_CYAN << output_file_path << ANSI_RESET;
    lexique.save_into_file(output_file_path);
    std::cout << ANSI_GREEN " DONE" ANSI_RESET << std::endl;

    return lexique;
}


int tests_Lexique(void)
{
    Lexique lexique_LesMiserables = create_Lexique_from_file(
        "../../tp1-Lexique-fichiers/lesMiserables_A.txt",
        "Lexique_LesMiserables",
        "../../lexique_LesMiserables.txt"
    );

    Lexique lexique_NotreDameDeParis = create_Lexique_from_file(
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
    bool condition = lexique_sum.get_unique_words_count() == lexique_LesMiserables.get_unique_words_count();
    std::cout << "+= operator: " << (condition ? "OK" : "FAILED") << std::endl;
    
    /* Test -= operator */
    Lexique lexique_diff("lexique_diff");
    lexique_diff += lexique_LesMiserables;
    lexique_diff -= lexique_NotreDameDeParis;
    condition = lexique_diff.get_word_occurence("Author") == 0;
    std::cout << "-= operator (Author): " << (condition ? "OK" : "FAILED") << std::endl;
    condition = lexique_diff.get_word_occurence("abjure") > 0;
    std::cout << "-= operator (abjure): " << (condition ? "OK" : "FAILED") << std::endl;

    return 0;
}

int tests_LexiqueLine(void)
{
    LexiqueLine lexique_LesMiserables = create_LexiqueLine_from_file(
        "../../tp1-Lexique-fichiers/lesMiserables_A.txt",
        "Lexique_LesMiserables",
        "../../lexique_LesMiserables.txt"
    );

    LexiqueLine lexique_NotreDameDeParis = create_LexiqueLine_from_file(
        "../../tp1-Lexique-fichiers/notreDameDeParis_A.txt",
        "Lexique_NotreDameDeParis",
        "../../lexique_NotreDameDeParis.txt"
    );
    
    /* Test += operator */
    /* Create empty lexique, add existing lexique and check that they are equal */
    LexiqueLine lexique_sum("lexique_sum");
    lexique_sum += lexique_LesMiserables;
    bool condition = lexique_sum.get_unique_words_count() == lexique_LesMiserables.get_unique_words_count();
    std::cout << "+= operator: " << (condition ? "OK" : "FAILED") << std::endl;
    
    /* Test -= operator */
    LexiqueLine lexique_diff("lexique_diff");
    lexique_diff += lexique_LesMiserables;
    lexique_diff -= lexique_NotreDameDeParis;
    condition = lexique_diff.get_word_occurence("Author") == 0;
    std::cout << "-= operator (Author): " << (condition ? "OK" : "FAILED") << std::endl;
    condition = lexique_diff.get_word_occurence("abjure") > 0;
    std::cout << "-= operator (abjure): " << (condition ? "OK" : "FAILED") << std::endl;

    return 0;
}