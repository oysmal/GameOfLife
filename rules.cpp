#include "rules.h"
#include "grid.h"
using namespace std;

Rules::Rules() {
    alive_values.push_back(2);
    alive_values.push_back(3);
    breed_values.push_back(3);
}

Rules::~Rules() {

}

vector<int> Rules::get_alive(){
    return alive_values;
}

vector<int> Rules::get_breed(){
    return breed_values;
}

void Rules::set_alive(vector<int> values) {
    alive_values = values;
}

void Rules::set_breed(vector<int> values) {
    breed_values = values;
}


void Rules::breed (int x, int y, int neighbour) {
    for (int i = 0; i < breed_values.size(); i++) {
        if (breed_values[i] == neighbour){
            Grid::getInstance().set_value_at(x, y, true);
        }
    }
}

void Rules::kill (int x, int y, int neighbour) {
    int temp = 0;
    for (int i = 0; i < alive_values.size(); i++) {
        if (alive_values[i] != neighbour){
            temp++;
        }
    }
    if(temp == alive_values.size()){
        Grid.set_value_at(x, y, false);
    }
}

int Rules::test_neighbour(int x, int y){
    int temp = 0;
    if(Grid::getInstance().get_value_at(x+1, y)) {
        temp++;
    }
    if(Grid::getInstance().get_value_at(x, y+1)) {
        temp++;
    }
    if(Grid::getInstance().get_value_at(x+1, y+1)) {
        temp++;
    }
    if(Grid::getInstance().get_value_at(x, y-1)) {
        temp++;
    }
    if(Grid::getInstance().get_value_at(x-1, y)) {
        temp++;
    }
    if(Grid::getInstance().get_value_at(x-1, y-1)) {
        temp++;
    }
    return temp;
}
