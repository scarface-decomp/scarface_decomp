// bin: proto
// va: 0x001179D0
// tool: the portal's starter code (no AI)
// sub_001179D0 (0x001179D0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037D4CC;
extern "C" int DAT_0045A0EC;

class Class_001179D0
{
public:
    float sub_001179D0();
    char m_pad00[0x5B4];
    int m_Field5B4; // +0x5B4
};

float Class_001179D0::sub_001179D0()
{
    int local_4, t1;

    t1 = DAT_0045A0EC;
    local_4 = *(int*)(DAT_0045A0EC + 44) - m_Field5B4;
    return ((float)local_4) * DAT_0037D4CC;
}
