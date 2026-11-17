// bin: proto
// va: 0x000EB610
// tool: the portal's starter code (no AI)
// sub_000EB610 (0x000EB610, 93 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0045BA00;
extern "C" float DAT_0045BA04;
extern "C" float DAT_0045BA08;
extern "C" bool DAT_0045BA0C;
extern "C" int __cdecl sub_00056450(void);

class Class_000EB610
{
public:
    void* sub_000EB610();
    char m_pad00[0x1C];
    int m_Field1C; // +0x1C
    char m_pad20[0x20];
    bool m_Field40; // +0x40
};

void* Class_000EB610::sub_000EB610()
{
    int t1;

    t1 = sub_00056450();
    if (t1 != 3) {
        if (t1 == 4) {
            if (!m_Field40) goto L_58;
        }
        if (!(1 & DAT_0045BA0C)) {
            *(int*)&DAT_0045BA0C = *(int*)&DAT_0045BA0C | 1;
            DAT_0045BA00 = 0.0f;
            DAT_0045BA04 = 0.0f;
            DAT_0045BA08 = 0.0f;
        }
        return &DAT_0045BA00;
    }
L_58:
    return &m_Field1C;
}
