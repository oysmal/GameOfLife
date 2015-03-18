#ifndef GRID_H
#define GRID_H

#include <qDebug>
#include <memory>

class Grid
{
public:
    ~Grid();

    // Get instance. instance is instantiated on first call, and when done without pointers, this is guaranteed to be correctly destroyed.
    static Grid& getInstance() {
        if(!isInstanceInit) {
            instance = std::shared_ptr<Grid>(new Grid());
            isInstanceInit = true;
        }
        return *instance.get();
    };

    static Grid& getTempInstance() {
        if(!isTempInit) {
            tempinstance = std::shared_ptr<Grid>(new Grid());
            isTempInit = true;
        }
        return *tempinstance.get();
    }

    static void delete_grid() {
        instance.reset();
        tempinstance.reset();
    }

    static void swap_temp_grid_to_front();
    bool get_value_at(int x, int y);
    void set_value_at(int x, int y, bool value);
    size_t get_size_x();
    size_t get_size_y();
    void expand_grid_array(int expand_points_x, int expand_points_y);
    void clear_and_set_size(int size_x, int size_y);

private:

    static std::shared_ptr<Grid> instance;
    static std::shared_ptr<Grid> tempinstance;
    static bool isInstanceInit;
    static bool isTempInit;
    Grid();
    Grid(Grid const&) = delete;
    void operator=(Grid const&) = delete;

    bool** grid_array;
    size_t size_x = 100;
    size_t size_y = 100;
};

#endif // GRID_H
