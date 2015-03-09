#include "gameoflife.h"
#include "rules.h"
#include "grid.h"
#include "eventinterface.h"
#include "subscriber.h"

gameoflife::gameoflife() {

}

gameoflife::~gameoflife() {

}

gameoflife::iterator() {
    tick++;
}

gameoflife::load_file() {

}

// denne må opptimaliseres, slik at den ikke går igjennom hele for hver gang.
gameoflife::apply_rules(int x, int y) {
    for(int i = 0; i < x; i++){ // 1 skal være x størrelsen i gridden
        for(int j = 0; j < y; j++){ // 1 skal være y i gridden
            int temp = rules.test_neighbour(i, j);
            rules.breed(i, j, temp);
            rules.kill(i, j, temp);
        }
    }
}

gameoflife::new_rules(int breed[], int alive[]) {
    rules.set_alive(alive[]);
    rules.set_breed(breed[]);
}
