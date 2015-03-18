/**
*   Event class. Objects of this type are used for communication between objects
*   who inherit from EventInterface and subscribers.
*   Data can be transferred with the event as a vector of strings. E.g. filepaths.
*   Try to keep these data transfers small though, as events can be sent to many subscribers and thus
*   limit performance if too much data is transferred.
*
*/



#ifndef EVENT_H
#define EVENT_H

#include <vector>
#include <string>

class Event
{
public:

    // Types of event to create.
    enum EVENT { STOP_GAME, AUTO_STEP, NEXT_STEP, VALUE_CHANGED, LOADED_FILE, ITERATION_FINISHED };

    // Create event without data.
    Event(EVENT event_type);

    // Create event with data.
    Event(EVENT event_type, std::vector<std::string> data);

    ~Event();

    // Get the data from event
    std::vector<std::string> get_data();

    // Get the event type.
    EVENT get_event_type();

private:
    std::vector<std::string> data;
    EVENT event_type;
};


#endif // EVENT_H
