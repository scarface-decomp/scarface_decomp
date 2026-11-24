// bin: xb
// va: 0x00093330
// what: Returns the 32-bit element at the given byte index from the inline array at +0x0C.
// tool: Gemini 4 Neon

class Class_00093330
{
public:
    int sub_00093330(unsigned char index);
    char m_pad00[0xC];
    int m_Field0C[256]; // +0x0C
};

int Class_00093330::sub_00093330(unsigned char index)
{
    return m_Field0C[index];
}
