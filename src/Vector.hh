#pragma once
#include <memory>
#include <cassert>

template <typename Scalar>
class Vector {
  public:
    typedef Scalar scalar_type;
    typedef size_t size_type;

    Vector(size_type size, bool fill_zero = true);

    Vector(const Vector& other);
    Vector(Vector&& other) = default;

    Vector& operator+=(const Vector& other);

    Vector& operator-=(const Vector& other);

    scalar_type& operator[](size_type i);

    scalar_type operator[](size_type i) const;

    size_type size() const;

    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;

  private:
    std::unique_ptr<Scalar[]> m_data;
    size_type m_size;
};

template <typename Scalar>
Vector<Scalar> operator+(Vector<Scalar> lhs, const Vector<Scalar>& rhs);

template <typename Scalar>
Vector<Scalar> operator-(Vector<Scalar> lhs, const Vector<Scalar>& rhs);

#include "Vector.impl.hh"
