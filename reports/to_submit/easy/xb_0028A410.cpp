// bin: xb
// va: 0x0028A410
// tool: the portal's starter code (no AI)
// pure3d::CompressedQuaternionChannel<math::CompressedQuaternion8>::vfunc_00 (0x0028A410, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" char DAT_003D839C[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_002884C0(void);

namespace math { class CompressedQuaternion8; }

namespace pure3d { 
template <class T0> class CompressedQuaternionChannel
{
public:
    virtual CompressedQuaternionChannel<math::CompressedQuaternion8>* vfunc_00(int a1);
    void sub_00288B80();
};
}

template <> pure3d::CompressedQuaternionChannel<math::CompressedQuaternion8>* pure3d::CompressedQuaternionChannel<math::CompressedQuaternion8>::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003D839C;
    sub_002884C0();
    sub_00288B80();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}
