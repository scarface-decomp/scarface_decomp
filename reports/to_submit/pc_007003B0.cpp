// bin: pc
// va: 0x007003B0
// what: 
// tool: the portal's starter code (no AI)

// sub_007003B0 (PC 0x007003B0, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_007003B0
{
public:
    int sub_007003B0();
    char m_pad00[0x20];
    int m_Field20; // +0x20
    char m_pad24[0x4];
    int m_Field28; // +0x28
};

int Class_007003B0::sub_007003B0()
{
    int r_eax, r_edi;

    r_edi = 0;
L_06:
    r_eax = m_Field28;
    if (r_eax) {
        if (!(r_eax + -4)) goto L_27;
        if (m_Field20 == 30) goto L_27;
        r_eax = *(int*)(r_eax + -4);
        r_eax = ((int (__stdcall*)(int))*(int*)r_eax)((int)this);
        r_edi += 1;
        if ((unsigned int)r_edi < (unsigned int)5) goto L_06;
    }
L_27:
    return r_eax;
}
