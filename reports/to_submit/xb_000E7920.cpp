// bin: xb
// va: 0x000E7920
// what: Returns a copy of a three-number vector kept in an object.
// tool: Claude Opus 5.5 (symcov hint: CSA_Physical::GetEndPos)
// sub_000E7920 (0x000E7920, 30 bytes)

struct Struct_000E7920
{
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

class Class_000E7920
{
public:
    Struct_000E7920 sub_000E7920() const;

    char m_pad00[0x24];
    Struct_000E7920 m_Field24; // +0x24
};

// Returns the stored vector by value.
Struct_000E7920 Class_000E7920::sub_000E7920() const
{
    return m_Field24;
}
