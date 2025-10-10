#pragma once

#include <map>
#include <string>

#include "Lexique.hpp"

class LexiqueLine : public Lexique
{
private:
    std::map<std::string, int> words_line;

private:
    /**
     * @brief Remove all undesired char
     *
     * @param input String to clean
     * @return std::string Cleaned string
     */
    std::string clean_string(std::string input) override;

public:
    /**
     * @brief Construct a new Lexique object
     * 
     * @param name Name of the lexique
     */
    LexiqueLine(std::string name);
    
    /* Getters */
    /**
     * @brief Get the line of a specific word
     * 
     * @param word Word to find
     * @return int Line where the word has been seen
     */
    int get_word_line(const std::string word) const;

    /* Methods */
    /**
     * @brief Add words to lexique with occurences from a string
     * @note For each word, count occurences
     * 
     * @param input_string Content to be analyzed
     */
    void load_from_string(const std::string input_string) override;
    
    /**
     * @brief Writes lexique in a text file
     * 
     * @param filename Name of the output file
     * @note Filename has to include the file extension
     */
    void save_into_file(const std::string filename);
    
    /**
     * @brief Clear lexique
     * @note Clear occurrences map 
     */
    void clear();

    /**
     * @brief Remove word from lexique
     * 
     * @param word Word to remove
     */
    void delete_word(std::string word);

    /* Operator Overloading */
    friend std::ostream& operator<< (std::ostream& os, const LexiqueLine & obj);
};
