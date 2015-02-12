#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <map>
#include <vector>
#include "subscriber.h"
#include "event.h"

class EventHandler
{
public:

    void subscribe(Event::EVENT e, Subscriber *s);
    void cancel_subscription(Event::EVENT e, Subscriber *s);
    void add_event_to_queue(Event::EVENT e);
    void notify_subscribers();

    ~EventHandler();

    // Get instance. instance is instantiated on first call, and when done without pointers, this is guaranteed to be correctly destroyed.
    static EventHandler& getInstance() {
            static EventHandler instance;
            return instance;
    };

private:
    std::map<Event::EVENT, std::vector<Subscriber*>> subscribers;
    std::vector<Event::EVENT> event_queue;
    EventHandler();

    EventHandler(EventHandler const&) = delete;
    void operator=(EventHandler const&) = delete;
};

#endif // EVENTHANDLER_H
