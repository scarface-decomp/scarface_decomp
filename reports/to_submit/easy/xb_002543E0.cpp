// bin: xb
// va: 0x002543E0
// tool: the portal's starter code (no AI)
// sub_002543E0 (0x002543E0, 83 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

class Class_002543E0
{
public:
    void sub_002543E0(int a1, int a2, float a3);
    void sub_00253D90(int);
    char m_pad00[0x10];
    int m_Field10; // +0x10
};

void Class_002543E0::sub_002543E0(int a1, int a2, float a3)
{
    int t1;

    if (a2 < 0) goto L_4E;
    t1 = m_Field10 + (a2 * 196);
    if (*(int*)(m_Field10 + (a2 * 196) + 132)) {
        if (*(int*)t1 != a1) goto L_4D;
        sub_00253D90(a2);
        *(float*)(m_Field10 + (a2 * 196) + 144) = a3;
        *(bool*)(m_Field10 + (a2 * 196) + 153) = true;
    }
L_4D:
L_4E:
    ;
}
