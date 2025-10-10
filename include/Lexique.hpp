#pragma once

#include <iostream>
#include <string>
#include <map>

#define DEBUG

class Lexique
{
private:
    std::string name;
    std::map<std::string,int> words_occurences;

private:
    /**
     * @brief Remove all undesired char
     * 
     * @param input String to clean
     * @return std::string Cleaned string
     */
    std::string clean_string(std::string input);

public:
    /**
     * @brief Construct a new Lexique object
     * 
     * @param name Name of the lexique
     */
    Lexique(std::string name);
    ~Lexique();

    /* Getters */
    /**
     * @brief Get the occurence of a specific word
     * 
     * @param word Word to find
     * @return int Occurence or 0 if does not exist
     */
    int get_word_occurence(const std::string word) const;
    
    /**
     * @brief Return the number of unique words in the lexique
     * 
     * @return int
     */
    int get_unique_words_count() const;

    /* Methods */
    /**
     * @brief Add words to lexique with occurences from a string
     * @note For each word, count occurences
     * 
     * @param input_string Content to be analyzed
     */
    void load_from_string(const std::string input_string);
    
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
    friend std::ostream& operator<< (std::ostream& os, const Lexique & obj);
    void operator += (const Lexique & obj);
    void operator -= (const Lexique & obj);
};
