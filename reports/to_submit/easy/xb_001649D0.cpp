// bin: xb
// va: 0x001649D0
// tool: the portal's starter code (no AI)
// sub_001649D0 (0x001649D0, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;

class Class_001649D0
{
public:
    float sub_001649D0();
    char m_pad00[0xB4];
    int m_FieldB4; // +0xB4
};

float Class_001649D0::sub_001649D0()
{
    int r_eax;

    r_eax = m_FieldB4;
    if (r_eax) {
        return *(float*)(r_eax + 148);
    }
    return DAT_0039D664;
}
