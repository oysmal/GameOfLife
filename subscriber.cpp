#include "subscriber.h"
#include "eventhandler.h"

Subscriber::Subscriber()
{

}

Subscriber::~Subscriber()
{

}

void Subscriber::subscribe(Event::EVENT e) {
    EventHandler::getInstance().subscribe(e, this->get_shared_ptr());
}
