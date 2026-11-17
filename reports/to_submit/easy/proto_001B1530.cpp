// bin: proto
// va: 0x001B1530
// tool: the portal's starter code (no AI)
// WorldAmbienceSpawnObject::vfunc_05 (0x001B1530, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001AF720(int, int);
};

extern "C" int DAT_00460C24;
extern "C" void __stdcall sub_001B0CD0(int);

class WorldAmbienceSpawnObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    char m_pad04[0x84];
    int m_Field88; // +0x88
    char m_pad8C[0xC];
    int m_Field98; // +0x98
    int m_Field9C; // +0x9C
};

void WorldAmbienceSpawnObject::vfunc_05(int a1)
{
    sub_001B0CD0(a1);
    if (!m_Field9C) {
        m_Field98 = ((Object*)DAT_00460C24)->sub_001AF720(m_Field88, 0);
    }
}
