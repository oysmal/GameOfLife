#include "gameoflife.h"
#include "rules.h"
#include "grid.h"
#include "eventinterface.h"
#include "subscriber.h"

Gameoflife::Gameoflife() {

}

Gameoflife::~Gameoflife() {

}

void Gameoflife::iterator() {
    tick++;
}

void Gameoflife::load_file() {

}

// denne må opptimaliseres, slik at den ikke går igjennom hele for hver gang.
void Gameoflife::apply_rules(int x, int y) {
    for(int i = 0; i < x; i++){ // 1 skal være x størrelsen i gridden
        for(int j = 0; j < y; j++){ // 1 skal være y i gridden
            int temp = rules.test_neighbour(i, j);
            rules.breed(i, j, temp);
            rules.kill(i, j, temp);
        }
    }
}

void Gameoflife::new_rules(std::vector<int> breed, std::vector<int> alive) {
    rules.set_alive(alive);
    rules.set_breed(breed);
}
