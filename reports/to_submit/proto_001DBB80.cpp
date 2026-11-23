// bin: proto
// va: 0x001DBB80
// what: 
// tool: the portal's starter code (no AI)

// sub_001DBB80 (Proto 0x001DBB80, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0009F630(int);
};

class Class_001DBB80
{
public:
    int sub_001DBB80(int a1);
    char m_pad00[0xA4];
    int m_FieldA4; // +0xA4
    char m_padA8[0x14];
    int m_FieldBC; // +0xBC
};

int Class_001DBB80::sub_001DBB80(int a1)
{
    int r_eax;

    r_eax = m_FieldA4;
    if (r_eax) {
        r_eax = m_FieldBC;
        if (!r_eax) goto L_20;
        if (!(r_eax + 72)) goto L_20;
        return ((Object*)r_eax + 72)->sub_0009F630(a1);
    }
L_20:
    return r_eax;
}
