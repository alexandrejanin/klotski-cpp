#include <utility>
#include "klotski.h"

Klotski::Klotski()
        : Klotski({{0, 1,  1,  2},
                   {0, 1,  1,  2},
                   {3, 4,  4,  5},
                   {3, 6,  7,  5},
                   {8, -1, -1, 9}
                  },
                  1,
                  {{1, 3},
                   {2, 3},
                   {1, 4},
                   {2, 4}
                  }) {}

Klotski::Klotski(std::vector<std::vector<int>> board, unsigned int keyBlock, std::vector<Position> targetPos)
        : width(board[0].size()), height(board.size()), board(std::move(board)), key_block(keyBlock), target_pos(std::move(targetPos)) {}

std::ostream &operator<<(std::ostream &ostream, const Klotski &klotski) {
    return ostream << klotski.display();
}

int Klotski::get_block(int x, int y) const {
    return board[y][x];
}

int Klotski::get_block(Position position) const {
    return get_block(position.x, position.y);
}

char Klotski::get_char(int x, int y) const {
    int block = get_block(x, y);
    if (block < 0)
        return '.';
    return '0' + block;
}

char Klotski::get_char(Position position) const {
    return get_char(position.x, position.y);
}

std::string Klotski::display() const {
    std::string string;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            string += get_char(x, y);
        }
        string += '\n';
    }
    return string;
}

std::string Klotski::signature() const {
    std::string sig;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            sig += get_char(x, y);
        }
    }
    return sig;
}
