#ifndef KLOTSKI_H
#define KLOTSKI_H

#include <vector>
#include <string>
#include <ostream>

struct Position {
    int x;
    int y;
};

class Klotski {
public:
    const int width;
    const int height;

    // Default game configuration
    Klotski();

    int get_block(int x, int y) const;

    int get_block(Position position) const;

    char get_char(int x, int y) const;

    char get_char(Position position) const;

    std::string display() const;

    std::string signature() const;

    friend std::ostream &operator<<(std::ostream &ostream, const Klotski &klotski);

private:
    Klotski(std::vector<std::vector<int>> board, unsigned int keyBlock, std::vector<Position> targetPos);

    // Current position of blocks on the board.
    // Positions are accessed in the format [y][x].
    // If the value of a position is >= 0, it means the block with said value is occupying this position.
    // If the value is < 0, it means the position is free.
    std::vector<std::vector<int>> board;

    // ID of the block that must be moved to target_pos to win
    unsigned int key_block;

    // If all of the positions in target_pos are occupied by the block with ID key_block, the game is won.
    std::vector<Position> target_pos;
};

#endif //KLOTSKI_H
