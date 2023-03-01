#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main (){
    // Initialisation des valeurs titre, prix, quantite
    char titre[50];
    float prix_unitaire, prix_TTC, total;
    int quantite;
    bool continuer = true;

    while (continuer){
        // Récupération des informations de l'utilisateur
        printf("Veuillez entrer le titre : ");
        scanf("%s", titre);
        printf("Veuillez entrer le prix unitaire : ");
        scanf("%f", &prix_unitaire);
        printf("Veuillez la quantité : ");
        scanf("%d", &quantite);

        // Calculer les totaux
        total = prix_unitaire * quantite;
        prix_TTC = (total * 24) + prix_unitaire;

        // Afficher les résultats
        printf("%-20s%-20.2f%-10d%-20.2f%-20.2f\n", titre, prix_unitaire, quantite, total, prix_TTC);

        // Demander à l'utilisateur s'il veut continuer
        printf("Voulez-vous continuer (true/false) ? ");
        scanf("%d", &continuer);
    }

    return 0;
}