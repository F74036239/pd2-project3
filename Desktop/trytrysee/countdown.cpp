#include "countdown.h"

countdown::countdown(QObject* parent) : QTimer(parent)
{
  connect(this, SIGNAL(timeout()), this, SLOT(resettime());
}

void countdown::start()
{
  m_time.start();
  QTimer::start();
}

int countdown::timeLeft()
{
  return interval()-m_time.elapsed();
}

void countdown::resettime()
{
  m_time.restart();
}


countdown::~countdown()
{

}

