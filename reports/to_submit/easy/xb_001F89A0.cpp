// bin: xb
// va: 0x001F89A0
// tool: the portal's starter code (no AI)
// sub_001F89A0 (0x001F89A0, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00098B90(int);
};

class Class_001F89A0
{
public:
    void sub_001F89A0();
    char m_pad00[0x8];
    int m_Field08; // +0x08
};

void Class_001F89A0::sub_001F89A0()
{
    int r_edi, r_esi;

    r_esi = (int)(&m_Field08);
    r_edi = 8;
    do {
        ((Object*)r_esi + -8)->sub_00098B90(0);
        *(float*)(r_esi + -4) = 0.0f;
        *(float*)r_esi = 0.0f;
        *(bool*)(r_esi + 5) = false;
        *(bool*)(r_esi + 4) = false;
        r_esi += 16;
        r_edi -= 1;
    } while (r_edi);
}
