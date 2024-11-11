#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void afficherPendu(int erreurs) {
    // Dessin simple pour représenter les erreurs de l'utilisateur
    switch (erreurs) {
        case 1: std::cout << " O " << std::endl; break;
        case 2: std::cout << " O " << std::endl
                          << " | " << std::endl; break;
        case 3: std::cout << " O " << std::endl
                          << "/| " << std::endl; break;
        case 4: std::cout << " O " << std::endl
                          << "/|\\" << std::endl; break;
        case 5: std::cout << " O " << std::endl
                          << "/|\\" << std::endl
                          << "/  " << std::endl; break;
        case 6: std::cout << " O " << std::endl
                          << "/|\\" << std::endl
                          << "/ \\" << std::endl; break;
        default: break;
    }
}

int main() {
    std::string mot = "PENDULATION";   // Mot à deviner
    std::string lettresTrouvees(mot.size(), '_'); // Mot masqué avec des "_"
    std::vector<char> lettresEssayees;  // Pour stocker les lettres essayées
    int erreurs = 0;
    const int MAX_ERREURS = 6;   // Nombre maximum d'erreurs

    std::cout << "****Bienvenue dans le jeu du pendu !****" << std::endl;

    while (erreurs < MAX_ERREURS && lettresTrouvees != mot) {
        std::cout << "\nMot à deviner : " << lettresTrouvees << std::endl;
        std::cout << "Lettres essayées : ";
        for (char lettre : lettresEssayees) {
            std::cout << lettre << ' ';
        }
        std::cout << "\nNombre d'erreurs : " << erreurs << "/" << MAX_ERREURS << std::endl;
        afficherPendu(erreurs);

        std::cout << "Proposez une lettre : ";
        char proposition;
        std::cin >> proposition;

        // Vérifie si la lettre a déjà été proposée
        if (std::find(lettresEssayees.begin(), lettresEssayees.end(), proposition) != lettresEssayees.end()) {
            std::cout << "Vous avez déjà proposé cette lettre." << std::endl;
            continue;
        }

        lettresEssayees.push_back(proposition);  // Ajoute la lettre aux lettres essayées

        // Vérifie si la lettre est dans le mot
        bool bonneLettre = false;
        for (size_t i = 0; i < mot.size(); i++) {
            if (mot[i] == toupper(proposition)) {
                lettresTrouvees[i] = mot[i];
                bonneLettre = true;
            }
        }

        if (!bonneLettre) {
            erreurs++;  // Incrémente le compteur d'erreurs si la lettre est incorrecte
        }
    }

    // Affiche le résultat final
    if (lettresTrouvees == mot) {
        std::cout << "Félicitations ! Vous avez deviné le mot : " << mot << std::endl;
    } else {
        std::cout << "Désolé, vous avez perdu. Le mot était : " << mot << std::endl;
        afficherPendu(MAX_ERREURS);
    }

    return 0;
}

/* REMARQUE
le jeu prend en compte les lettres en majuscule
le mot à deviner est definit dans le code
*/