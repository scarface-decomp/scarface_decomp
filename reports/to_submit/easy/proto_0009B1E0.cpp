// bin: proto
// va: 0x0009B1E0
// tool: the portal's starter code (no AI)
// sub_0009B1E0 (0x0009B1E0, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE60;

class Class_0009B1E0
{
public:
    Class_0009B1E0* sub_0009B1E0();
    char m_pad00[0x8];
    int m_Field08; // +0x08
};

Class_0009B1E0* Class_0009B1E0::sub_0009B1E0()
{
    int r_edx, r_esi;
    float t1;

    t1 = DAT_0037CE60;
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
