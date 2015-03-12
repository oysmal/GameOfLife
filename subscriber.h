#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "event.h"

class Subscriber
{
public:
    Subscriber();
    virtual ~Subscriber();

    bool operator== (std::shared_ptr<Subscriber> s) { return this == s.get();};
    virtual void notify(std::shared_ptr<gol::Event> e) = 0;
    void subscribe(gol::Event::EVENT e);
};

#endif // SUBSCRIBER_H
