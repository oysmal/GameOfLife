/**
  * The Subscriber class must be inherited by all classes who wish to listen for events.
  * It provides the subscribe and notify methods, where notify is a pure virtual method
  * that needs to be implemented in each class that inherits from this class.
  * When an event the object has subscribed for is processed by the EventHandler, the
  * notify method is called, so you should implement your logic for handling the event there.
  *
  * All instances of the Subscriber class must be created as a shared_ptr with the "new" operator.
  *
*/

#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "event.h"

// Enable getting shared pointers to this object (used in EventHandler).
class Subscriber : public std::enable_shared_from_this<Subscriber>
{
public:
    Subscriber();
    // Destructor of virtual classes needs to be implemented in derived class.
    virtual ~Subscriber();

    // Get a shared pointer to this object.
    std::shared_ptr<Subscriber> get_shared_ptr() {
        return shared_from_this();
    }

    // Compare operator ==.
    bool operator== (std::shared_ptr<Subscriber> s) { return this == s.get();}

    // Virtual method notify must be implemented in subclass.
    virtual void notify(std::shared_ptr<Event> e) = 0;

    // Subscribe to an event.
    void subscribe(Event::EVENT e);
};

#endif // SUBSCRIBER_H
