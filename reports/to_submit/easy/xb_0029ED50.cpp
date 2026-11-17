// bin: xb
// va: 0x0029ED50
// tool: the portal's starter code (no AI)
// pure3d::_pddiExtMemRegistration::vfunc_01 (0x0029ED50, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" int DAT_004BDC58;

namespace pure3d {

class _pddiExtMemRegistration
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
};

int _pddiExtMemRegistration::vfunc_01(int a1)
{
    DAT_004BDC58 = a1;
    return a1;
}

}
