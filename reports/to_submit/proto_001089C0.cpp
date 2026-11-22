// bin: proto
// va: 0x001089C0
// what: 
// tool: the portal's starter code (no AI)

// sub_001089C0 (Proto 0x001089C0, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045A0EC;

class Class_001089C0
{
public:
    int sub_001089C0();
    char m_pad00[0x20];
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    bool m_Field28; // +0x28
    char m_pad29[0x3];
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
};

int Class_001089C0::sub_001089C0()
{
    if ((unsigned int)((m_Field30 - m_Field2C) >> 2) < (unsigned int)m_Field20) {
        if (m_Field28) {
            if ((unsigned int)*(int*)(DAT_0045A0EC + 40) >= (unsigned int)m_Field24) goto L_2D;
        }
        return 1;
    }
L_2D:
    return 0;
}
