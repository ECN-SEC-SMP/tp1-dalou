#include <string.h>

#include "Lexique.hpp"

Lexique::Lexique(std::string name)
    : name(name) {}

Lexique::~Lexique() = default;

/* Getters */
int Lexique::get_word_occurence(std::string word)
{
    if (!this->words_occurences.contains(word))
        return 0;
    return this->words_occurences[word];
}

/* Methods */
void Lexique::load_from_string(std::string input_string)
{
    const char delimiters[] = " ,.";
    char *word;
    word = strtok((char *)input_string.c_str(), delimiters);
    
    // Go through input string word by word
    while (word != NULL)
    {
        // Increment occurence counter
        this->words_occurences[word]++;

        // Continue string splitting
        word = strtok(NULL, delimiters);
    }
}

void Lexique::clear()
{
    this->words_occurences.clear();
}