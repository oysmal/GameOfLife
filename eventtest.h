#ifndef EVENTTEST_H
#define EVENTTEST_H

#include "subscriber.h"
#include <iostream>

class EventTest : public Subscriber
{
public:
    EventTest();
    ~EventTest();
    void notify(Event::EVENT e);
    static int event_count;
};

#endif // EVENTTEST_H
