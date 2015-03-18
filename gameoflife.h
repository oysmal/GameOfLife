#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include "grid.h"
#include "rules.h"
#include "filemanager.h"
#include "subscriber.h"
#include "eventinterface.h"

class Gameoflife: public Subscriber, public EventInterface
{
public:
    Gameoflife();
    ~Gameoflife();

    void notify(std::shared_ptr<Event> e);
    int get_step();
    void open_file(std::string filePath);
    void iterator();
    void iterator_auto();
    void iterator_step(int n);
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
