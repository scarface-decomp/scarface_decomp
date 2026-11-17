// bin: xb
// va: 0x00164C60
// tool: the portal's starter code (no AI)
// sub_00164C60 (0x00164C60, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_00048DF0(int);

class Class_00164C60
{
public:
    bool sub_00164C60();
    char m_pad00[0x1AC];
    int m_Field1AC; // +0x1AC
};

bool Class_00164C60::sub_00164C60()
{
    int t1, t2;

    t1 = m_Field1AC;
    if (m_Field1AC) {
        t2 = *(int*)(t1 + 172);
        if (!*(int*)(t1 + 172)) goto L_1E;
        return sub_00048DF0(t2);
    }
L_1E:
    return false;
}
