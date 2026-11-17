// bin: xb
// va: 0x00164170
// tool: the portal's starter code (no AI)
// sub_00164170 (0x00164170, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D584;
extern "C" float DAT_003A48F0;
extern "C" int DAT_004879E8;

class Class_00164170
{
public:
    float sub_00164170();
    char m_pad00[0xAC];
    int m_FieldAC; // +0xAC
    char m_padB0[0x310];
    int m_Field3C0; // +0x3C0
};

float Class_00164170::sub_00164170()
{
    int local_4, r_eax;

    r_eax = 0;
    if (m_FieldAC >= 4) {
        r_eax = DAT_004879E8;
        local_4 = *(int*)(r_eax + 44) - m_Field3C0;
        return ((float)local_4) * DAT_003A48F0;
    }
    return DAT_0039D584;
}
