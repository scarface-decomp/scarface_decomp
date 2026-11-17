// bin: xb
// va: 0x00124190
// tool: the portal's starter code (no AI)
// sub_00124190 (0x00124190, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004879E8;

class Class_00124190
{
public:
    int sub_00124190();
    char m_pad00[0x20];
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    bool m_Field28; // +0x28
    char m_pad29[0x3];
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
};

int Class_00124190::sub_00124190()
{
    if ((unsigned int)((m_Field30 - m_Field2C) >> 2) < (unsigned int)m_Field20) {
        if (m_Field28) {
            if ((unsigned int)*(int*)(DAT_004879E8 + 40) >= (unsigned int)m_Field24) goto L_2D;
        }
        return 1;
    }
L_2D:
    return 0;
}
