#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// Fonction pour générer le nombre de Jacobsthal
unsigned int jacobsthal(unsigned int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

// Fonction pour diviser les éléments en paires et trier les paires
void pairAndSort(std::vector<int>& collection) {
    size_t n = collection.size();
    for (size_t i = 0; i + 1 < n; i += 2) {
        if (collection[i] > collection[i + 1]) {
            std::swap(collection[i], collection[i + 1]);
        }
    }
}

// Fonction pour insérer les éléments pendants dans la chaîne principale
void insertPendElements(std::vector<int>& mainChain, std::vector<int>& pendElements) {
    size_t pendIndex = 0;
    unsigned int jacIndex = 1; // Le premier Jacobsthal utilisé est 3.

    while (pendIndex < pendElements.size()) {
        unsigned int areaSize = jacobsthal(jacIndex);
        size_t insertionPoint = std::min(mainChain.size(), static_cast<size_t>(areaSize));

        for (size_t i = pendIndex; i < pendElements.size() && i - pendIndex < insertionPoint; ++i) {
            int value = pendElements[i];
            std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.begin() + insertionPoint, value);
            mainChain.insert(it, value);
        }

        pendIndex += insertionPoint;
        ++jacIndex;
    }
}

// Fonction principale de tri par paire et insertion
void mergeInsertionSort(std::vector<int>& collection) {
    if (collection.size() <= 1) return;

    // Étape 1: Trier les paires
    pairAndSort(collection);

    // Étape 2: Diviser la chaîne principale et les pendants
    std::vector<int> mainChain, pendElements;
    for (size_t i = 0; i + 1 < collection.size(); i += 2) {
        mainChain.push_back(collection[i + 1]); // Les plus grands éléments
        pendElements.push_back(collection[i]); // Les plus petits éléments
    }
    if (collection.size() % 2 != 0) {
        mainChain.push_back(collection.back());
    }

    // Étape 3: Insérer les pendants dans la chaîne principale
    insertPendElements(mainChain, pendElements);

    // Copier le résultat dans la collection d'origine
    collection = mainChain;
}

// Fonction d'affichage
void printVector(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << (i + 1 < vec.size() ? " " : "\n");
    }
}

// Exemple d'utilisation
int main() {
    std::vector<int> collection = {9, 7, 3, 1, 8, 4, 6, 5, 2};
    
    std::cout << "Collection initiale : ";
    printVector(collection);

    mergeInsertionSort(collection);

    std::cout << "Collection triée : ";
    printVector(collection);

    return 0;
}
