#pragma once

#include <string>
#include <map>

class Lexique
{
private:
    std::string name;
    std::map<std::string,int> words_occurences;
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
    int get_word_occurence(std::string word);

    /* Methods */
    /**
     * @brief Add words to lexique with occurences from a string
     * @note For each word, count occurences
     * 
     * @param input_string Content to be analyzed
     */
    void load_from_string(std::string input_string);
    
    /**
     * @brief Clear lexique
     * @note Clear occurrences map 
     */
    void clear();
};
