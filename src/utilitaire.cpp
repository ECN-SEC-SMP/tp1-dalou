#include "utilitaire.hpp"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iterator>
#include <string>

namespace util {

bool readFileIntoString(std::string_view path, std::string& content) {
    std::ifstream input_file(std::string(path), std::ios::binary);
    if (!input_file) {
        return false; // laisse l’appelant décider quoi faire
    }

    // Technique efficace : on lit tout en une passe via iterators
    content.assign(std::istreambuf_iterator<char>(input_file),
                   std::istreambuf_iterator<char>());
    return true;
}

void remove_punctuation(std::string& word) {
    word.erase(std::remove_if(word.begin(), word.end(),
               [](unsigned char ch) {
                   // ASCII-centric punctuation test
                   return std::ispunct(ch) != 0;
               }),
               word.end());
}

void to_lower(std::string& s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
}

// Optionnel : seulement retirer la ponctuation en tête et en queue (trim)
void trim_punctuation(std::string& s) {
    auto is_punct = [](unsigned char ch) { return std::ispunct(ch) != 0; };

    auto first = std::find_if_not(s.begin(), s.end(), is_punct);
    auto last  = std::find_if_not(s.rbegin(), s.rend(), is_punct).base();

    if (first >= last) { s.clear(); return; }
    s.assign(first, last);
}

} // namespace util
