// bin: xb
// va: 0x00093320
// what: Returns the 32-bit element at the given byte index from the array pointed to by +0x04.
// tool: Gemini 4 Neon

class Class_00093320
{
public:
    int sub_00093320(unsigned char index);
    char m_pad00[0x4];
    int* m_Field04; // +0x04
};

int Class_00093320::sub_00093320(unsigned char index)
{
    return m_Field04[index];
}
