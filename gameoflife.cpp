#include "gameoflife.h"
#include "rules.h"
#include "grid.h"
#include "eventinterface.h"
#include "subscriber.h"
using namespace std;

Gameoflife::Gameoflife() {

}

Gameoflife::~Gameoflife() {

}

void Gameoflife::iterator() {
    tick++;
}

void Gameoflife::iterator_step(int n) {
    for(int i = 0; i < n; i++) {
        Gameoflife::apply_rules();
        tick++;
    }
}

void Gameoflife::open_file(std::string filePath) {
    FileManager.open_file(filePath);
}

// denne må opptimaliseres, slik at den ikke går igjennom hele for hver gang.
// int x og int y er størrelsen på gridden.
void Gameoflife::apply_rules() {
    for(int i = 0; i < Grid::getInstance().get_size_x(); i++){
        for(int j = 0; j < Grid::getInstance().get_size_y(); j++){
            int temp = rules.test_neighbour(i, j);
            rules.breed(i, j, temp);
            rules.kill(i, j, temp);
        }
    }
}

void Gameoflife::new_rules(vector<int> breed, vector<int> alive) {
    rules.set_alive(alive);
    rules.set_breed(breed);
}
