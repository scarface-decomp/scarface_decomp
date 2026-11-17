// bin: xb
// va: 0x000C5590
// tool: the portal's starter code (no AI)
// sub_000C5590 (0x000C5590, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_002A9290();
};

extern "C" int __cdecl sub_00014BE0(int);

class Class_000C5590
{
public:
    int sub_000C5590();
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    Field10 m_Field10; // +0x10
    char m_pad11[0x17];
    bool m_Field28; // +0x28
};

int Class_000C5590::sub_000C5590()
{
    int r_eax;

    r_eax = m_Field28;
    if (!((unsigned char)r_eax)) goto L_2A;
    r_eax = m_Field0C;
    if (r_eax) {
        if (!*(unsigned char*)r_eax) goto L_1F;
        sub_00014BE0(r_eax);
    }
L_1F:
    m_Field0C = 0;
    m_Field28 = false;
L_2A:
    m_Field10.sub_002A9290();
    r_eax = m_Field0C;
    if (r_eax) {
        if (*(unsigned char*)r_eax) {
            r_eax = sub_00014BE0(r_eax);
        }
        m_Field0C = 0;
    }
    return r_eax;
}
