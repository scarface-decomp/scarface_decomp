// bin: proto
// va: 0x000B9B70
// what: Finishes with the object held at +0x38 if there is one, then resets this object's state.
// tool: Claude Opus 5.5 (transplanted from xb:0x000C88F0, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003F45D8[];
extern "C" char DAT_003F5430[];
extern "C" int DAT_003FF2EC;
extern "C" int __cdecl sub_00028CF0(int, int);
extern "C" int __cdecl sub_002C92F8(int, int, int, int, int);

class Class_000B9B70
{
public:
    int sub_000B9B70();
    int sub_000B93C0();
    char m_pad00[0x30];
    int m_Field30; // +0x30
    char m_pad34[0x4];
    int m_Field38; // +0x38
    char m_pad3C[0x28];
    int m_Field64; // +0x64
    char m_pad68[0x2];
    bool m_Field6A; // +0x6A
};

int Class_000B9B70::sub_000B9B70()
{
    int r_eax;

    r_eax = m_Field38;
    if (r_eax) {
        r_eax = DAT_003FF2EC;
        r_eax = sub_00028CF0(r_eax, 0);
        r_eax = sub_002C92F8(r_eax, 0, (int)DAT_003F45D8, (int)DAT_003F5430, 0);
        if (!r_eax) goto L_39;
        r_eax = sub_000B93C0();
    }
L_39:
    m_Field38 = 0;
    m_Field6A = true;
    m_Field64 = -1;
    m_Field30 = 0;
    return r_eax;
}