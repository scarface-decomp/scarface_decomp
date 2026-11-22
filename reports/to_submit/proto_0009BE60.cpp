// bin: proto
// va: 0x0009BE60
// what: 
// tool: the portal's starter code (no AI)

// sub_0009BE60 (Proto 0x0009BE60, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0009B410(int, int);
};

class Class_0009BE60
{
public:
    int sub_0009BE60(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

int Class_0009BE60::sub_0009BE60(int a1)
{
    int r_eax;

    r_eax = m_Field04;
    if (r_eax) {
        if (!*(unsigned char*)r_eax) goto L_21;
        r_eax = ((Object*)a1)->sub_0009B410(r_eax, 1);
        m_Field00 = r_eax;
        return r_eax;
    }
L_21:
    m_Field00 = -1;
    return r_eax;
}
