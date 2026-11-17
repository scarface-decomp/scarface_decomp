// bin: proto
// va: 0x00050F70
// tool: the portal's starter code (no AI)
// sub_00050F70 (0x00050F70, 84 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002173C0();
};

extern "C" char DAT_003802AC[];
extern "C" char DAT_003802F4[];
extern "C" int __cdecl sub_001FCF20(int);
extern "C" void __stdcall sub_00217060(int);

class Class_00050F70
{
public:
    Class_00050F70* sub_00050F70();
    void sub_00216BB0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x38];
    float m_Field3C; // +0x3C
};

Class_00050F70* Class_00050F70::sub_00050F70()
{
    int r_esi;

    sub_00217060(1);
    m_Field00 = (int)DAT_003802F4;
    r_esi = sub_001FCF20(60);
    if (r_esi) {
        ((Object*)r_esi)->sub_002173C0();
        *(int*)r_esi = (int)DAT_003802AC;
        *(bool*)(r_esi + 56) = true;
        *(int*)(r_esi + 12) = 1;
    } else {
        r_esi = 0;
    }
    sub_00216BB0(0, r_esi);
    m_Field3C = 0.0f;
    return this;
}
