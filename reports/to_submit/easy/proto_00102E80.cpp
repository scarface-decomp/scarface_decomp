// bin: proto
// va: 0x00102E80
// tool: the portal's starter code (no AI)
// sub_00102E80 (0x00102E80, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045A0EC;

class Class_00102E80
{
public:
    int sub_00102E80(int a1);
    char m_pad00[0x8];
    int m_Field08; // +0x08
    bool m_Field0C; // +0x0C
};

int Class_00102E80::sub_00102E80(int a1)
{
    if (m_Field0C) {
        if ((*(int*)(DAT_0045A0EC + 44) - m_Field08) > a1) goto L_20;
        return 1;
    }
L_20:
    return 0;
}
