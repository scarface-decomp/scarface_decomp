// bin: xb
// va: 0x001EB8E0
// tool: the portal's starter code (no AI)
// WorldAmbienceSpawnObject::vfunc_01 (0x001EB8E0, 85 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field94
{
    void sub_001DE370(int);
};

extern "C" char DAT_003C8EB4[];
extern "C" int DAT_003C8F68;
extern "C" void __cdecl sub_00027600(int);

class WorldAmbienceSpawnObject
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    void sub_001EA010();
    char m_pad04[0x90];
    Field94* m_Field94; // +0x94
    int m_Field98; // +0x98
    char m_pad9C[0x17];
    unsigned char m_FieldB3; // +0xB3
};

int WorldAmbienceSpawnObject::vfunc_01(int a1)
{
    int r_eax;

    *(int*)this = (int)DAT_003C8EB4;
    r_eax = ((int (__cdecl*)(void))DAT_003C8F68)();
    if (m_Field98) {
        r_eax |= 1;
    }
    if (m_FieldB3 & 1) {
        m_Field94->sub_001DE370(r_eax);
        m_FieldB3 &= 254;
    }
    sub_001EA010();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    r_eax = (int)this;
    return r_eax;
}
