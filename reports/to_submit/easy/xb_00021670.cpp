// bin: xb
// va: 0x00021670
// tool: the portal's starter code (no AI)
// sub_00021670 (0x00021670, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
{
    void sub_00087DC0(int);
};

struct Field5C
{
    int sub_00087430(int);
};

class Class_00021670
{
public:
    int sub_00021670(int a1, int a2);
    char m_pad00[0x30];
    Field30 m_Field30; // +0x30
    char m_pad31[0xB];
    int m_Field3C; // +0x3C
    char m_pad40[0x1C];
    Field5C m_Field5C; // +0x5C
    char m_pad5D[0x3];
    int m_Field60; // +0x60
};

int Class_00021670::sub_00021670(int a1, int a2)
{
    int r_eax;

    r_eax = m_Field3C;
    if (r_eax) {
        if (!*(unsigned char*)r_eax) goto L_1D;
        m_Field30.sub_00087DC0(a1);
    }
L_1D:
    r_eax = m_Field60;
    if (r_eax) {
        if (!*(unsigned char*)r_eax) goto L_32;
        r_eax = m_Field5C.sub_00087430(a1);
    }
L_32:
    return r_eax;
}
