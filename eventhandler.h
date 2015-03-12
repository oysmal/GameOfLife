/**
*   Eventhandler class. Implemented as a singleton, this class only ever has one instance.
*   The class handles all subscriptions to Events, and is responsible for notifying the
*   subscribers when events are added to the eventqueue.
*
*/




#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <map>
#include <vector>
#include "subscriber.h"
#include "event.h"


class EventHandler
{
public:

    // Subscribe to an event.
    void subscribe(Event::EVENT e, std::shared_ptr<Subscriber> s);

    // Cancel a subscription to an event for a subscriber.
    void cancel_subscription(Event::EVENT e, std::shared_ptr<Subscriber> s);

    // Add an event to a queue.
    void add_event_to_queue(std::shared_ptr<Event> e);

    // Notify the subscribers of the events in the eventqueue, and remove the events from the queue
    void notify_subscribers();

    ~EventHandler();

    // Get instance. instance is instantiated on first call, and when done without pointers, this is guaranteed to be correctly destroyed.
    static EventHandler& getInstance() {
            static EventHandler instance;
            return instance;
    };

private:
    // Map of events and list of subscribers to each event.
    std::map<Event::EVENT, std::vector<std::shared_ptr<Subscriber>>> subscribers;

    // Eventqueue
    std::vector<std::shared_ptr<Event>> event_queue;

    // Private constructor so only the getInstance method can instatiate an object of the class.
    EventHandler();

    // Do not allow
    EventHandler(EventHandler const&) = delete;
    void operator=(EventHandler const&) = delete;
};

#endif // EVENTHANDLER_H
