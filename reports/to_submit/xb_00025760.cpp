// bin: xb
// va: 0x00025760
// what: Returns true if the 32-bit state field at +0x218 equals 6.
// tool: Gemini 4 Neon

class Class_00025760
{
public:
    unsigned char sub_00025760();
    char m_pad00[0x218];
    int m_Field218; // +0x218
};

#pragma optimize("s", on)
unsigned char Class_00025760::sub_00025760()
{
    return m_Field218 == 6;
}
#pragma optimize("", on)
