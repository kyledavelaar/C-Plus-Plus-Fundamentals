#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <random>

enum class CardSuit {
    club,
    diamond,
    heart,
    spade,

    max_suits
};

enum class CardRank {
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,
    rank_ace,

    max_ranks
};

struct Card {
    CardRank rank{};
    CardSuit suit{};
};

void printCard(const Card& c) {
    switch(c.rank) {
        case CardRank::rank_2: std::cout << '2'; break;
        case CardRank::rank_3: std::cout << '3'; break;
        case CardRank::rank_4: std::cout << '4'; break;
        case CardRank::rank_5: std::cout << '5'; break;
        case CardRank::rank_6: std::cout << '6'; break;
        case CardRank::rank_7: std::cout << '7'; break;
        case CardRank::rank_8: std::cout << '8'; break;
        case CardRank::rank_9: std::cout << '9'; break;
        case CardRank::rank_10: std::cout << "10"; break;
        case CardRank::rank_jack: std::cout << 'J'; break;
        case CardRank::rank_queen: std::cout << 'Q'; break;
        case CardRank::rank_king: std::cout << 'K'; break;
        case CardRank::rank_ace: std::cout << 'A'; break;
        default:
            std::cout << "?"; break;
    }

    switch(c.suit) {
        case CardSuit::heart: std::cout << "H "; break;
        case CardSuit::club: std::cout << "C "; break;
        case CardSuit::spade: std::cout << "S "; break;
        case CardSuit::diamond: std::cout << "D "; break;
    }
}
// can set alias of deck_type so don't have to type std::array<Card, 52> everywhere
using deck_type = std::array<Card, 52>;
using index_type = deck_type::size_type;

std::array<Card, 52> createDeck() {
    // static_cast to convert int to enumerated type
    std::array<Card, 52> cards{};
    int counter{0};
    for (int i = 0; i < static_cast<int>(CardRank::max_ranks); i++) {
        for(int y = 0; y < static_cast<int>(CardSuit::max_suits); y++) {
            Card card{ static_cast<CardRank>(i), static_cast<CardSuit>(y) };
            // printCard(card);
            cards[counter] = card;
            counter += 1;
        }
    }
    return cards;
}

void printDeck(deck_type& deck) {
    for (Card card : deck) {
        printCard(card);
    }
    std::cout << '\n';
}

int getCardValue(Card& card) {
   switch(card.rank) {
        case CardRank::rank_2: return 2;
        case CardRank::rank_3: return 3;
        case CardRank::rank_4: return 4;
        case CardRank::rank_5: return 5;
        case CardRank::rank_6: return 6;
        case CardRank::rank_7: return 7;
        case CardRank::rank_8: return 8;
        case CardRank::rank_9: return 9;
        case CardRank::rank_10:
        case CardRank::rank_jack:
        case CardRank::rank_queen:
        case CardRank::rank_king:
            return 10;
        case CardRank::rank_ace: return 11;
   }
}

int main() {
    std::array<Card, 52> deck = createDeck();
    std::cout << '\n' << "ORDERED--------------------------------" << '\n';
    printDeck(deck);

    int value = getCardValue(deck[48]);
    std::cout << "first value: " << value << '\n';

    std::cout << '\n' << "RANDOM--------------------------------" << '\n';
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
    printDeck(deck);


    return 0;
}