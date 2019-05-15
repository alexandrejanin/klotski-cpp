#include <utility>
#include "klotski.h"


// Public

Klotski::Klotski()
        : Klotski({{0, 1,  1,  2},
                   {0, 1,  1,  2},
                   {3, 4,  4,  5},
                   {3, 6,  7,  5},
                   {8, -1, -1, 9},
                  },
                  1,
                  {Position{1, 3},
                   Position{2, 3},
                   Position{1, 4},
                   Position{2, 4},
                  }) {}

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

bool Klotski::down(unsigned int block) {
    return down_n(block, 1);
}

bool Klotski::down2(unsigned int block) {
    return down_n(block, 2);
}

bool Klotski::down_n(unsigned int block, int n) {
    if (!can_move_down(block, n))
        return false;

    std::vector<Position> positionsToMove;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // For each position of the selected block
            if (get_block(x, y) == block) {
                // Insert at the start so that we iterate the block from bottom to top when moving
                positionsToMove.push_back(Position{x, y});
            }
        }
    }

    // Chosen block doesn't exist, return false
    if (positionsToMove.empty()) {
        return false;
    }

    // No position returned false, we can move them and return true
    for (int i = 0; i < n; ++i) {
        for (Position &position : positionsToMove) {
            set_block(position, -1);
            position.y++;
            set_block(position, block);
        }
    }

    return true;
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


// Private

Klotski::Klotski(std::vector<std::vector<int>> board, unsigned int keyBlock, std::vector<Position> targetPos)
        : width(board[0].size()), height(board.size()), board(std::move(board)), key_block(keyBlock), target_pos(std::move(targetPos)) {}

void Klotski::set_block(int x, int y, int block) {
    board[y][x] = block;
}

void Klotski::set_block(Position position, int block) {
    set_block(position.x, position.y, block);
}

bool Klotski::can_move_down(unsigned int block, int n) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // For each position of the selected block
            if (get_block(x, y) == block) {
                // Block is too low, would exit board
                if (y >= height - n)
                    return false;

                for (int i = 1; i <= n; ++i) {
                    // If a the position if taken by a different block, return false
                    int down_block = get_block(x, y + i);
                    if (down_block > 0 && down_block != block) {
                        return false;
                    }

                }
            }
        }
    }
    return true;
}
