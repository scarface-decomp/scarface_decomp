// bin: xb
// va: 0x00146B50
// tool: the portal's starter code (no AI)
// sub_00146B50 (0x00146B50, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

class Class_00146B50
{
public:
    void sub_00146B50(int a1);
    char m_pad00[0x28];
    int m_Field28; // +0x28
    char m_pad2C[0x34];
    int m_Field60; // +0x60
    char m_pad64[0x18];
    bool m_Field7C; // +0x7C
};

void Class_00146B50::sub_00146B50(int a1)
{
    int r_edi, t4;

    r_edi = sub_0002AC90(m_Field28);
    if (m_Field7C) {
        if (!(*(unsigned char*)(r_edi + 369) & 32)) goto L_4C;
        m_Field7C = false;
        return;
    }
    if (sub_0002AC90(*(int*)(r_edi + 204))) {
        t4 = *(int*)(r_edi + 192);
        if (m_Field60 == *(int*)(r_edi + 192)) goto L_4C;
        m_Field60 = t4;
    }
L_4C:
    ;
}
