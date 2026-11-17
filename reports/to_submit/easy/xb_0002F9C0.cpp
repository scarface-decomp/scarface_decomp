// bin: xb
// va: 0x0002F9C0
// tool: the portal's starter code (no AI)
// sub_0002F9C0 (0x0002F9C0, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_0002F9C0
{
public:
    int sub_0002F9C0(int a1);
    unsigned short m_Field00; // +0x00
    char m_pad02[0x2];
    int m_Field04; // +0x04
};

int Class_0002F9C0::sub_0002F9C0(int a1)
{
    if (m_Field04 == *(int*)(a1 + 4)) {
        if (m_Field00 != *(unsigned short*)a1) goto L_1C;
        return 1;
    }
L_1C:
    return 0;
}
