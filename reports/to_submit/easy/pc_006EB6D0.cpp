// bin: pc
// va: 0x006EB6D0
// tool: the portal's starter code (no AI)
// sub_006EB6D0 (0x006EB6D0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0072FC64[];
extern "C" int DAT_007F6398;

class Class_006EB6D0
{
public:
    int sub_006EB6D0();
    int m_Field00; // +0x00
};

int Class_006EB6D0::sub_006EB6D0()
{
    int r_eax;

    r_eax = m_Field00;
    if (r_eax == DAT_007F6398) {
        r_eax = (int)DAT_0072FC64;
    }
    return r_eax;
}
