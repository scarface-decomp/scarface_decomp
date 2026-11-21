// parked: 55/55 bytes (python portal/verify.py work/xb_00013AA0.cpp --va 0x00013AA0 --bin xb --match sub_00013AA0 prints VERIFIED); tried member assignments to a named local (builds it on the stack, 0/55 layout); stuck at agent.py check: the inline 3-float constructor that the return-by-temporary needs is also emitted as a COMDAT (??0Class_00013AA0@@QAE@MMM@Z) and check, with no match_substr in this checkout (no reports/full_remaining_queue.json), refuses an .obj with two functions.
// bin: xb
// va: 0x00013AA0
// what: Returns a three-number vector with each component multiplied by a number.
// tool: Claude Opus 5.5 (symcov hint: Abacus::operator*)
// sub_00013AA0 (0x00013AA0, 55 bytes)

class Class_00013AA0
{
public:
    Class_00013AA0()
    {
    }

    Class_00013AA0(float field00, float field04, float field08)
        : m_Field00(field00), m_Field04(field04), m_Field08(field08)
    {
    }

    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

// Scales every component of the vector by the same factor.
Class_00013AA0 __cdecl sub_00013AA0(const Class_00013AA0 &vector, float scale)
{
    return Class_00013AA0(vector.m_Field00 * scale, vector.m_Field04 * scale, vector.m_Field08 * scale);
}
