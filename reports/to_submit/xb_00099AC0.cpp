// bin: xb
// va: 0x00099AC0
// what: Passes its argument and the 16-bit field at +0x08 to sub_00099A20.
// tool: Gemini 4 Neon

class Class_00099AC0
{
public:
    void sub_00099AC0(int a1);
    void sub_00099A20(int a1, unsigned short a2);
    char m_pad00[0x8];
    unsigned short m_Field08; // +0x08
};

void Class_00099AC0::sub_00099AC0(int a1)
{
    sub_00099A20(a1, m_Field08);
}
