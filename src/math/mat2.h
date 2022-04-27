#pragma once

#include <cstdint>
#include <cmath>
#include <type_traits>
#include <ostream>

#include "vec2.h"

namespace math {
    template <typename T>
    struct mat2 {
        T m[2][2];

        mat2(T m00, T m01, T m10, T m11)
            : m {{m00, m01}, {m10, m11}}
        {}

        mat2<T>& operator += (mat2<T> const& rhs) {
            m[0][0] += rhs.m[0][0];
            m[0][1] += rhs.m[0][1];
            m[1][0] += rhs.m[1][0];
            m[1][1] += rhs.m[1][1];
            return *this;
        }

        mat2<T>& operator -= (mat2<T> const& rhs) {
            m[0][0] += rhs.m[0][0];
            m[0][1] += rhs.m[0][1];
            m[1][0] += rhs.m[1][0];
            m[1][1] += rhs.m[1][1];
            return *this;
        }

        mat2<T>& operator *= (T rhs) {
            m[0][0] *= rhs;
            m[0][1] *= rhs;
            m[1][0] *= rhs;
            m[1][1] *= rhs;
            return *this;
        }

        mat2<T>& operator /= (T rhs) {
            m[0][0] /= rhs;
            m[0][1] /= rhs;
            m[1][0] /= rhs;
            m[1][1] /= rhs;
            return *this;
        }

        static mat2<T> eye() {
            return mat2<T>{T(1), T(0), T(0), T(1)};
        }

        static mat2<T> rotation(T a) {
            auto cosa = std::cos(a);
            auto sina = std::sin(a);
            return mat2<T> {cosa, -sina, sina, cosa};
        }
    };

    template <typename T>
    inline
    std::ostream& operator << (std::ostream& o, mat2<T> const& m) {
        o << "mat2{{" << m.m[0][0] << ", " << m.m[0][1] << "}, {" << 
                         m.m[1][0] << ", " << m.m[1][1] << "}}";
        return o;
    }

    template <typename T>
    inline
    mat2<T> operator + (mat2<T> const& lhs, mat2<T> const& rhs) {
        auto res = lhs;
        return res += rhs;
    }

    template <typename T>
    inline
    mat2<T> operator * (mat2<T> const& lhs, T rhs) {
        auto res = lhs;
        return res *= rhs;
    }

    template <typename T>
    inline
    mat2<T> operator * (T lhs, mat2<T>  const& rhs) {
        auto res = rhs;
        return res *= lhs;
    }

    template <typename T>
    inline
    mat2<T> operator / (mat2<T> const& lhs, T rhs) {
        auto res = lhs;
        return res /= rhs;
    }

    template <typename T>
    inline
    mat2<T> operator * (mat2<T> const& lhs, mat2<T> const& rhs) {
        return mat2<T> {
            lhs.m[0][0] * rhs.m[0][0] + lhs.m[0][1] * rhs.m[1][0],
            lhs.m[0][0] * rhs.m[0][1] + lhs.m[0][1] * rhs.m[1][1],
            lhs.m[1][0] * rhs.m[0][0] + lhs.m[1][1] * rhs.m[1][0],
            lhs.m[1][0] * rhs.m[0][1] + lhs.m[1][1] * rhs.m[1][1]
        };
    }

    template <typename T>
    inline
    vec2<T> operator * (mat2<T> const& lhs, vec2<T> const& rhs) {
        return vec2<T> {
            lhs.m[0][0] * rhs.x + lhs.m[0][1] * rhs.y,
            lhs.m[1][0] * rhs.x + lhs.m[1][1] * rhs.y
        };
    }

    using mat2f = mat2<float>;
} // namespace math
