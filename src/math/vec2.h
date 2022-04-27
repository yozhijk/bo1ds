#pragma once

#include <cstdint>
#include <cmath>
#include <type_traits>
#include <ostream>

namespace math {
    template <typename T> //requires std::is_arithmetic<T>
    struct vec2 {
        T x;
        T y;

        vec2<T>& operator += (vec2<T> const& rhs) {
            x += rhs.x;
            y += rhs.y;
            return *this;
        }

        vec2<T>& operator -= (vec2<T> const& rhs) {
            x -= rhs.x;
            y -= rhs.y;
            return *this;
        }

        vec2<T>& operator *= (vec2<T> const& rhs) {
            x *= rhs.x;
            y *= rhs.y;
            return *this;
        }

        vec2<T>& operator *= (T a) {
            x *= a;
            y *= a;
            return *this;
        }

        vec2<T>& operator /= (T a) {
            x /= a;
            y /= a;
            return *this;
        }

        bool operator == (vec2<T> const& rhs) const {
            return x == rhs.x && y == rhs.y;
        }
    };

    template <typename T> 
    inline
    std::ostream& operator << (std::ostream& o, vec2<T> const& v) {
        o << "vec2{" << v.x << ", " << v.y << "}";
        return o;
    }

    template <typename T>
    inline
    vec2<T> operator + (vec2<T> const& lhs, vec2<T> const& rhs) {
        auto res = lhs;
        return res += rhs;
    }

    template <typename T>
    inline
    vec2<T> operator * (vec2<T> const& lhs, vec2<T> const& rhs) {
        auto res = lhs;
        return res *= rhs;
    }

    template <typename T>
    inline
    vec2<T> operator * (vec2<T> const& lhs, T rhs) {
        auto res = lhs;
        return res *= rhs;
    }

    template <typename T>
    inline
    vec2<T> operator * (T lhs, vec2<T>  const& rhs) {
        auto res = rhs;
        return res *= lhs;
    }

    template <typename T>
    inline
    vec2<T> operator / (vec2<T> const& lhs, T rhs) {
        auto res = lhs;
        return res /= rhs;
    }

    template <typename T>
    inline
    T dot(vec2<T> const& lhs, vec2<T> const& rhs) {
        return lhs.x * rhs.x + lhs.y * rhs.y;
    }
    
    template <typename T>
    inline
    T approx_eq(vec2<T> const& lhs, vec2<T> const& rhs, T eps = T(1e-5f)) {
        return std::abs(lhs.x - rhs.x) < eps && std::abs(lhs.x - rhs.x) < eps;
    }

    using vec2f = vec2<float>;
} // namespace math
