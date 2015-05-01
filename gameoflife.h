#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include "grid.h"
#include "rules.h"
#include "filemanager.h"

class Gameoflife
{
public:
    Gameoflife();
    ~Gameoflife();

    int get_step();
    void open_file(std::string filePath);
    void iterate();
    void apply_rules();
    void test_neighbour(int x, int y);
    void new_rules(std::vector<int> breed, std::vector<int> alive);

private:
    int step;
    bool loop;
    Rules rules;
    FileManager filemanager;
};

#endif // GAMEOFLIFE_H
