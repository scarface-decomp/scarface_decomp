// bin: proto
// va: 0x00025090
// tool: the portal's starter code (no AI)
// MemoryManager::Allocator::vfunc_08 (0x00025090, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08(int);
};

namespace MemoryManager {

class Allocator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08(int a1);
    char m_pad04[0x2C];
    Field30* m_Field30; // +0x30
    char m_pad34[0x4];
    int m_Field38; // +0x38
};

void Allocator::vfunc_08(int a1)
{
    if (a1) {
        m_Field38 -= 1;
        a1 = a1;
        m_Field30->vfunc_08(a1);
        return;
    }
}

}
