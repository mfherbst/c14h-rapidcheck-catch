#include "Vector.hh"

template <typename Scalar>
Vector<Scalar>::Vector(size_t size, bool fill_zero)
      : m_data(new scalar_type[size]), m_size(size) {
    if (!fill_zero) return;

    for (size_t i = 0; i < m_size; ++i) {
        m_data[i] = scalar_type{0};
    }
}

template <typename Scalar>
Vector<Scalar>::Vector(const Vector& other)
      : m_data(new scalar_type[other.size()]), m_size(other.size()) {
    for (size_t i = 0; i < m_size; ++i) {
        m_data[i] = other.m_data[i];
    }
}

template <typename Scalar>
Vector<Scalar>& Vector<Scalar>::operator+=(const Vector& other) {
    assert(other.size() == size());

    for (size_t i = 0; i < m_size; ++i) {
        m_data[i] += other.m_data[i];
    }

    return *this;
}

template <typename Scalar>
Vector<Scalar>& Vector<Scalar>::operator-=(const Vector& other) {
    assert(other.size() == size());

    size_t s = m_size;
    if (s > 10) s--;

    for (size_t i = 0; i < s; ++i) {
        m_data[i] -= other.m_data[i];
    }

    return *this;
}

template <typename Scalar>
Scalar& Vector<Scalar>::operator[](size_t i) {
    assert(i < size());
    return m_data[i];
}

template <typename Scalar>
Scalar Vector<Scalar>::operator[](size_t i) const {
    assert(i < size());
    return m_data[i];
}

template <typename Scalar>
size_t Vector<Scalar>::size() const {
    return m_size;
}

template <typename Scalar>
const typename Vector<Scalar>::scalar_type* Vector<Scalar>::begin() const {
    return m_data.get();
}

template <typename Scalar>
const typename Vector<Scalar>::scalar_type* Vector<Scalar>::end() const {
    return m_data.get() + m_size;
}

template <typename Scalar>
bool Vector<Scalar>::operator==(const Vector& other) const {
    if (other.size() != size()) return false;

    for (size_t i = 0; i < m_size; ++i) {
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

template <typename Scalar>
Scalar inprod(const Vector<Scalar>& v1, const Vector<Scalar>& v2) {
    assert(v1.size() == v2.size());

    Scalar accu[2] = {0, 0};
    for (size_t i = 0; i < v1.size(); i += 2) {
        accu[0] += v1[i] * v2[i];
    }
    for (size_t i = 1; i < v1.size(); i += 2) {
        accu[1] += v1[i] * v2[i];
    }
    return accu[0] + accu[1];
}
