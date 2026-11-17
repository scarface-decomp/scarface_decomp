// bin: proto
// va: 0x0009CD80
// tool: the portal's starter code (no AI)
// sub_0009CD80 (0x0009CD80, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0009B480(int, int);
};

class Class_0009CD80
{
public:
    int sub_0009CD80(int a1, int a2);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

int Class_0009CD80::sub_0009CD80(int a1, int a2)
{
    int r_eax;

    m_Field00 = -1;
    m_Field04 = -1;
    r_eax = *(int*)a1;
    if (r_eax) {
        if (!*(unsigned char*)r_eax) goto L_31;
        r_eax = ((Object*)a2)->sub_0009B480(r_eax, 0);
        m_Field00 = r_eax;
    }
L_31:
    r_eax = *(int*)(a1 + 4);
    if (r_eax) {
        if (!*(unsigned char*)r_eax) goto L_4A;
        r_eax = ((Object*)a2)->sub_0009B480(r_eax, 0);
        m_Field04 = r_eax;
    }
L_4A:
    return r_eax;
}
