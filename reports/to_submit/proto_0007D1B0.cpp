// bin: proto
// va: 0x0007D1B0
// what: 
// tool: the portal's starter code (no AI)

// sub_0007D1B0 (Proto 0x0007D1B0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00015510(int);

class Class_0007D1B0
{
public:
    void sub_0007D1B0();
    int m_Field00; // +0x00
    bool m_Field04; // +0x04
};

void Class_0007D1B0::sub_0007D1B0()
{
    int t1;

    if (!m_Field04) goto L_22;
    t1 = m_Field00;
    if (m_Field00) {
        if (!*(unsigned char*)t1) goto L_1E;
        sub_00015510(t1);
    }
L_1E:
    m_Field04 = false;
L_22:
    ;
}
