#include <iostream>
#include <vector>
#include <cstdint>

#include "vec2.h"
#include "mat2.h"

using namespace std;
using namespace math;

int main() {
    auto a = vec2f{1.f, 1.f};
    auto b = vec2f{2.f, 3.f};
    cout << a + b << endl;
    cout << 3.f * a << endl;
    cout << a / 0.3f << endl;
    cout << dot(b, b) << endl;

    auto ma = mat2f{1.f, 2.f, 3.f, 4.f};
    auto mb = mat2f{1.f, 2.f, 3.f, 4.f};

    cout << ma * mb << endl;
    cout << ma * 0.5f << endl;

    auto v = vec2f{1.f, 0.f};
    auto mr = mat2f::rotation(3.14f / 2.f);
    auto vr = mr * v;
    cout << vr << endl;

    return 0;
}
