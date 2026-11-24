// bin: xb
// va: 0x00163550
// what: Returns 1 if the 32-bit field at +0x17C equals the argument, otherwise 0.
// tool: Gemini 4 Neon

class Class_00163550
{
public:
    unsigned char sub_00163550(int value);
    char m_pad00[0x17C];
    int m_Field17C; // +0x17C
};

unsigned char Class_00163550::sub_00163550(int value)
{
    return m_Field17C == value;
}
