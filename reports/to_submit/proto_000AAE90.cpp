// bin: proto
// va: 0x000AAE90
// what: 
// tool: the portal's starter code (no AI)

// sub_000AAE90 (Proto 0x000AAE90, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00041490(int, int, float);

class Class_000AAE90
{
public:
    void sub_000AAE90(float a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

void Class_000AAE90::sub_000AAE90(float a1)
{
    int t1, t2;

    t1 = m_Field04;
    if (m_Field04) {
        t2 = m_Field00;
        if (!m_Field00) goto L_29;
        sub_00041490(t1, 0, *(float*)(t2 + 12) * a1);
    }
L_29:
    ;
}
