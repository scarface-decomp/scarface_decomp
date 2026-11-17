// bin: xb
// va: 0x000A70B0
// tool: the portal's starter code (no AI)
// sub_000A70B0 (0x000A70B0, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;

class Class_000A70B0
{
public:
    Class_000A70B0* sub_000A70B0();
    char m_pad00[0x8];
    int m_Field08; // +0x08
};

Class_000A70B0* Class_000A70B0::sub_000A70B0()
{
    int r_edx, r_esi;
    float t1;

    t1 = DAT_0039D65C;
    r_edx = (int)(&m_Field08);
    r_esi = 30;
    do {
        *(int*)(r_edx + -8) = 0;
        *(int*)(r_edx + -4) = 0;
        *(float*)r_edx = t1;
        r_edx += 12;
        r_esi -= 1;
    } while (r_esi);
    return this;
}
