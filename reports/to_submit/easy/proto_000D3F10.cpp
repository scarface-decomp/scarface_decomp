// bin: proto
// va: 0x000D3F10
// tool: the portal's starter code (no AI)
// sub_000D3F10 (0x000D3F10, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
};

extern "C" char DAT_00386A54[];
extern "C" void __cdecl sub_0001F5E0(void);

class Class_000D3F10
{
public:
    Class_000D3F10* sub_000D3F10(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

Class_000D3F10* Class_000D3F10::sub_000D3F10(int a1, int a2)
{
    sub_0001F5E0();
    m_Field00 = (int)DAT_00386A54;
    m_Field08 = 0;
    m_Field0C = 0;
    m_Field10 = 0.0f;
    if (a1) {
        m_Field08 = a1;
        ((Object*)a1)->vfunc_00();
    }
    if (a2) {
        m_Field0C = a2;
        ((Object*)a2)->vfunc_00();
    }
    return this;
}
