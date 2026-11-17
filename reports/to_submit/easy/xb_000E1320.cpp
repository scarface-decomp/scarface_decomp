// bin: xb
// va: 0x000E1320
// tool: the portal's starter code (no AI)
// sub_000E1320 (0x000E1320, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00287A80(int, int, int);
};

extern "C" float DAT_0039D664;

class Class_000E1320
{
public:
    int sub_000E1320(int a1, int a2, int a3);
    char m_pad00[0x30];
    int m_Field30; // +0x30
};

int Class_000E1320::sub_000E1320(int a1, int a2, int a3)
{
    int t1;

    t1 = m_Field30;
    if (m_Field30) {
        return ((Object*)t1)->sub_00287A80(a1, a2, a3);
    }
    *(float*)(a3 + 8) = 0.0f;
    *(float*)(a3 + 4) = 0.0f;
    *(float*)a3 = 0.0f;
    *(float*)(a3 + 12) = DAT_0039D664;
    return a3;
}
