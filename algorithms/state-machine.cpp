#include <iostream>
#include <vector>
#include <string>


/*
    Our simple automaton, accepts the language of A, defined as {0, 1} and should have three states: q1, q2, and q3. Here is the description of the states:

    q1 is our start state, we begin reading commands from here
    q2 is our accept state, we return true if this is our last state
    And the transitions:

    q1 moves to q2 when given a 1, and stays at q1 when given a 0
    q2 moves to q3 when given a 0, and stays at q2 when given a 1
    q3 moves to q2 when given a 0 or 1
    The automaton should return whether we end in our accepted state (q2), or not (true/false).

*/

enum class State {
    q1,
    q2,
    q3
};

class Automaton {
private:
    State state{ State::q1 };
    State acceptedState{ State::q2 };
public:
    Automaton(){};

    bool isTrue(char v) { return v == '1'; }
    bool isTrue(int v) { return v == 1; }
    bool isTrue(std::string v) { return v == "1"; }

    template <typename T>
    bool read_commands(const T& commands) {
        for (auto c : commands) {
            // std::cout << c << std::endl;

            switch (state) {
                case State::q1:
                    if (isTrue(c)) {
                        state = State::q2;
                    }
                    break;
                case State::q2:
                    if (!isTrue(c)) {
                        state = State::q3;
                    }
                    break;
                case State::q3:
                    state = State::q2;
                    break;
            }
        }
        return state == acceptedState;
  }
};


int main() {
    std::vector<char> test1{ '1', '0', '0', '1' }; // true
    std::vector<int> test2{ 1, 0, 0, 1 }; // true
    std::vector<std::string> test3{ "1", "0", "0", "1" }; // true
    std::vector<std::vector<int>> test4{
        { 1, 0, 0, 1, 0 }, // false
        { 1, 0, 0, 1 } // true
    };
    std::vector<std::vector<char>> test5{
        { '1', '0', '0', '1', '0' }, // false
        { '1', '0', '0', '1' } // true
    };

    Automaton myAutomaton{};

    bool accepted = myAutomaton.read_commands(test1);
    std::cout << "accepted: " << accepted << std::endl;
    bool accepted2 = myAutomaton.read_commands(test2);
    std::cout << "accepted: " << accepted2 << std::endl;
    bool accepted3 = myAutomaton.read_commands(test3);
    std::cout << "accepted: " << accepted3 << std::endl;

    for (auto& v : test4) {
        bool a = myAutomaton.read_commands(v);
        std::cout << "accepted: " << a << std::endl;
    }
    for (auto& v : test5) {
        bool a = myAutomaton.read_commands(v);
        std::cout << "accepted: " << a << std::endl;
    }




    return 0;
}