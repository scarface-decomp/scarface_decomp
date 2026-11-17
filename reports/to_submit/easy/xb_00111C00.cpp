// bin: xb
// va: 0x00111C00
// tool: the portal's starter code (no AI)
// sub_00111C00 (0x00111C00, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __stdcall sub_00111B70(int, int);

class Class_00111C00
{
public:
    void sub_00111C00(int a1);
    int m_Field00; // +0x00
};

void Class_00111C00::sub_00111C00(int a1)
{
    if (!sub_00111B70(a1, 0)) {
        m_Field00 = !m_Field00;
    }
}
