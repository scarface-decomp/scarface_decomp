// bin: xb
// va: 0x00218C70
// tool: the portal's starter code (no AI)
// sub_00218C70 (0x00218C70, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000ABBD0();
    void sub_002ED360();
};

extern "C" int DAT_0044CCA8;

class Class_00218C70
{
public:
    void sub_00218C70();
    char m_pad00[0xAC];
    int m_FieldAC; // +0xAC
    char m_padB0[0x14];
    int m_FieldC4; // +0xC4
};

void Class_00218C70::sub_00218C70()
{
    int t1;

    if (!m_FieldAC) goto L_39;
    t1 = m_FieldC4;
    if (m_FieldC4) {
        if (!*(bool*)(t1 + 68)) goto L_38;
        *(int*)(t1 + 1620) = DAT_0044CCA8;
        ((Object*)t1 + 72)->sub_000ABBD0();
        ((Object*)*(int*)(t1 + 112))->sub_002ED360();
        return;
    }
L_38:
L_39:
    ;
}
