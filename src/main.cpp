#include <algorithm>
#include <array>
#include <iostream>
#include <random>
#include <string>
#include <utility>

constexpr int SIZE = 8;
using Map = std::array<std::string, SIZE>;

void draw(const Map& map, int health, int treasure) {
    std::cout << "\nHealth: " << health << " | Treasure: " << treasure << "\n";
    for (const auto& row : map) std::cout << row << "\n";
    std::cout << "Move with W/A/S/D, Q to quit.\n";
}

int main() {
    Map map = {
        "########",
        "#@.#...#",
        "#..$...#",
        "#.##.#.#",
        "#....M.#",
        "##.#...#",
        "#...#E.#",
        "########"
    };
    int px = 1, py = 1, health = 5, treasure = 0;
    std::mt19937 rng(std::random_device{}());

    while (health > 0) {
        draw(map, health, treasure);
        char input;
        std::cout << "> ";
        std::cin >> input;
        if (input == 'q' || input == 'Q') break;

        int nx = px, ny = py;
        if (input == 'w' || input == 'W') --ny;
        if (input == 's' || input == 'S') ++ny;
        if (input == 'a' || input == 'A') --nx;
        if (input == 'd' || input == 'D') ++nx;
        if (map[ny][nx] == '#') { std::cout << "A wall blocks the way.\n"; continue; }

        if (map[ny][nx] == '$') { ++treasure; map[ny][nx] = '.'; }
        if (map[ny][nx] == 'E') {
            std::cout << "You escaped with " << treasure << " treasure. You win!\n";
            return 0;
        }
        if (map[ny][nx] == 'M') {
            --health;
            std::cout << "The monster hits you!\n";
            continue;
        }

        map[py][px] = '.';
        px = nx; py = ny;
        map[py][px] = '@';

        // The monster takes one random step after the player.
        std::array<std::pair<int,int>, 4> moves{{{0,-1},{0,1},{-1,0},{1,0}}};
        std::shuffle(moves.begin(), moves.end(), rng);
        for (const auto& move : moves) {
            int mx = 0, my = 0;
            for (int y = 0; y < SIZE; ++y)
                for (int x = 0; x < SIZE; ++x)
                    if (map[y][x] == 'M') { mx = x; my = y; }
            const int tx = mx + move.first, ty = my + move.second;
            if (tx > 0 && tx < SIZE - 1 && ty > 0 && ty < SIZE - 1 &&
                map[ty][tx] == '.' && !(tx == px && ty == py)) {
                map[my][mx] = '.';
                map[ty][tx] = 'M';
                break;
            }
        }
    }
    std::cout << (health <= 0 ? "You were defeated.\n" : "Game ended.\n");
}
