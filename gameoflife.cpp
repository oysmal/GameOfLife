#include "rules.h"
#include "grid.h"
#include "gameoflife.h"
using namespace std;

Gameoflife::Gameoflife() {
    step = 0;
    loop = false;
}

Gameoflife::~Gameoflife() {

}

void Gameoflife::iterate() {
    step++;
    Gameoflife::apply_rules();
}



int Gameoflife::get_step() {
    return step;
}

// denne må opptimaliseres, slik at den ikke går igjennom hele for hver gang.
// int x og int y er størrelsen på gridden.
void Gameoflife::apply_rules() {
    for(int i = 0; i < Grid::getInstance().get_size_x(); i++){
        for(int j = 0; j < Grid::getInstance().get_size_y(); j++){
            int temp = rules.test_neighbour(i, j);
            rules.change(i, j, temp);
        }
    }
    Grid::swap_temp_grid_to_front();
}

void Gameoflife::new_rules(vector<int> breed, vector<int> alive) {
    rules.set_alive(alive);
    rules.set_breed(breed);
}
