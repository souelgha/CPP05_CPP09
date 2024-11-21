#include <iostream>
#include <vector>
#include <algorithm> // Pour std::swap

// Fonction d'insertion dans un tableau déjà trié
void insertionSort(std::vector<int>& arr, int start, int end) {
    for (int i = start + 1; i <= end; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= start && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Fonction pour fusionner deux vecteurs triés avec insertion
std::vector<int> mergeWithMinimalComparisons(const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int> merged;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            merged.push_back(left[i]);
            ++i;
        } else {
            merged.push_back(right[j]);
            ++j;
        }
    }

    // Ajouter les éléments restants
    while (i < left.size()) {
        merged.push_back(left[i]);
        ++i;
    }
    while (j < right.size()) {
        merged.push_back(right[j]);
        ++j;
    }

    return merged;
}

// Fonction principale de l'algorithme Ford-Johnson
std::vector<int> fordJohnsonSort(std::vector<int> arr) {
    if (arr.size() <= 1) {
        return arr;
    }

    // Diviser le tableau en sous-groupes
    int mid = arr.size() / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());

    // Trier chaque sous-groupe
    insertionSort(left, 0, left.size() - 1);
    insertionSort(right, 0, right.size() - 1);

    // Fusionner les deux sous-groupes triés
    return mergeWithMinimalComparisons(left, right);
}

int main() {
    std::vector<int> arr = {34, 7, 23, 32, 5, 62};
    std::vector<int> sortedArr = fordJohnsonSort(arr);

    std::cout << "Tableau trié : ";
    for (size_t i = 0; i < sortedArr.size(); ++i) {
        std::cout << sortedArr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
