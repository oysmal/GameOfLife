#ifndef EVENT_H
#define EVENT_H

#include <vector>
#include <string>

class Event
{
public:
    // Types of event to send.
    enum EVENT { ITERATION_FINISHED, AUTO_STEP, MANUAL_STEP, NEXT_STEP, VALUE_CHANGED, LOADED_FILE };

    Event(EVENT event_type);
    Event(EVENT event_type, std::vector<std::string> data);
    ~Event();

    std::vector<std::string> get_data();
    EVENT get_event_type();

private:
    std::vector<std::string> data;
    EVENT event_type;
};


#endif // EVENT_H
