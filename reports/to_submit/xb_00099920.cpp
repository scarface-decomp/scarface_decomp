// bin: xb
// va: 0x00099920
// what: Clamps a signed 16-bit argument to at least 0 and stores it at +0x0C.
// tool: Gemini 4 Neon

class Class_00099920
{
public:
    void sub_00099920(int value);
    char m_pad00[0xC];
    short m_Field0C; // +0x0C
};

void Class_00099920::sub_00099920(int value)
{
    m_Field0C = ((short)value > 0) ? (short)value : (short)0;
}
