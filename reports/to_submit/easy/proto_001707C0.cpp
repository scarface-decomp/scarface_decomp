// bin: proto
// va: 0x001707C0
// tool: the portal's starter code (no AI)
// GenericMenuClient::vfunc_02 (0x001707C0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00170100(int);

class GenericMenuClient
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(bool a1);
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
};

void GenericMenuClient::vfunc_02(bool a1)
{
    sub_00170100(1);
    if (!a1) {
        vfunc_09();
    }
}
