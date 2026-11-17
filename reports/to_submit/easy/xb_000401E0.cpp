// bin: xb
// va: 0x000401E0
// tool: the portal's starter code (no AI)
// sub_000401E0 (0x000401E0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0003FF40(int);
};

extern "C" int DAT_00474E38;

class Class_000401E0
{
public:
    void sub_000401E0();
    char m_pad00[0x1C];
    unsigned char m_Field1C; // +0x1C
};

void Class_000401E0::sub_000401E0()
{
    if (DAT_00474E38) {
        if (!(m_Field1C & 2)) goto L_1D;
        ((Object*)DAT_00474E38)->sub_0003FF40((int)this);
        m_Field1C &= 253;
    }
L_1D:
    ;
}
