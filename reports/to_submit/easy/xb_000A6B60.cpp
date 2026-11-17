// bin: xb
// va: 0x000A6B60
// tool: the portal's starter code (no AI)
// sub_000A6B60 (0x000A6B60, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0004B410(int, int);

class Class_000A6B60
{
public:
    int sub_000A6B60();
    char m_pad00[0x80];
    int m_Field80; // +0x80
    int m_Field84; // +0x84
};

int Class_000A6B60::sub_000A6B60()
{
    int r_eax, t1, t2;

    r_eax = 0;
    t1 = m_Field80;
    if (m_Field80) {
        if (!*(unsigned char*)t1) goto L_25;
        t2 = m_Field84;
        if (!m_Field84) goto L_25;
        r_eax = sub_0004B410(t1, t2);
    }
L_25:
    return r_eax;
}
