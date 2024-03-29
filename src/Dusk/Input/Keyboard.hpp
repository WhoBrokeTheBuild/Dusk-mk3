#ifndef DUSK_INPUT_KEYS_HPP
#define DUSK_INPUT_KEYS_HPP

#include <Dusk/Config.hpp>
#include <Dusk/Collections/Map.hpp>
#include <Dusk/Events/Event.hpp>

#include <SFML/Window/Keyboard.hpp>
#include <SFML/System.hpp>

namespace dusk
{

class Keyboard
{
public:
    enum Key
    {
        Invalid = -1,

        A = 1,
        B = 2,
        C = 3,
        D = 4,
        E = 5,
        F = 6,
        G = 7,
        H = 8,
        I = 9,
        J = 10,
        K = 11,
        L = 12,
        M = 13,
        N = 14,
        O = 15,
        P = 16,
        Q = 17,
        R = 18,
        S = 19,
        T = 20,
        U = 21,
        V = 22,
        W = 23,
        X = 24,
        Y = 25,
        Z = 26,

        N0 = 50,
        N1 = 51,
        N2 = 52,
        N3 = 53,
        N4 = 54,
        N5 = 55,
        N6 = 56,
        N7 = 57,
        N8 = 58,
        N9 = 59,

        Dash = 100,
        Equal = 101,
        Tilde = 102,
        LeftBracket = 103,
        RightBracket = 104,
        Semicolon = 105,
        Quote = 106,
        Backslash = 107,
        Period = 108,
        Comma = 109,
        Slash = 110,
        Up = 111,
        Down = 112,
        Left = 113,
        Right = 114,
        Backspace = 118,
        Tab = 119,
        Enter = 120,
        Return = Enter,
        Space = 121,
        Pause = 122,
        PrintScreen = 123,

        LeftShift = 124,
        RightShift = 125,
        LeftControl = 126,
        RightControl = 127,
        LeftAlt = 128,
        RightAlt = 129,
        LeftSuper = 138,
        LeftSystem = LeftSuper,
        RightSuper = 139,
        RightSystem = RightSuper,

        Insert = 130,
        Delete = 131,
        Home = 132,
        End = 133,
        PageUp = 134,
        PageDown = 135,
        Escape = 136,
        Menu = 137,

        Pad0 = 200,
        Pad1 = 201,
        Pad2 = 202,
        Pad3 = 203,
        Pad4 = 204,
        Pad5 = 205,
        Pad6 = 206,
        Pad7 = 207,
        Pad8 = 208,
        Pad9 = 209,

        Add = 210,
        Subtract = 211,
        Multiply = 212,
        Divide = 213,

        F1 = 216,
        F2 = 217,
        F3 = 218,
        F4 = 219,
        F5 = 220,
        F6 = 221,
        F7 = 222,
        F8 = 223,
        F9 = 224,
        F10 = 225,
        F11 = 226,
        F12 = 227,
        F13 = 228,
        F14 = 229,
        F15 = 230,

    }; // enum Keys

    static Keyboard::Key ConvertSFMLKey(sf::Keyboard::Key key);

}; // class Keyboard

class KeyEventData : public EventData
{
public:
    DUSK_CLASSNAME("Key Event Data")

    KeyEventData() = default;
    KeyEventData(const KeyEventData&) = default;
    KeyEventData& operator=(const KeyEventData&) = default;
    ~KeyEventData() = default;

    KeyEventData(const Keyboard::Key& key)
        : m_Key(key)
    {
    }

    virtual inline EventData* Clone() const override { return New KeyEventData(m_Key); }

    inline Keyboard::Key GetKey() const { return m_Key; }

    virtual int PushDataToLua(lua_State* L) const override;

private:
    Keyboard::Key m_Key = Keyboard::Key::Invalid;

}; // class KeyEventData

class TextInputEventData : public EventData
{
public:
    DUSK_CLASSNAME("Text Event Data")

    TextInputEventData() = default;

    TextInputEventData(const char32_t& input)
        : m_Input(input)
    {
    }

    virtual inline EventData* Clone() const override { return New TextInputEventData(m_Input); }

    inline char32_t GetInput() const { return m_Input; }

    virtual int PushDataToLua(lua_State* L) const override;

private:
    char32_t m_Input = 0;

}; // class TextInputEventData

} // namespace dusk

#endif // DUSK_INPUT_KEYS_HPP
