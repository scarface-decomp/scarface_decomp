// bin: xb
// va: 0x0015D790
// what: Returns a copy of a three-number vector kept in an object.
// tool: Claude Opus 5.5 (symcov hint: Photon::CEnvironment::GetPanoShadowColor)
// sub_0015D790 (0x0015D790, 33 bytes)

struct Struct_0015D790
{
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

class Class_0015D790
{
public:
    Struct_0015D790 sub_0015D790() const;

    char m_pad00[0xB4];
    Struct_0015D790 m_FieldB4; // +0xB4
};

// Returns the stored vector by value.
Struct_0015D790 Class_0015D790::sub_0015D790() const
{
    return m_FieldB4;
}
