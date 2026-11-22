// bin: pc
// va: 0x006E6730
// what: 
// tool: the portal's starter code (no AI)

// core::CementLibrary::vfunc_05 (PC 0x006E6730, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006DCAD0(void);
extern "C" void __cdecl sub_006DEFA0(int);

namespace core {

class CementLibrary
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

void CementLibrary::vfunc_05()
{
    if (!m_Field20) {
        do {
            sub_006DCAD0();
            sub_006DEFA0(0);
        } while (!m_Field20);
    }
}

}
