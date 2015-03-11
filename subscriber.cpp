#include "subscriber.h"
#include "eventhandler.h"

Subscriber::Subscriber()
{

}

Subscriber::~Subscriber()
{

}

void Subscriber::subscribe(Event::EVENT e) {
    EventHandler::getInstance().subscribe(e, std::shared_ptr<Subscriber>(this));
}
