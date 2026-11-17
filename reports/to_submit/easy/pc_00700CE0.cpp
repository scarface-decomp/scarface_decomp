// bin: pc
// va: 0x00700CE0
// tool: the portal's starter code (no AI)
// sub_00700CE0 (0x00700CE0, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F33F0(int, int);

class Class_00700CE0
{
public:
    int sub_00700CE0(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

int Class_00700CE0::sub_00700CE0(int a1)
{
    if (sub_006F33F0(a1, m_Field00)) {
        if (!sub_006F33F0(a1, m_Field04)) goto L_33;
        return 1;
    }
L_33:
    return 0;
}
