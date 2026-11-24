// bin: proto
// va: 0x001E1630
// what: 
// tool: the portal's starter code (no AI)

// sub_001E1630 (Proto 0x001E1630, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001E1630
{
public:
    int sub_001E1630();
    char m_pad00[0x24];
    int m_Field24; // +0x24
    int m_Field28; // +0x28
};

int Class_001E1630::sub_001E1630()
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
