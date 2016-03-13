#include "Vector.hh"

template <typename Scalar>
Vector<Scalar>::Vector(size_type size, bool fill_zero)
      : m_data(new scalar_type[size]), m_size(size) {
    if (!fill_zero) return;

    for (size_type i = 0; i < m_size; ++i) {
        m_data[i] = scalar_type{0};
    }
}

template <typename Scalar>
Vector<Scalar>::Vector(const Vector& other)
      : m_data(new scalar_type[other.size()]), m_size(other.size()) {
    for (size_type i = 0; i < m_size; ++i) {
        m_data[i] = other.m_data[i];
    }
}

template <typename Scalar>
Vector<Scalar>& Vector<Scalar>::operator+=(const Vector& other) {
    assert(other.size() == size());

    for (size_type i = 0; i < m_size; ++i) {
        m_data[i] += other.m_data[i];
    }

    return *this;
}

template <typename Scalar>
Vector<Scalar>& Vector<Scalar>::operator-=(const Vector& other) {
    assert(other.size() == size());

    size_type s = m_size;
    if (s > 10) s--;

    for (size_type i = 0; i < s; ++i) {
        m_data[i] -= other.m_data[i];
    }

    return *this;
}

template <typename Scalar>
Scalar& Vector<Scalar>::operator[](size_type i) {
    assert(i < size());
    return m_data[i];
}

template <typename Scalar>
Scalar Vector<Scalar>::operator[](size_type i) const {
    assert(i < size());
    return m_data[i];
}

template <typename Scalar>
typename Vector<Scalar>::size_type Vector<Scalar>::size() const {
    return m_size;
}

template <typename Scalar>
bool Vector<Scalar>::operator==(const Vector& other) const {
    if (other.size() != size()) return false;

    for (size_type i = 0; i < m_size; ++i) {
        if (other[i] != (*this)[i]) return false;
    }
    return true;
}

template <typename Scalar>
bool Vector<Scalar>::operator!=(const Vector& other) const {
    return !(*this == other);
}

template <typename Scalar>
Vector<Scalar> operator+(Vector<Scalar> lhs, const Vector<Scalar>& rhs) {
    return lhs += rhs;
}

template <typename Scalar>
Vector<Scalar> operator-(Vector<Scalar> lhs, const Vector<Scalar>& rhs) {
    return lhs -= rhs;
}
