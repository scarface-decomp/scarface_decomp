// bin: xb
// va: 0x00101A60
// tool: the portal's starter code (no AI)
// sub_00101A60 (0x00101A60, 93 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0048954C;
extern "C" float DAT_00489550;
extern "C" float DAT_00489554;
extern "C" bool DAT_00489558;
extern "C" int __cdecl sub_000CE360(void);

class Class_00101A60
{
public:
    void* sub_00101A60();
    char m_pad00[0x1C];
    int m_Field1C; // +0x1C
    char m_pad20[0x24];
    bool m_Field44; // +0x44
};

void* Class_00101A60::sub_00101A60()
{
    int t1;

    t1 = sub_000CE360();
    if (t1 != 3) {
        if (t1 == 4) {
            if (!m_Field44) goto L_58;
        }
        if (!(1 & DAT_00489558)) {
            *(int*)&DAT_00489558 = *(int*)&DAT_00489558 | 1;
            DAT_0048954C = 0.0f;
            DAT_00489550 = 0.0f;
            DAT_00489554 = 0.0f;
        }
        return &DAT_0048954C;
    }
L_58:
    return &m_Field1C;
}
