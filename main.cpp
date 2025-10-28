#include <iostream>
using namespace std;

// =====================
// Partie 1 : Fonctions de base
// =====================

size_t LongueurChaine(const char* chaine) {
    const char* debut = chaine;
    while (*chaine != '\0') {
        chaine++;
    }
    return chaine - debut;
}

void CopierChaine(char* destination, const char* source) {
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
}

void ConcatenerChaines(char* destination, const char* source) {
    while (*destination != '\0') {
        destination++;
    }
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
}

// =====================
// Partie 2 : Fonctions de recherche
// =====================

char* TrouverCaractere(const char* chaine, char caractere) {
    while (*chaine != '\0') {
        if (*chaine == caractere) {
            return (char*)chaine;
        }
        chaine++;
    }
    return nullptr;
}

size_t CompterOccurrences(const char* chaine, char caractere) {
    size_t compteur = 0;
    while (*chaine != '\0') {
        if (*chaine == caractere)
            compteur++;
        chaine++;
    }
    return compteur;
}

// =====================
// Partie 3 : Fonctions de manipulation mémoire
// =====================

void CopierMemoire(void* destination, const void* source, size_t taille) {
    unsigned char* dest = (unsigned char*)destination;
    const unsigned char* src = (const unsigned char*)source;

    if (dest > src && dest < src + taille) {
        dest += taille - 1;
        src += taille - 1;
        for (size_t i = 0; i < taille; i++) {
            *dest-- = *src--;
        }
    } else {
        for (size_t i = 0; i < taille; i++) {
            *dest++ = *src++;
        }
    }
}

void InitialiserMemoire(void* zone, unsigned char valeur, size_t taille) {
    unsigned char* p = (unsigned char*)zone;
    for (size_t i = 0; i < taille; i++) {
        *p = valeur;
        p++;
    }
}

// =====================
// Partie 4 : Fonctions avancées
// =====================

void ExtraireSousChaine(char* destination, const char* source, 
                       size_t debut, size_t longueur) {
    size_t i = 0;
    while (i < debut && *source != '\0') {
        source++;
        i++;
    }

    size_t j = 0;
    while (j < longueur && *source != '\0') {
        destination[j] = *source;
        j++;
        source++;
    }
    destination[j] = '\0';
}

size_t DiviserChaine(const char* chaine, char separateur, 
                    char resultat[][100], size_t max_resultats) {
    size_t nb = 0;
    size_t j = 0;

    for (size_t i = 0; chaine[i] != '\0' && nb < max_resultats; i++) {
        if (chaine[i] == separateur) {
            resultat[nb][j] = '\0';
            nb++;
            j = 0;
        } else {
            resultat[nb][j++] = chaine[i];
        }
    }

    resultat[nb][j] = '\0';
    nb++;
    return nb;
}

// =====================
// Partie 5 : Fonctions supplémentaires
// =====================

int ComparerChaines(const char* chaine1, const char* chaine2) {
    while (*chaine1 != '\0' && *chaine2 != '\0') {
        if (*chaine1 != *chaine2) {
            return *chaine1 - *chaine2;
        }
        chaine1++;
        chaine2++;
    }
    return *chaine1 - *chaine2;
}

void ConvertirMinuscules(char* chaine) {
    while (*chaine != '\0') {
        if (*chaine >= 'A' && *chaine <= 'Z') {
            *chaine = *chaine + 32;
        }
        chaine++;
    }
}

bool EstChaineNumerique(const char* chaine) {
    if (*chaine == '-') {
        chaine++;
    }

    if (*chaine == '\0') return false;

    while (*chaine != '\0') {
        if (*chaine < '0' || *chaine > '9') {
            return false;
        }
        chaine++;
    }
    return true;
}

// =====================
// Programme principal de test
// =====================

int main() {
    cout << "=== TEST DES FONCTIONS DE MANIPULATION DE CHAINES STYLE C ===" << endl;
    cout << "Compilé avec C++ et Clang++" << endl << endl;
    
    // Test 1: Longueur de chaîne
    char message[] = "Bonjour le monde";
    cout << "1. Longueur de '" << message << "': " << LongueurChaine(message) << endl;
    
    // Test 2: Copie de chaîne
    char copie[50];
    CopierChaine(copie, message);
    cout << "2. Copie: '" << copie << "'" << endl;
    
    // Test 3: Concaténation
    char salutation[100] = "Hello ";
    ConcatenerChaines(salutation, "World!");
    cout << "3. Concaténation: '" << salutation << "'" << endl;
    
    // Test 4: Recherche de caractère
    char* position = TrouverCaractere(message, 'j');
    if (position != nullptr) {
        cout << "4. Caractère 'j' trouvé à la position: " << (position - message) << endl;
    } else {
        cout << "4. Caractère 'j' non trouvé" << endl;
    }
    
    // Test 5: Comptage d'occurrences
    cout << "5. Occurrences de 'o' dans '" << message << "': " 
         << CompterOccurrences(message, 'o') << endl;
    
    // Test 6: Extraction de sous-chaîne
    char sous_chaine[20];
    ExtraireSousChaine(sous_chaine, message, 3, 5);
    cout << "6. Sous-chaîne (pos 3, longueur 5): '" << sous_chaine << "'" << endl;
    
    // Test 7: Division de chaîne
    char phrase[] = "pomme,orange,banane,kiwi";
    char fruits[10][100];
    size_t nb_fruits = DiviserChaine(phrase, ',', fruits, 10);
    
    cout << "7. Division de '" << phrase << "':" << endl;
    for (size_t i = 0; i < nb_fruits; i++) {
        cout << "   [" << i << "] " << fruits[i] << endl;
    }
    
    // Test 8: Fonctions mémoire
    char zone1[10] = "ABCDEFGHI";
    char zone2[10];
    CopierMemoire(zone2, zone1, 5);
    zone2[5] = '\0';
    cout << "8. Copie mémoire (5 octets): '" << zone2 << "'" << endl;
    
    char zone3[10];
    InitialiserMemoire(zone3, 'X', 5);
    zone3[5] = '\0';
    cout << "9. Initialisation mémoire: '" << zone3 << "'" << endl;
    
    // Test 10: Comparaison de chaînes
    char chaineA[] = "apple";
    char chaineB[] = "banana";
    int resultat_comparaison = ComparerChaines(chaineA, chaineB);
    cout << "10. Comparaison '" << chaineA << "' vs '" << chaineB << "': " 
         << resultat_comparaison << endl;
    
    // Test 11: Conversion minuscules
    char mixte[] = "Hello World!";
    cout << "11. Avant conversion: '" << mixte << "'" << endl;
    ConvertirMinuscules(mixte);
    cout << "    Après conversion: '" << mixte << "'" << endl;
    
    // Test 12: Vérification numérique
    char numerique[] = "12345";
    char non_numerique[] = "12a45";
    cout << "12. '" << numerique << "' est numérique: " 
         << (EstChaineNumerique(numerique) ? "OUI" : "NON") << endl;
    cout << "    '" << non_numerique << "' est numérique: " 
         << (EstChaineNumerique(non_numerique) ? "OUI" : "NON") << endl;
    
    return 0;
}
