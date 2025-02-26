#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class Person {
protected:
    std::string name;
    std::string surname;
public:
    Person(const std::string& n, const std::string& s) : name(n), surname(s) {}
    std::string getFullName() const {
        return name + " " + surname;
    }
};

class Player : public Person {
private:
    int number;
    float pointsPerGame;
    float reboundsPerGame;
    float assistsPerGame;
    static int totalPlayers;
public:
    Player(const std::string& n, const std::string& s, int num, float ppg, float rpg, float apg)
        : Person(n, s), number(num), pointsPerGame(ppg), reboundsPerGame(rpg), assistsPerGame(apg) {
        totalPlayers++;
    }
    void print() const {
        std::cout << getFullName() << " | " << "#" << number << " | PPG: " << pointsPerGame
                  << " | RPG: " << reboundsPerGame << " | APG: " << assistsPerGame << std::endl;
    }
    float getPointsPerGame() const {
        return pointsPerGame;
    }
    static int getTotalPlayers() {
        return totalPlayers;
    }
};

int Player::totalPlayers = 0;

int readPlayersFromFile(std::vector<Player>& players, const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Errore nell'apertura del file." << std::endl;
        return 0;
    }

    std::string firstName, lastName;
    int number;
    float ppg, rpg, apg;
    int count = 0;
    
    while (file >> firstName >> lastName >> number >> ppg >> rpg >> apg) {
        if (count >= 5) break; // Limite massimo di 5 giocatori
        players.emplace_back(firstName, lastName, number, ppg, rpg, apg);
        count++;
    }

    std::cout << "Numero totale di giocatori letti fino ad ora: " << Player::getTotalPlayers() << std::endl;
    return count;
}

Player bestScorer(const std::vector<Player>& players) {
    if (players.empty()) {
        throw std::runtime_error("Nessun giocatore disponibile per la valutazione.");
    }

    const Player* best = &players[0];
    for (const auto& player : players) {
        if (player.getPointsPerGame() > best->getPointsPerGame()) {
            best = &player;
        }
    }
    return *best;
}

int main() {
    std::vector<Player> players;
    readPlayersFromFile(players, "giocatori.txt");

    std::cout << "\nElenco Giocatori:" << std::endl;
    for (const auto& player : players) {
        player.print();
    }

    try {
        Player topScorer = bestScorer(players);
        std::cout << "\nMiglior Marcatore:" << std::endl;
        topScorer.print();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\nNumero totale di giocatori letti in tutte le chiamate: " << Player::getTotalPlayers() << std::endl;
    return 0;
}

