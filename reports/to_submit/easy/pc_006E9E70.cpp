// bin: pc
// va: 0x006E9E70
// tool: the portal's starter code (no AI)
// NISStreamDataLoader::vfunc_04 (0x006E9E70, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class NISStreamDataLoader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1, int a2, int a3, int a4, int a5);
    virtual void vfunc_05();
    virtual void vfunc_06(int, int, int, int);
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

void NISStreamDataLoader::vfunc_04(int a1, int a2, int a3, int a4, int a5)
{
    vfunc_06(a1, a2, m_Field10, a5);
}
