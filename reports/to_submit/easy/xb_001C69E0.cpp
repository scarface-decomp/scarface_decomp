// bin: xb
// va: 0x001C69E0
// tool: the portal's starter code (no AI)
// sub_001C69E0 (0x001C69E0, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001C69E0
{
public:
    int sub_001C69E0(int a1);
    int m_Field00; // +0x00
    char m_pad04[0x4C];
    bool m_Field50; // +0x50
};

int Class_001C69E0::sub_001C69E0(int a1)
{
    if (m_Field50) {
        if (m_Field00 != a1) goto L_17;
        return 1;
    }
L_17:
    return 0;
}
