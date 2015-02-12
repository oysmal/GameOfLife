#ifndef GRID_H
#define GRID_H

#include "eventinterface.h"

class Grid : public EventInterface
{
public:
    Grid();
    ~Grid();

    bool get_value_at(int x, int y);
    bool set_value_at(int x, int y, bool value);
    size_t get_size_x();
    size_t get_size_y();
    void expand_grid_array(int expand_points_x, int expand_points_y);
    void clear_and_set_size(int size_x, int size_y);

private:
    bool** grid_array;
    size_t size_x = 100;
    size_t size_y = 100;
};

#endif // GRID_H
