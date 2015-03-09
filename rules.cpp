#include "rules.h"
#include "grid.h"
using namespace std;

rules::rules() {
    alive_values(2);
    alive_values.push_back(2);
    alive_values.push_back(3);
    breed_values(1);
    breed_values.push_back(3);
}

rules::~rules() {

}

vector<int> rules::get_alive(){
    return alive_values;
}

vector<int> rules::get_breed(){
    return breed_values;
}

rules::breed (int x, int y, int neighbour) {
    for (int i = 0; i < breed_values.size(); i++) { //put inn størrelsen på arrayen til breed_value
        if (breed_values[i] == neighbour){
            grid::set_value_at(x, y, true);
        }
    }
}

//denne må endres til å drepe
rules::kill (int x, int y, int neighbour) {
    for (int i = 0; i < alive_values.size(); i++) { //put inn størrelsen på arrayen til alive_value
        if (alive_values[i] == neighbour){
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
