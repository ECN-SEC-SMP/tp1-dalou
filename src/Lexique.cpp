#include <string.h>
#include <fstream>
#include <algorithm>

#include "Lexique.hpp"
#include "utilitaire.hpp"

Lexique::Lexique(std::string name)
    : name(name) {}

Lexique::~Lexique() = default;

std::string Lexique::clean_string(std::string input)
{
    std::string cleaned_string = std::string(input);
    util::remove_punctuation(cleaned_string);
    std::replace_if(
        cleaned_string.begin(),
        cleaned_string.end(),
        [](unsigned char ch)
        {
            return std::isalpha(ch) == 0 && ch != '\0';
        },
        ' ');
    return cleaned_string;
}

/* Getters */
int Lexique::get_word_occurence(const std::string word) const
{
    std::string word_lowered = word;
    util::to_lower(word_lowered);
    if (!this->words_occurences.contains(word_lowered))
        return 0;
    return this->words_occurences.at(word_lowered);
}

int Lexique::get_unique_words_count() const
{
    return this->words_occurences.size();
}

/* Methods */
void Lexique::load_from_string(const std::string input_string)
{
    const char delimiters[] = " ";
    char *word;
    std::string input_string_cleaned = clean_string(input_string);
    word = strtok((char *)input_string_cleaned.c_str(), delimiters);

    // Go through input string word by word
    while (word != NULL)
    {
        // Increment occurence counter
        this->words_occurences[word]++;

        // Continue string splitting
        word = strtok(NULL, delimiters);
    }
}

void Lexique::save_into_file(const std::string filename)
{
    std::ofstream output_file;
    output_file.open(filename);
    for (const auto &[word, occurence] : this->words_occurences)
    {
        output_file << occurence << "\t\t" << word << std::endl;
    }

    output_file.close();
}

void Lexique::clear()
{
    this->words_occurences.clear();
}

void Lexique::delete_word(std::string word)
{
    this->words_occurences.erase(word);
}

/* Operator Overloading */
std::ostream &operator<<(std::ostream &os, const Lexique &obj)
{
    os << obj.name << std::endl;
    os << std::string(obj.name.length(), '=') << std::endl;
#ifdef DEBUG
    int i = 0;
#endif
    for (auto &&[word, occurence] : obj.words_occurences)
    {
        os << "\"" << word << "\": " << occurence << " occurences" << std::endl;
#ifdef DEBUG
        i++;
        if (i > 50)
            break;
#endif
    }

    return os;
}

void Lexique::operator+=(const Lexique &obj)
{
    for (auto &&[word, occurence] : obj.words_occurences)
    {
        this->words_occurences[word] += occurence;
    }
}

void Lexique::operator-=(const Lexique &obj)
{
    for (auto &&[word, occurence] : obj.words_occurences)
    {
        if (this->get_word_occurence(word) > 0)
        {
            this->delete_word(word);
        }
    }
}