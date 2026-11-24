// bin: xb
// va: 0x000930C0
// what: Returns the 16-bit entry at the given byte index from the array at +0x4C.
// tool: Gemini 4 Neon

class Class_000930C0
{
public:
    unsigned short sub_000930C0(unsigned char index);
    char m_pad00[0x4C];
    unsigned short m_Field4C[256]; // +0x4C
};

unsigned short Class_000930C0::sub_000930C0(unsigned char index)
{
    return m_Field4C[index];
}
