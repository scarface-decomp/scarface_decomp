// bin: proto
// va: 0x0023DCA0
// tool: the portal's starter code (no AI)
// sub_0023DCA0 (0x0023DCA0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_0031A4D0(int);

class Class_0023DCA0
{
public:
    void sub_0023DCA0(int a1);
    char m_pad00[0x110];
    int m_Field110; // +0x110
};

void Class_0023DCA0::sub_0023DCA0(int a1)
{
    if (m_Field110 != a1) {
        m_Field110 = a1;
        a1 = a1;
        sub_0031A4D0(a1);
        return;
    }
}
