#include "gameoflife.h"
#include "rules.h"
#include "grid.h"
#include "eventinterface.h"
#include "subscriber.h"
using namespace std;

Gameoflife::Gameoflife() {
    step = 0;
    loop = false;
    subscribe(Event::AUTO_STEP);
    subscribe(Event::NEXT_STEP);
    subscribe(Event::STOP_GAME);
}

Gameoflife::~Gameoflife() {

}

void Gameoflife::notify(shared_ptr<Event> e){
    Event::EVENT event = e->get_event_type();

    switch(event) {
    case Event::NEXT_STEP:
        Gameoflife::iterator();
        break;
    case Event::AUTO_STEP:
        loop = true;
        Gameoflife::iterator_auto();
        break;
    case Event::STOP_GAME:
        loop = false;
        break;
    }
}

void Gameoflife::iterate() {
    step++;
    Gameoflife::apply_rules();
    shared_ptr<Event> e = shared_ptr<Event>(new Event(Event::ITERATION_FINISHED));
    add_event_to_queue(e);
}

void Gameoflife::iterate_auto(){
    while(loop) {
        Gameoflife::apply_rules();
        shared_ptr<Event> e = shared_ptr<Event>(new Event(Event::ITERATION_FINISHED));
        add_event_to_queue(e);
    }
}

void Gameoflife::open_file(std::string filePath) {
    FileManager filemanager;
    filemanager.open_file(filePath);
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
