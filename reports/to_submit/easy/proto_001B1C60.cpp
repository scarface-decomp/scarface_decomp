// bin: proto
// va: 0x001B1C60
// tool: the portal's starter code (no AI)
// WorldAmbienceSpawnObject::vfunc_01 (0x001B1C60, 85 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field98
{
    void sub_001A6530(int);
};

extern "C" char DAT_003A2ECC[];
extern "C" int DAT_003A2F78;
extern "C" void __cdecl sub_00025160(int);

class WorldAmbienceSpawnObject
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    void sub_001B0CB0();
    char m_pad04[0x94];
    Field98* m_Field98; // +0x98
    int m_Field9C; // +0x9C
    char m_padA0[0x13];
    unsigned char m_FieldB3; // +0xB3
};

int WorldAmbienceSpawnObject::vfunc_01(int a1)
{
    int r_eax;

    *(int*)this = (int)DAT_003A2ECC;
    r_eax = ((int (__cdecl*)(void))DAT_003A2F78)();
    if (m_Field9C) {
        r_eax |= 1;
    }
    if (m_FieldB3 & 1) {
        m_Field98->sub_001A6530(r_eax);
        m_FieldB3 &= 254;
    }
    sub_001B0CB0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    r_eax = (int)this;
    return r_eax;
}
