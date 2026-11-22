// bin: proto
// va: 0x0001F480
// what: 
// tool: the portal's starter code (no AI)

// sub_0001F480 (Proto 0x0001F480, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
{
    void sub_0007D850(int);
};

struct Field60
{
    int sub_0007CF10(int);
};

class Class_0001F480
{
public:
    int sub_0001F480(int a1, int a2);
    char m_pad00[0x30];
    Field30 m_Field30; // +0x30
    char m_pad31[0xF];
    int m_Field40; // +0x40
    char m_pad44[0x1C];
    Field60 m_Field60; // +0x60
    char m_pad61[0x3];
    int m_Field64; // +0x64
};

int Class_0001F480::sub_0001F480(int a1, int a2)
{
    int r_eax;

    r_eax = m_Field40;
    if (r_eax) {
        if (!*(unsigned char*)r_eax) goto L_1D;
        m_Field30.sub_0007D850(a1);
    }
L_1D:
    r_eax = m_Field64;
    if (r_eax) {
        if (!*(unsigned char*)r_eax) goto L_32;
        r_eax = m_Field60.sub_0007CF10(a1);
    }
L_32:
    return r_eax;
}
