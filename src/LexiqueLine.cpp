#include <algorithm>
#include <cstring>
#include <fstream>
#include <vector>

#include "LexiqueLine.hpp"
#include "utilitaire.hpp"

LexiqueLine::LexiqueLine(std::string name)
    : Lexique(name) {}

std::string LexiqueLine::clean_string(std::string input)
{
    std::string cleaned_string = std::string(input);
    util::remove_punctuation(cleaned_string);
    std::replace_if(
        cleaned_string.begin(),
        cleaned_string.end(),
        [](unsigned char ch)
        {
            return std::isalpha(ch) == 0 && ch != '\0' && ch != '\n';
        },
        ' ');
    return cleaned_string;
}

int LexiqueLine::get_word_line(const std::string word) const
{
    return this->words_line.at(word);
}

void LexiqueLine::load_from_string(const std::string input_string)
{
    std::string input_string_cleaned = clean_string(input_string);
    const char delimiter[] = " ";
    const char delimiter_lines[] = "\n";
    char *line;
    char *word;
    std::vector<std::string> lines;

    line = strtok((char *)input_string_cleaned.c_str(), delimiter_lines);
    while (line != NULL)
    {
        lines.push_back(std::string(line));

        // Continue string splitting
        line = strtok(NULL, delimiter_lines);
    }
    
    int line_number = 1;
    for (auto &&line_str : lines)
    {
        word = strtok((char *) line_str.c_str(), delimiter);

        // Go through input string word by word
        while (word != NULL)
        {
            // Save line number
            if (this->get_word_occurence(word) == 0)
            {
                this->words_line[word] = line_number;
            }

            // Increment occurence counter
            this->words_occurences[word]++;

            // Continue string splitting
            word = strtok(NULL, delimiter);
        }

        line_number++;
    }
}

void LexiqueLine::save_into_file(const std::string filename)
{
    std::ofstream output_file;
    output_file.open(filename);
    output_file << "Occurence\t\tWord\t\tLine" << std::endl;
    for (const auto &[word, occurence] : this->words_occurences)
    {
        output_file << occurence << "\t\t" << word;
        output_file << "\t\t" << this->words_line[word] << std::endl;
    }
    output_file.close();
}

void LexiqueLine::clear()
{
    Lexique::clear();
    this->words_line.clear();
}

void LexiqueLine::delete_word(std::string word) 
{
    Lexique::delete_word(word);
    this->words_line.erase(word);
}


/* Operator Overloading */
std::ostream &operator<<(std::ostream &os, const LexiqueLine &obj)
{
    os << obj.name << std::endl;
    os << std::string(obj.name.length(), '=') << std::endl;
#ifdef DEBUG
    int i = 0;
#endif
    for (auto &&[word, occurence] : obj.words_occurences)
    {
        os << "\"" << word << "\": " << occurence << " occurences (line " << obj.words_line.at(word) << ")" << std::endl;
#ifdef DEBUG
        i++;
        if (i > 50)
            break;
#endif
    }

    return os;
}