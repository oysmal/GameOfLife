#include "eventtest.h"
#include <QDebug>

int EventTest::event_count = 0;

EventTest::EventTest()
{
    subscribe(gol::Event::EVENT::AUTO_STEP);
    //subscribe(Event::EVENT::NEXT_STEP);
    qDebug() << "subscribed to AUTO_STEP\n";
}

EventTest::~EventTest()
{

    qDebug() << "Exiting..";
}

void EventTest::notify(std::shared_ptr<gol::Event> e) {
    qDebug() << "Event recieved\n";
    event_count++;
}

