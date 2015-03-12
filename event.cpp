#include "event.h"

Event::Event(Event::EVENT event_type)
{
    this->event_type = event_type;
}

Event::Event(Event::EVENT event_type, std::vector<std::string> data) {
    this->event_type = event_type;
    this->data = data;
}

std::vector<std::string> Event::get_data() {
    return this->data;
}

Event::EVENT Event::get_event_type() {
    return this->event_type;
}

Event::~Event()
{

}

