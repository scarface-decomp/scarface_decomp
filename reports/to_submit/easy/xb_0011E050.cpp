// bin: xb
// va: 0x0011E050
// tool: the portal's starter code (no AI)
// sub_0011E050 (0x0011E050, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004879E8;

class Class_0011E050
{
public:
    int sub_0011E050(int a1);
    char m_pad00[0x8];
    int m_Field08; // +0x08
    bool m_Field0C; // +0x0C
};

int Class_0011E050::sub_0011E050(int a1)
{
    if (m_Field0C) {
        if ((*(int*)(DAT_004879E8 + 44) - m_Field08) > a1) goto L_20;
        return 1;
    }
L_20:
    return 0;
}
