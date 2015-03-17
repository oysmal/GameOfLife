#include "eventhandler.h"
#include <qdebug>

EventHandler::EventHandler()
{
    this->subscribers = std::map<Event::EVENT, std::vector<std::shared_ptr<Subscriber>>>();
    for(int e = Event::EVENT::ITERATION_FINISHED; e != Event::EVENT::VALUE_CHANGED; e++) {
        Event::EVENT event = static_cast<Event::EVENT>(e);
        subscribers.insert(std::pair<Event::EVENT, std::vector<std::shared_ptr<Subscriber>>>(event, std::vector<std::shared_ptr<Subscriber>>()));
    }
    this->event_queue = std::vector<std::shared_ptr<Event>>();

}


void EventHandler::subscribe(Event::EVENT e, std::shared_ptr<Subscriber> s) {
    subscribers.at(e).push_back(s);
}

void EventHandler::cancel_subscription(Event::EVENT e, std::shared_ptr<Subscriber> s) {
    std::vector<std::shared_ptr<Subscriber>>::iterator it;
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

void EventHandler::add_event_to_queue(std::shared_ptr<Event> e) {
    event_queue.push_back(e);
}

void EventHandler::notify_subscribers() {
    for(std::shared_ptr<Event> e : event_queue) {
        for(std::shared_ptr<Subscriber> s : subscribers.at(e->get_event_type())) {
            s->notify(e);
        }
    }
    event_queue.clear();
}

EventHandler::~EventHandler() {

    //subscribers.clear();
    //event_queue.clear();

}
