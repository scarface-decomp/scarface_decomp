// bin: xb
// va: 0x00217690
// what: 
// tool: the portal's starter code (no AI)

// sub_00217690 (0x00217690, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000AB880(int);
};

class Class_00217690
{
public:
    int sub_00217690(int a1);
    char m_pad00[0xAC];
    int m_FieldAC; // +0xAC
    char m_padB0[0x14];
    int m_FieldC4; // +0xC4
};

int Class_00217690::sub_00217690(int a1)
{
    int r_eax;

    r_eax = m_FieldAC;
    if (r_eax) {
        r_eax = m_FieldC4;
        if (!r_eax) goto L_20;
        if (!(r_eax + 72)) goto L_20;
        return ((Object*)r_eax + 72)->sub_000AB880(a1);
    }
L_20:
    return r_eax;
}
