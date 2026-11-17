// bin: xb
// va: 0x00132FA0
// tool: the portal's starter code (no AI)
// sub_00132FA0 (0x00132FA0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003A48F0;
extern "C" int DAT_004879E8;

class Class_00132FA0
{
public:
    float sub_00132FA0();
    char m_pad00[0x5B4];
    int m_Field5B4; // +0x5B4
};

float Class_00132FA0::sub_00132FA0()
{
    int local_4, t1;

    t1 = DAT_004879E8;
    local_4 = *(int*)(DAT_004879E8 + 44) - m_Field5B4;
    return ((float)local_4) * DAT_003A48F0;
}
