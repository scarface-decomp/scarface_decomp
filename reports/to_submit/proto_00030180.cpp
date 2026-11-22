// bin: proto
// va: 0x00030180
// what: 
// tool: the portal's starter code (no AI)

// Path::vfunc_01 (Proto 0x00030180, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Path
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x8];
    short m_Field0C; // +0x0C
    char m_pad0E[0xA];
    int m_Field18; // +0x18
};

int Path::vfunc_01()
{
    int r_eax;

    r_eax = m_Field18;
    if (r_eax) {
        if (r_eax == 3) goto L_17;
        r_eax = 1;
        if (m_Field0C >= 1) goto L_19;
    }
L_17:
    r_eax = 0;
L_19:
    return r_eax;
}
