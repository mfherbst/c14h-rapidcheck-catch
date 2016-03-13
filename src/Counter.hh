#pragma once

class Counter {
  public:
    long operator()() const;
    long value() const;

    /** increment and return current value */
    long increment();

    /** decrement and return current value */
    long decrement();

  private:
    long m_value = 0;
};
