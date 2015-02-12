#ifndef EVENT_H
#define EVENT_H


class Event
{
public:
    Event();
    ~Event();

     enum EVENT { ITERATION_FINISHED, AUTO_STEP, MANUAL_STEP, NEXT_STEP, VALUE_CHANGED };
};

#endif // EVENT_H
