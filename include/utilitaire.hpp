#ifndef UTILITAIRE_HPP
#define UTILITAIRE_HPP

#include <string>
#include <string_view>

namespace util {
// Lit un fichier texte (ou binaire) dans 'content'.
// Retourne true en cas de succès, false sinon (ne fait PAS exit()).
bool readFileIntoString(std::string_view path, std::string& content);

// Supprime toute la ponctuation (ASCII) dans la chaîne, en place.
void remove_punctuation(std::string& word);

// Met la chaîne en minuscules (ASCII), en place.
void to_lower(std::string& s);

// Variante : ne supprimer que ponctuation en tête/queue .
void trim_punctuation(std::string& s);
}

#endif // UTILITAIRE_HPP
