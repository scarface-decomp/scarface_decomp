// bin: xb
// va: 0x000A5670
// what: Sets four numbers of an object to zero.
// tool: Claude Opus 5.5 (symcov hint: EARS::Modules::Sentient::HeadTrackAngleInfo::Init)
// sub_000A5670 (0x000A5670, 23 bytes)

class Class_000A5670
{
public:
    void sub_000A5670();

    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
};

// Clears all four values.
void Class_000A5670::sub_000A5670()
{
    m_Field00 = 0.0f;
    m_Field04 = 0.0f;
    m_Field08 = 0.0f;
    m_Field0C = 0.0f;
}
