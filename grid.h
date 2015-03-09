#ifndef GRID_H
#define GRID_H

#include "eventinterface.h"

class Grid : public EventInterface
{
public:
    ~Grid();

    // Get instance. instance is instantiated on first call, and when done without pointers, this is guaranteed to be correctly destroyed.
    static Grid& getInstance() {
            static Grid instance;
            return instance;
    };


    bool get_value_at(int x, int y);
    void set_value_at(int x, int y, bool value);
    size_t get_size_x();
    size_t get_size_y();
    void expand_grid_array(int expand_points_x, int expand_points_y);
    void clear_and_set_size(int size_x, int size_y);

private:

    Grid();
    Grid(Grid const&) = delete;
    void operator=(Grid const&) = delete;

    bool** grid_array;
    size_t size_x = 100;
    size_t size_y = 100;
};

#endif // GRID_H
