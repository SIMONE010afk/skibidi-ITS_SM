#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 5  // Numero massimo di giocatori per squadra

// Definizione della struttura Player
typedef struct {
    char name[50];
    int number;
    float pointsPerGame;
    float reboundsPerGame;
    float assistsPerGame;
} Player;

// Nuova struct per rappresentare una squadra di basket
typedef struct {
    char teamName[50];
    Player players[MAX_PLAYERS];
    int numPlayers;
} Team;

// Funzione per leggere i dati di una squadra da un file
int readTeamFromFile(Team* team, const char* filename, const char* teamName) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Errore nell'aprire il file '%s'!\n", filename);
        return -1;
    }

    strcpy(team->teamName, teamName);  // Assegna il nome della squadra
    int i = 0;

    while (fscanf(file, "%49s %d %f %f %f", team->players[i].name, &team->players[i].number,
                  &team->players[i].pointsPerGame, &team->players[i].reboundsPerGame, &team->players[i].assistsPerGame) == 5) {
        i++;
        if (i >= MAX_PLAYERS) {
            break;
        }
    }

    fclose(file);
    team->numPlayers = i;
    return i;
}

// Funzione per stampare i dati di un giocatore
void printPlayer(const Player* p) {
    printf("Nome: %s\n", p->name);
    printf("Numero maglia: %d\n", p->number);
    printf("Punti per partita: %.2f\n", p->pointsPerGame);
    printf("Rimbalzi per partita: %.2f\n", p->reboundsPerGame);
    printf("Assist per partita: %.2f\n\n", p->assistsPerGame);
}

// Funzione per trovare il miglior marcatore di una squadra
Player bestScorer(Player players[], int size) {
    Player best = players[0];
    for (int i = 1; i < size; i++) {
        if (players[i].pointsPerGame > best.pointsPerGame) {
            best = players[i];
        }
    }
    return best;
}

int main() {
    Team team1, team2;
    
    // Legge i dati delle due squadre da file
    int numPlayers1 = readTeamFromFile(&team1, "giocatori1.txt", "Team 1");
    int numPlayers2 = readTeamFromFile(&team2, "giocatori2.txt", "Team 2");

    if (numPlayers1 == -1 || numPlayers2 == -1) {
        return 1;  // Errore nell'aprire almeno un file
    }

    // Stampa i giocatori delle due squadre
    printf("Dati dei giocatori della %s:\n", team1.teamName);
    for (int i = 0; i < numPlayers1; i++) {
        printf("Giocatore %d:\n", i + 1);
        printPlayer(&team1.players[i]);
    }

    printf("Dati dei giocatori della %s:\n", team2.teamName);
    for (int i = 0; i < numPlayers2; i++) {
        printf("Giocatore %d:\n", i + 1);
        printPlayer(&team2.players[i]);
    }

    // Trova e stampa il miglior marcatore di ciascuna squadra
    Player topScorer1 = bestScorer(team1.players, numPlayers1);
    Player topScorer2 = bestScorer(team2.players, numPlayers2);

    printf("Miglior marcatore della %s: %s (Numero %d) - %.2f punti a partita\n\n",
           team1.teamName, topScorer1.name, topScorer1.number, topScorer1.pointsPerGame);

    printf("Miglior marcatore della %s: %s (Numero %d) - %.2f punti a partita\n\n",
           team2.teamName, topScorer2.name, topScorer2.number, topScorer2.pointsPerGame);

    // Confronta i migliori marcatori delle due squadre
    if (topScorer1.pointsPerGame > topScorer2.pointsPerGame) {
        printf("Il miglior marcatore assoluto è %s della %s con %.2f punti a partita!\n",
               topScorer1.name, team1.teamName, topScorer1.pointsPerGame);
    } else if (topScorer1.pointsPerGame < topScorer2.pointsPerGame) {
        printf("Il miglior marcatore assoluto è %s della %s con %.2f punti a partita!\n\n\n\n",
               topScorer2.name, team2.teamName, topScorer2.pointsPerGame);
    } else {
        printf("I due migliori marcatori hanno la stessa media punti: %.2f!\n", topScorer1.pointsPerGame);
    }

    return 0;
}
