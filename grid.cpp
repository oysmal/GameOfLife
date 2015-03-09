#include "grid.h"
#include <QDebug>

Grid::Grid()
{
    grid_array = new bool*[size_x];
    for( int i = 0; i < size_x; i++) {
        grid_array[i] = new bool[size_y];
    }
}

Grid::~Grid()
{
    delete grid_array;
}

bool Grid::get_value_at(int x, int y) {
    qDebug() << "Getting value at: " << x << ", " << y << "Size of array is: " << size_x << ", " << size_y << ".\n";
    if(x < size_x && y < size_y)
        return grid_array[x][y];
    else
        return false;
}

void Grid::set_value_at(int x, int y, bool value) {
    if(x < size_x && y < size_y)
        grid_array[x][y] = value;
}

size_t Grid::get_size_x() {
    return size_x;
}

size_t Grid::get_size_y(){
    return size_y;
}

void Grid::expand_grid_array(int expand_points_x, int expand_points_y) {
    bool** array = new bool*[size_x + expand_points_x];
    for( int i = 0; i < size_x + expand_points_x; i++) {
        array[i] = new bool[size_y + expand_points_y];
    }

    for(int i = 0; i < size_x; i++) {
        for(int j = 0; j < size_y; j++) {
            array[i][j] = grid_array[i][j];
        }
    }

    delete grid_array;
    grid_array = array;
    size_x += expand_points_x;
    size_y += expand_points_y;
}

void Grid::clear_and_set_size(int size_x, int size_y) {
    delete this->grid_array;

    grid_array = new bool*[size_x];
    for( int i = 0; i < size_x; i++) {
        grid_array[i] = new bool[size_y];
    }

    this->size_x = size_x;
    this->size_y = size_y;
}
