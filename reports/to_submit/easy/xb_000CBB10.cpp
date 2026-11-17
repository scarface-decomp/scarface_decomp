// bin: xb
// va: 0x000CBB10
// tool: the portal's starter code (no AI)
// sub_000CBB10 (0x000CBB10, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000CD940();
};

class Class_000CBB10
{
public:
    unsigned short sub_000CBB10();
    char m_pad00[0xAC];
    int m_FieldAC; // +0xAC
};

unsigned short Class_000CBB10::sub_000CBB10()
{
    int r_eax, t1;

    r_eax = 0;
    t1 = m_FieldAC;
    if (m_FieldAC) {
        return ((Object*)t1)->sub_000CD940();
    }
    r_eax |= 65535;
    return r_eax;
}
