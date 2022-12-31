#include <iostream>
#include <unordered_set>
#include <cstring>

struct Player {
    const char *name;
    int score;
private:
    static constexpr std::hash<size_t> hasher = std::hash<size_t>();

public:
    bool operator==(const Player &other) const {
        return *name == *other.name && score == other.score;
    }

    static size_t hash(const Player &player) {
        return hasher(strlen(player.name) + player.score);
    }
};

namespace std {
    template<>
    struct hash<Player> {
        std::size_t operator()(const Player &p) const noexcept {
            return Player::hash(p);
        }
    };
}

const char *int_to_bool_const_char(size_t value) {
    if (value != 0)
        return "true";
    return "false";
}

int main() {
    std::unordered_set<Player> unique;

    Player p1 = {"james", 100};
    Player p2 = {"runi", 9};

    unique.insert(p1);

    std::cout << " contains p1? "
              << int_to_bool_const_char(unique.contains(p1))
              << " : "
              << " contains p2? "
              << int_to_bool_const_char(unique.contains(p2))
              << std::endl;
    return 0;
}
