#ifndef EVENTINTERFACE_H
#define EVENTINTERFACE_H

#include "event.h"
#include "eventhandler.h"

class EventInterface
{
public:
    EventInterface();
    ~EventInterface();

    void add_event_to_queue(Event *e);

};

#endif // EVENTINTERFACE_H
