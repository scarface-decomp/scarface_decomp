// bin: xb
// va: 0x0021D9C0
// what: 
// tool: the portal's starter code (no AI)

// sub_0021D9C0 (0x0021D9C0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_0021D9C0
{
public:
    int sub_0021D9C0();
    char m_pad00[0x24];
    int m_Field24; // +0x24
    int m_Field28; // +0x28
};

int Class_0021D9C0::sub_0021D9C0()
{
    int r_eax, r_edx, t1;

    r_eax = m_Field24;
    if ((unsigned int)r_eax < (unsigned int)m_Field28) {
        r_edx = -33;
        do {
            *(int*)(r_eax + 8) &= r_edx;
            t1 = m_Field28;
            r_eax += 12;
        } while ((unsigned int)r_eax < (unsigned int)t1);
    }
    return r_eax;
}
