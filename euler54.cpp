#include "euler.hpp"

// defines for all the card and win types
#define NONE 0
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define EIGHT 8
#define NINE 9
#define TEN 10
#define JACK 11
#define QUEEN 12
#define KING 13
#define ACE 14

#define SINGLE 1
#define PAIR 2
#define TWO_PAIRS 3
#define TRIPLE 4
#define STRAIGHT 5
#define FLUSH 6
#define FULL_HOUSE PAIR*TRIPLE
#define FOUR_OF_A_KIND 9
#define STRAIGHT_FLUSH STRAIGHT+FLUSH
#define ROYAL_FLUSH 12

struct Card {
    char suit;
    int rank;
};

int get_rank(char);
int get_max(const vector<Card>&);
int is_pair(const vector<Card>&);
int is_two_pairs(const vector<Card>&);
int is_triple(const vector<Card>&);
int is_straight(const vector<Card>&);
int is_flush(const vector<Card>&);
int is_full_house(const vector<Card>&);
int is_four_of_a_kind(const vector<Card>&);
inline int is_straight_flush(const vector<Card>&);
int is_royal_flush(const vector<Card>&);
vector<int> score_hand(vector<Card>&, int);
int compare_hands(vector<Card>&, vector<Card>&);
int tie_break_hands(vector<Card>, vector<Card>, int);
int main(int, char**);

int get_rank(char repr) {
    switch (repr) {
        case '2':
            return TWO;
        case '3':
            return THREE;
        case '4':
            return FOUR;
        case '5':
            return FIVE;
        case '6':
            return SIX;
        case '7':
            return SEVEN;
        case '8':
            return EIGHT;
        case '9':
            return NINE;
        case 'T':
            return TEN;
        case 'J':
            return JACK;
        case 'Q':
            return QUEEN;
        case 'K':
            return KING;
    }
    return ACE;
}

int get_max(const vector<Card>& hand) {
    /**
     * Return the rank of the highest card in hand
     */
    int max = 0;
    for (auto it = hand.begin(); it != hand.end(); ++it)
        if (it->rank > max)
            max = it->rank;
    return max;
}

int is_pair(const vector<Card>& hand) {
    /**
     * If a sole pair is found, return its rank
     * Else return NONE
     */
    // make a frequency table of every rank
    int pair = NONE;
    vector<int> frequencies(15);
    for (auto it = hand.begin(); it != hand.end(); ++it)
        ++frequencies[it->rank];
    // make sure there is exactly one rank that has freq 2
    for (size_t i = 0; i < 15; ++i) {
        if (frequencies[i] == 2) {
            if (pair != NONE)
                // we've already found a pair somewhere
                return NONE;
            pair = i;
        }
    }
    return pair;
}

int is_two_pairs(const vector<Card>& hand) {
    /**
     * If two pairs are present, return the larger rank
     * Else return NONE
     */
    int largest_pair = NONE;
    vector<int> frequencies(15);
    for (auto it = hand.begin(); it != hand.end(); ++it)
        ++frequencies[it->rank];
    for (size_t i = 0; i < 15; ++i) {
        if (frequencies[i] == 2) {
            if (largest_pair != NONE)
                // already found a pair somewhere, so this is second
                return i;
            largest_pair = i;
        }
    }
    return NONE;
}

int is_triple(const vector<Card>& hand) {
    /**
     * Return the rank of the triple
     * If none found, return NONE
     */
    vector<int> frequencies(15);
    for (auto it = hand.begin(); it != hand.end(); ++it)
        ++frequencies[it->rank];
    for (size_t i = 0; i < 15; ++i)
        if (frequencies[i] == 3)
            return i;
    return NONE;
}

int is_straight(const vector<Card>& hand) {
    /**
     * If the hand is a straight, return the highest card's rank
     * Else return NONE
     */
    if (hand.size() != 5)
        return NONE;
    vector<int> values;
    values.reserve(5);
    for (auto it = hand.begin(); it != hand.end(); ++it)
        values.push_back(it->rank);
    std::sort(values.begin(), values.end());
    for (size_t i = 1; i < values.size(); ++i)
        // make sure common difference is 1
        if (values[i] - values[i-1] != 1)
            return NONE;
    // return the biggest element
    return values[values.size()-1];
}

int is_flush(const vector<Card>& hand) {
    /**
     * If the hand is a flush, return the highest card's rank
     * Else return NONE
     */ 
    int max = 0;
    char suit = hand[0].suit;
    if (hand.size() != 5)
        return NONE;
    for (auto it = hand.begin(); it != hand.end(); ++it) {
        if (it->suit != suit)
            return NONE;
        if (it->rank > max)
            max = it->rank;
    }
    return max;
}

int is_full_house(const vector<Card>& hand) {
    /**
     * If the hand is a full house (pair with triple), return the
     * rank of the triple
     * Else return NONE
     */
    if (is_pair(hand))
        return is_triple(hand);
    return NONE;
}

int is_four_of_a_kind(const vector<Card>& hand) {
    /**
     * If the hand contains four of a kind, return its rank
     * Else return NONE
     */
    vector<int> frequencies(15);
    for (auto it = hand.begin(); it != hand.end(); ++it)
        ++frequencies[it->rank];
    for (size_t i = 0; i < 15; ++i)
        if (frequencies[i] == 4)
            return i;
    return NONE;
}

int is_straight_flush(const vector<Card>& hand) {
    /**
     * If the hand is a straight flush, return the highest card's rank
     * Else return NONE
     */
    if (is_flush(hand))
        return is_straight(hand);
    return NONE;
}

int is_royal_flush(const vector<Card>& hand) {
    /**
     * If the hand is a royal flush, return ACE
     * Else return NONE
     */
    if (is_straight_flush(hand))
        for (auto it = hand.begin(); it != hand.end(); ++it)
            if (it->rank == ACE)
                return ACE;
    return NONE;
}

vector<int> score_hand(vector<Card>& hand, int disregard) {
    /**
     * Return the winning play and best card of that winning play
     * Do not count the rank defined by disregard
     */
    if (disregard != NONE)
        for (std::size_t i = 0; i < hand.size(); ++i)
            if (hand[i].rank == disregard)
                hand.erase(hand.begin()+i);

    vector<int> result(2);
    int score = is_royal_flush(hand);
    if (score) {
        result[0] = ROYAL_FLUSH;
        result[1] = score;
        return result;
    }
    score = is_straight_flush(hand);
    if (score) {
        result[0] = STRAIGHT_FLUSH;
        result[1] = score;
        return result;
    }
    score = is_four_of_a_kind(hand);
    if (score) {
        result[0] = FOUR_OF_A_KIND;
        result[1] = score;
        return result;
    }
    score = is_full_house(hand);
    if (score) {
        result[0] = FULL_HOUSE;
        result[1] = score;
        return result;
    }
    score = is_flush(hand);
    if (score) {
        result[0] = FLUSH;
        result[1] = score;
        return result;
    }
    score = is_straight(hand);
    if (score) {
        result[0] = STRAIGHT;
        result[1] = score;
        return result;
    }
    score = is_triple(hand);
    if (score) {
        result[0] = TRIPLE;
        result[1] = score;
        return result;
    }
    score = is_two_pairs(hand);
    if (score) {
        result[0] = TWO_PAIRS;
        result[1] = score;
        return result;
    }
    score = is_pair(hand);
    if (score) {
        result[0] = PAIR;
        result[1] = score;
        return result;
    }
    result[0] = SINGLE;
    result[1] = get_max(hand);
    return result;
}

int compare_hands(vector<Card>& hand1, vector<Card>& hand2) {
    /**
     * Return 1 if hand1 wins
     * 2 if hand2 wins
     * 0 if tie
     */
    vector<int> score1 = score_hand(hand1, NONE);
    vector<int> score2 = score_hand(hand2, NONE);
    if (score1[0] != score2[0]) {
        if (score1[0] > score2[0])
            return 1;
        return 2;
    }
    if (score1[1] != score2[1]) {
        if (score1[1] > score2[1])
            return 1;
        return 2;
    }
    return tie_break_hands(hand1, hand2, score1[1]);
}

int tie_break_hands(vector<Card> hand1, vector<Card> hand2, int tie) {
    /**
     * Resolve initially tied hands on the rank given by tie
     * Return 1 if hand1 wins
     * 2 if hand2 wins
     * If truly a tie, return 0
     */
    if (hand1.size() == 0 || hand2.size() == 0)
        // it really is a tie!
        return 0;
    vector<int> score1 = score_hand(hand1, tie);
    vector<int> score2 = score_hand(hand2, tie);
    if (score1[0] != score2[0]) {
        if (score1[0] > score2[0])
            return 1;
        return 2;
    }
    if (score1[1] != score2[1]) {
        if (score1[1] > score2[1])
            return 1;
        return 2;
    }
    // still a tie, so recurse
    return tie_break_hands(hand1, hand2, score1[1]);
}

int main(int argc, char** argv) {
    int count_wins_1 = 0;
    int count_wins_2 = 0;
    int count_draws = 0;
    int c; // counter
    int result;
    string line;
    vector<Card> hand1(5);
    vector<Card> hand2(5);
    std::ifstream datafile("e54.dat");
    while (datafile.good()) {
        c = 0;
        getline(datafile, line);
        if (line.size() < 5)
            break;
        while (c < 5) {
            hand1[c].rank = get_rank(line[3*c]);
            hand1[c].suit = line[3*c+1];
            ++c;
        }
        while (c < 10) {
            hand2[c-5].rank = get_rank(line[3*c]);
            hand2[c-5].suit = line[3*c+1];
            ++c;
        }
        result = compare_hands(hand1, hand2);
        if (result == 1)
            ++count_wins_1;
        if (result == 2)
            ++count_wins_2;
        if (result == 3)
            ++count_draws;
    }
    cout << "1 wins: " << count_wins_1 << " games.\n";
    cout << "2 wins: " << count_wins_2 << " games.\n";
    cout << "Drawn: " << count_draws << " games.\n";
    datafile.close();
    return 0;
}
