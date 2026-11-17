// bin: proto
// va: 0x0009AC90
// tool: the portal's starter code (no AI)
// sub_0009AC90 (0x0009AC90, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00043E30(int, int);

class Class_0009AC90
{
public:
    int sub_0009AC90();
    char m_pad00[0x80];
    int m_Field80; // +0x80
    int m_Field84; // +0x84
};

int Class_0009AC90::sub_0009AC90()
{
    int r_eax, t1, t2;

    r_eax = 0;
    t1 = m_Field80;
    if (m_Field80) {
        if (!*(unsigned char*)t1) goto L_25;
        t2 = m_Field84;
        if (!m_Field84) goto L_25;
        r_eax = sub_00043E30(t1, t2);
    }
L_25:
    return r_eax;
}
