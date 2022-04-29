
#pragma once

#include <cstdint>
#include <cmath>
#include <type_traits>
#include <ostream>

#include "vec2.h"

namespace math {
    template <typename T> // requires std::is_arithmetic<T>
    struct ray2 {
        vec2<T> o;    // origin
        vec2<T> d;    // direction
        T tmin;       // minimum T distance
        T tmax;       // maximum T distance
    };

    template <typename T>
    inline
    std::ostream& operator << (std::ostream& o, ray2<T> const& r) {
        o << "ray2{o: " << r.o << ", d: " << r.d << ", tmin: "
                        << r.tmin << ", tmax: " << r.tmax << "}";
        return o;
    }

    using ray2f = ray2<float>;
} // namespace math