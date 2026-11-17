// bin: xb
// va: 0x00113300
// tool: the portal's starter code (no AI)
// sub_00113300 (0x00113300, 71 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00111F10(int, int);
};

extern "C" float DAT_0039D664;
extern "C" int DAT_004897F0;

class Class_00113300
{
public:
    int sub_00113300(int a1);
    char m_pad00[0x74];
    int m_Field74; // +0x74
};

int Class_00113300::sub_00113300(int a1)
{
    if ((m_Field74 & 2032) != 2032) {
        ((Object*)DAT_004897F0)->sub_00111F10(a1, (int)this);
        return a1;
    }
    *(float*)a1 = 0.0f;
    *(float*)(a1 + 4) = 0.0f;
    *(float*)(a1 + 8) = DAT_0039D664;
    return a1;
}
