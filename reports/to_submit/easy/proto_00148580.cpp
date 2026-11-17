// bin: proto
// va: 0x00148580
// tool: the portal's starter code (no AI)
// sub_00148580 (0x00148580, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;

class Class_00148580
{
public:
    float sub_00148580();
    char m_pad00[0xA8];
    int m_FieldA8; // +0xA8
};

float Class_00148580::sub_00148580()
{
    int r_eax;

    r_eax = m_FieldA8;
    if (r_eax) {
        return *(float*)(r_eax + 136);
    }
    return DAT_0037CE50;
}
