// bin: xb
// va: 0x00162630
// what: Returns 1 if the signed byte field at +0xB8 is at least 2, otherwise 0.
// tool: Gemini 4 Neon

class Class_00162630
{
public:
    unsigned char sub_00162630();
    char m_pad00[0xB8];
    signed char m_FieldB8; // +0xB8
};

#pragma optimize("s", on)
unsigned char Class_00162630::sub_00162630()
{
    return m_FieldB8 >= 2;
}
#pragma optimize("", on)
