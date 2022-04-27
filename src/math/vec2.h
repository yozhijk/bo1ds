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

    using vec2f = vec2<float>;
} // namespace math
