#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "event.h"

class Subscriber
{
public:
    Subscriber();
    virtual ~Subscriber();

    bool operator== (Subscriber &s) { return this == &s;};
    virtual void notify(Event::EVENT e) = 0;
    void subscribe(Event::EVENT e);
};

#endif // SUBSCRIBER_H
