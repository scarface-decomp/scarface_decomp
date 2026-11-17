// bin: xb
// va: 0x000C40B0
// tool: the portal's starter code (no AI)
// sub_000C40B0 (0x000C40B0, 87 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field48
{
    void sub_000C3D50(int, int);
};

struct Field5C
{
    void sub_000C3E70(int, int);
};

extern "C" int __cdecl sub_0002AC90(int);

class Class_000C40B0
{
public:
    void sub_000C40B0();
    char m_pad00[0x4];
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    char m_pad0C[0x3C];
    Field48 m_Field48; // +0x48
    char m_pad49[0x13];
    Field5C m_Field5C; // +0x5C
    char m_pad5D[0x17];
    Field5C m_Field74; // +0x74
};

void Class_000C40B0::sub_000C40B0()
{
    if (m_Field08) {
        m_Field48.sub_000C3D50(m_Field08, sub_0002AC90(m_Field04));
        m_Field5C.sub_000C3E70(m_Field08, sub_0002AC90(m_Field04));
        m_Field74.sub_000C3E70(m_Field08, sub_0002AC90(m_Field04));
    }
}
