// Header for SFML unit tests.
//
// For a new system module test case, include this header and not <doctest.h> directly.
// This ensures that string conversions are visible and can be used by doctest for debug output.

#ifndef SFML_TESTUTILITIES_SYSTEM_HPP
#define SFML_TESTUTILITIES_SYSTEM_HPP

#include <doctest.h>

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <sstream>
#include <string>

// String conversions for doctest framework
namespace sf
{
    class String;
    class Time;

    doctest::String toString(const sf::String& string);
    doctest::String toString(sf::Time time);

    template <typename T>
    doctest::String toString(const sf::Vector2<T>& vector)
    {
        std::ostringstream stream;
        stream << "(" << vector.x << ", " << vector.y << ")";
        return stream.str().c_str();
    }

    template <typename T>
    doctest::String toString(const sf::Vector3<T>& vector)
    {
        std::ostringstream stream;
        stream << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
        return stream.str().c_str();
    }
}

// Work around GCC 8.x bug with `<filesystem>`.
#if !defined(__GNUC__) || (__GNUC__ >= 9)
namespace sf::Testing
{
    class TemporaryFile
    {
    private:
        std::string m_path;

    public:
        // Create a temporary file with a randomly generated path, containing 'contents'.
        TemporaryFile(const std::string& contents);

        // Close and delete the generated file.
        ~TemporaryFile();

        // Prevent copies.
        TemporaryFile(const TemporaryFile&) = delete;
        TemporaryFile& operator=(const TemporaryFile&) = delete;

        // Return the randomly generated path.
        const std::string& getPath() const;
    };
}
#endif // !defined(__GNUC__) || (__GNUC__ >= 9)

#endif // SFML_TESTUTILITIES_SYSTEM_HPP