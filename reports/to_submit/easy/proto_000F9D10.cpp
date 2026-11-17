// bin: proto
// va: 0x000F9D10
// tool: the portal's starter code (no AI)
// sub_000F9D10 (0x000F9D10, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000F9D10
{
public:
    void sub_000F9D10(int a1, int a2);
    char m_pad00[0x14];
    int m_Field14; // +0x14
    char m_pad18[0xC];
    bool m_Field24; // +0x24
};

void Class_000F9D10::sub_000F9D10(int a1, int a2)
{
    int t1;

    t1 = m_Field14 + ((((((unsigned int)*(int*)(a1 + 120)) >> 4) & 127) + (((((unsigned int)*(int*)(a1 + 120)) >> 4) & 127) * 2)) * 4);
    if (*(int*)(m_Field14 + ((((((unsigned int)*(int*)(a1 + 120)) >> 4) & 127) + (((((unsigned int)*(int*)(a1 + 120)) >> 4) & 127) * 2)) * 4) + 4) == *(int*)(a2 + 16)) {
        if (!*(int*)(t1 + 4)) goto L_36;
        *(int*)(t1 + 4) = 0;
        *(bool*)(t1 + 8) = false;
        m_Field24 = true;
    }
L_36:
    ;
}
