// bin: proto
// va: 0x00147E10
// tool: the portal's starter code (no AI)
// sub_00147E10 (0x00147E10, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CD94;
extern "C" float DAT_0037D4CC;
extern "C" int DAT_0045A0EC;

class Class_00147E10
{
public:
    float sub_00147E10();
    char m_pad00[0xA0];
    int m_FieldA0; // +0xA0
    char m_padA4[0x2F0];
    int m_Field394; // +0x394
};

float Class_00147E10::sub_00147E10()
{
    int local_4, r_eax;

    r_eax = 0;
    if (m_FieldA0 >= 4) {
        r_eax = DAT_0045A0EC;
        local_4 = *(int*)(r_eax + 44) - m_Field394;
        return ((float)local_4) * DAT_0037D4CC;
    }
    return DAT_0037CD94;
}
