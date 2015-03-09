#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H


class gameoflife
{
public:
    gameoflife();
    ~gameoflife();
    iterator();
    apply_rules(int x, int y);
    test_neighbour(int x, int y);
    new_rules(int breed[], int alive[]);

private:
    int tick;
    rules rules;
    grid grid;
    filemanager filemanager;
};

#endif // GAMEOFLIFE_H
