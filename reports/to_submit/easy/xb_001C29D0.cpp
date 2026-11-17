// bin: xb
// va: 0x001C29D0
// tool: the portal's starter code (no AI)
// HUDDistanceBubbleRestoreData::vfunc_00 (0x001C29D0, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C2CE0[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_001930C0(void);

class HUDDistanceBubbleRestoreData
{
public:
    virtual HUDDistanceBubbleRestoreData* vfunc_00(int a1);
    char m_pad04[0x4];
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

HUDDistanceBubbleRestoreData* HUDDistanceBubbleRestoreData::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003C2CE0;
    m_Field10 = 0.0f;
    m_Field0C = 0.0f;
    m_Field08 = 0.0f;
    sub_001930C0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}
