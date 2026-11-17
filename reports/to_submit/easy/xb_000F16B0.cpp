// bin: xb
// va: 0x000F16B0
// tool: the portal's starter code (no AI)
// sub_000F16B0 (0x000F16B0, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field39C
{
    int sub_000CE360();
    bool sub_00103C00();
};

class Class_000F16B0
{
public:
    int sub_000F16B0(int a1);
    char m_pad00[0x39C];
    Field39C m_Field39C; // +0x39C
    char m_pad39D[0x1D2];
    bool m_Field56F; // +0x56F
};

int Class_000F16B0::sub_000F16B0(int a1)
{
    if (!m_Field39C.sub_00103C00()) {
        if (m_Field56F) goto L_36;
        if (m_Field39C.sub_000CE360() != a1) goto L_36;
        return 1;
    }
L_36:
    return 0;
}
