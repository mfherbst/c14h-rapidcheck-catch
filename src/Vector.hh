#pragma once
#include <cassert>
#include <memory>

template <typename Scalar>
class Vector {
  public:
    typedef Scalar scalar_type;

    Vector(size_t size, bool fill_zero = true);

    Vector(const Vector& other);
    Vector(Vector&& other) = default;

    Vector& operator+=(const Vector& other);

    Vector& operator-=(const Vector& other);

    scalar_type& operator[](size_t i);

    scalar_type operator[](size_t i) const;

    size_t size() const;

    const scalar_type* begin() const;
    const scalar_type* end() const;

    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;

  private:
    std::unique_ptr<Scalar[]> m_data;
    size_t m_size;
};

template <typename Scalar>
Scalar inprod(const Vector<Scalar>& v1, const Vector<Scalar>& v2);

template <typename Scalar>
Vector<Scalar> operator+(Vector<Scalar> lhs, const Vector<Scalar>& rhs);

template <typename Scalar>
Vector<Scalar> operator-(Vector<Scalar> lhs, const Vector<Scalar>& rhs);

#include "Vector.impl.hh"
