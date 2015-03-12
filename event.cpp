#include "event.h"

gol::Event::Event(Event::EVENT event_type)
{
    this->event_type = event_type;
}

gol::Event::Event(Event::EVENT event_type, std::vector<std::string> data) {
    this->event_type = event_type;
    this->data = data;
}

std::vector<std::string> gol::Event::get_data() {
    return this->data;
}

gol::Event::EVENT gol::Event::get_event_type() {
    return this->event_type;
}

gol::Event::~Event()
{

}

