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

    int get_tick();
    void open_file(std::string filePath);
    void iterator();
    void iterator_step(int n);
    void apply_rules();
    void test_neighbour(int x, int y);
    void new_rules(std::vector<int> breed, std::vector<int> alive);

private:
    int tick;
    Rules rules;
    FileManager filemanager;
};

#endif // GAMEOFLIFE_H
