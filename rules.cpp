#include "rules.h"
#include "grid.h"

rules::rules() {
    alive_values[] = new int[2];
    alive_values[0] = 2;
    alive_values[1] = 3;
    breed_values[] = new int[1];
    breed_values[0] = 3;
}

rules::~rules() {

}

rules::set_alive(){

}

rules::set_breed(){

}

rules::get_alive(){

}

rules::get_breed(){

}

// x og y, vet jeg ikke hvor kommer fra, kanskje game of life skal gjøre dette.
rules::breed (int x, int y, int neighbour) {
    for (int i = 0; i < i; i++) { //put inn størrelsen på arrayen til breed_value
        if (breed_value[i] == neighbour){
            grid::set_value_at(x, y, true);
        }
    }
}

//denne må endres til å drepe
rules::kill (int x, int y, int neighbour) {
    for (int i = 0; i < i; i++) { //put inn størrelsen på arrayen til alive_value
        if (alive_value[i] == neighbour){
            grid::set_value_at(x, y, true);
        }
    }
}

int rules::test_neighbour(int x, int y){
    int temp = 0;
    if(grid::get_value_at(x+1, y)) {
        temp++;
    }
    if(grid::get_value_at(x, y+1)) {
        temp++;
    }
    if(grid::get_value_at(x+1, y+1)) {
        temp++;
    }
    if(grid::get_value_at(x, y-1)) {
        temp++;
    }
    if(grid::get_value_at(x-1, y)) {
        temp++;
    }
    if(grid::get_value_at(x-1, y-1)) {
        temp++;
    }
    return temp;
}
