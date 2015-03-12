#ifndef EVENTINTERFACE_H
#define EVENTINTERFACE_H

#include "event.h"
#include "eventhandler.h"


class EventInterface
{
public:
    EventInterface();
    ~EventInterface();

    void add_event_to_queue(std::shared_ptr<gol::Event> e);

};

#endif // EVENTINTERFACE_H
