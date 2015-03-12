/**
  * The EventInterface class must be inherited by all classes who wish to add Events to the EventHandler's Event queue.
  * The class provides the method add_event_to_queue which(surprise, surprise) adds an event to the EventHandlers queue.
*/

#ifndef EVENTINTERFACE_H
#define EVENTINTERFACE_H

#include "event.h"
#include "eventhandler.h"


class EventInterface
{
public:
    EventInterface();
    ~EventInterface();

    // Add an event to the event queue
    void add_event_to_queue(std::shared_ptr<Event> e);

};

#endif // EVENTINTERFACE_H
