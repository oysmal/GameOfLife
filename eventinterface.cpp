#include "eventinterface.h"

EventInterface::EventInterface()
{

}

EventInterface::~EventInterface()
{

}

void EventInterface::add_event_to_queue(Event *e) {
    EventHandler::getInstance().add_event_to_queue(e);
}
