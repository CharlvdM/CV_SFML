////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2023 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

// Disable the GCC warnings
#if defined(__GNUG__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
#endif

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Transform.hpp>
#include <SFML/System/Angle.hpp>

#include <cmath>


namespace sf
{
////////////////////////////////////////////////////////////
Transform& Transform::rotate(Angle angle)
{
    float rad = angle.asRadians();
    float cos = std::cos(rad);
    float sin = std::sin(rad);

    // clang-format off
    Transform rotation(cos, -sin, 0,
                       sin,  cos, 0,
                       0,    0,   1);
    // clang-format on

    return combine(rotation);
}


////////////////////////////////////////////////////////////
Transform& Transform::rotate(Angle angle, const Vector2f& center)
{
    float rad = angle.asRadians();
    float cos = std::cos(rad);
    float sin = std::sin(rad);

    // clang-format off
    Transform rotation(cos, -sin, center.x * (1 - cos) + center.y * sin,
                       sin,  cos, center.y * (1 - cos) - center.x * sin,
                       0,    0,   1);
    // clang-format on

    return combine(rotation);
}

} // namespace sf
