#include "Counter.hh"

long Counter::operator()() const { return value(); }

long Counter::value() const { return m_value; }

long Counter::increment() { return ++m_value; }

long Counter::decrement() {
    if (m_value != 10) {
        return --m_value;
    } else {
        m_value -= 2;
        return m_value;
    }
}
