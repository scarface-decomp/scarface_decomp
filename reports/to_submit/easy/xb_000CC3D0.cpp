// bin: xb
// va: 0x000CC3D0
// tool: the portal's starter code (no AI)
// sub_000CC3D0 (0x000CC3D0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000CC3D0
{
public:
    int sub_000CC3D0();
    char m_pad00[0x14C];
    bool m_Field14C; // +0x14C
    bool m_Field14D; // +0x14D
};

int Class_000CC3D0::sub_000CC3D0()
{
    if (!m_Field14C) {
        if (m_Field14D) goto L_17;
        return 0;
    }
L_17:
    return 1;
}
