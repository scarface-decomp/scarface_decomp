// bin: proto
// va: 0x000B7A20
// tool: the portal's starter code (no AI)
// sub_000B7A20 (0x000B7A20, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_001B7A10();
};

extern "C" int __cdecl sub_00015510(int);

class Class_000B7A20
{
public:
    int sub_000B7A20();
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    Field10 m_Field10; // +0x10
    char m_pad11[0x17];
    bool m_Field28; // +0x28
};

int Class_000B7A20::sub_000B7A20()
{
    int r_eax;

    r_eax = m_Field28;
    if (!((unsigned char)r_eax)) goto L_2A;
    r_eax = m_Field0C;
    if (r_eax) {
        if (!*(unsigned char*)r_eax) goto L_1F;
        sub_00015510(r_eax);
    }
L_1F:
    m_Field0C = 0;
    m_Field28 = false;
L_2A:
    m_Field10.sub_001B7A10();
    r_eax = m_Field0C;
    if (r_eax) {
        if (*(unsigned char*)r_eax) {
            r_eax = sub_00015510(r_eax);
        }
        m_Field0C = 0;
    }
    return r_eax;
}
