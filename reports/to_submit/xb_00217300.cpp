// bin: xb
// va: 0x00217300
// what: Calls sub_000AB360 on the embedded member at +0x48 when the flag at +0x44 is set, or returns the default float at DAT_003D005C.
// tool: Gemini 4 Neon

extern "C" const float DAT_003D005C;

struct Member_00217300
{
    float sub_000AB360();
};

class Class_00217300
{
public:
    float sub_00217300();
    char m_pad00[0x44];
    bool m_Field44; // +0x44
    char m_pad45[3];
    Member_00217300 m_Field48; // +0x48
};

float Class_00217300::sub_00217300()
{
    if (m_Field44)
        return m_Field48.sub_000AB360();
    return DAT_003D005C;
}
