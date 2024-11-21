#include <iostream>
#include <vector>
#include <algorithm> // pour std::lower_bound

// Fonction pour afficher un vecteur (utilitaire)
void printVector(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}

// Fonction récursive principale
std::vector<int> fordJohnsonSort(std::vector<int>& input)  
{
    if (input.size() <= 1)
        return input;
    if (input.size() == 2) {
        if (input[0] > input[1])
            std::swap(input[0], input[1]);
        return input;
    }
	//MANQUE LA CREATION DE PAIRES

    // Étape 1 : Diviser la liste en paires
    std::vector<int> smalls, larges;
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        if (input[i] < input[i + 1]) {
            smalls.push_back(input[i]);
            larges.push_back(input[i + 1]);
        } else {
            smalls.push_back(input[i + 1]);
            larges.push_back(input[i]);
        }
    }

    // Si le nombre d'éléments est impair, ajouter le dernier élément dans `smalls`
    if (input.size() % 2 != 0)
        smalls.push_back(input.back());

    // Étape 2 : Trier récursivement les petits éléments
    smalls = fordJohnsonSort(smalls);

    // Étape 3 : Insérer les grands éléments dans la liste triée des petits
    std::vector<int> result = smalls;
    for (size_t i = 0; i < larges.size(); ++i) {
        // Trouver la position d'insertion en maintenant l'ordre trié
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), larges[i]);
        result.insert(pos, larges[i]);
    }

    return result;
}

// Programme principal pour tester l'algorithme
int main() {
    std::vector<int> data = {8, 3, 7, 1, 9, 4, 2};

    std::cout << "Liste originale : ";
    printVector(data);

    std::vector<int> sortedData = fordJohnsonSort(data);

    std::cout << "Liste triée : ";
    printVector(sortedData);

    return 0;
}
