// bin: xb
// va: 0x0016F3E0
// tool: the portal's starter code (no AI)
// sub_0016F3E0 (0x0016F3E0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_0016E750(int);

class Class_0016F3E0
{
public:
    void sub_0016F3E0(int a1);
    char m_pad00[0x43C];
    int m_Field43C; // +0x43C
    char m_pad440[0x8];
    bool m_Field448; // +0x448
};

void Class_0016F3E0::sub_0016F3E0(int a1)
{
    if (m_Field43C != a1) {
        m_Field43C = a1;
        if (m_Field448) goto L_25;
        a1 = a1;
        sub_0016E750(a1);
        return;
    }
L_25:
    ;
}
