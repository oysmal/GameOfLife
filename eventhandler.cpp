#include "eventhandler.h"

EventHandler::EventHandler()
{
    this->subscribers = std::map<Event::EVENT, std::vector<Subscriber*>>();
    for(int e = Event::EVENT::ITERATION_FINISHED; e != Event::EVENT::VALUE_CHANGED; e++) {
        Event::EVENT event = static_cast<Event::EVENT>(e);
        subscribers.insert(std::pair<Event::EVENT, std::vector<Subscriber*>>(event, std::vector<Subscriber*>()));
    }
    this->event_queue = std::vector<Event*>();

}


void EventHandler::subscribe(Event::EVENT e, Subscriber *s) {
    subscribers.at(e).push_back(s);
}

void EventHandler::cancel_subscription(Event::EVENT e, Subscriber *s) {
    std::vector<Subscriber*>::iterator it;
    auto get_position_in_list = [&] () {
        for(it = subscribers.at(e).begin(); it != subscribers.at(e).end(); it++) {
            if(*it == s) break;
        }
        return it;
    };
    it = get_position_in_list();

    if(it != subscribers.at(e).end())
        subscribers.at(e).erase(it);
}

void EventHandler::add_event_to_queue(Event* e) {
    event_queue.push_back(e);
}

void EventHandler::notify_subscribers() {
    for(Event *e : event_queue) {
        for(Subscriber *s : subscribers.at(e->get_event_type())) {
            s->notify(e);
        }
    }
    event_queue.clear();
}

EventHandler::~EventHandler() {
    subscribers.clear();
    event_queue.clear();
}
