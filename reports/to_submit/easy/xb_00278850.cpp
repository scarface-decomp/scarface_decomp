// bin: xb
// va: 0x00278850
// tool: the portal's starter code (no AI)
// sub_00278850 (0x00278850, 79 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" int __cdecl sub_00027590(int);

class Class_00278850
{
public:
    bool sub_00278850(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

bool Class_00278850::sub_00278850(int a1)
{
    int t1;

    if (a1) {
        t1 = sub_00027590((a1 + (a1 * 2)) << 2);
        m_Field00 = t1;
        if (!t1) goto L_39;
        m_Field04 = t1;
        m_Field08 = ((a1 + (a1 * 2)) << 2) + t1;
        return true;
    }
    m_Field00 = 0;
L_39:
    m_Field04 = 0;
    m_Field08 = 0;
    return false;
}
