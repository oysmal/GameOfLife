#include "eventtest.h"
#include <QDebug>

int EventTest::event_count = 0;

EventTest::EventTest()
{
    subscribe(Event::EVENT::AUTO_STEP);
    //subscribe(Event::EVENT::NEXT_STEP);
    qDebug() << "subscribed to AUTO_STEP\n";
}

EventTest::~EventTest()
{

}

void EventTest::notify(Event::EVENT e) {
    qDebug() << "Event recieved\n";
    event_count++;
}

