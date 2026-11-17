// bin: xb
// va: 0x0004C3D0
// tool: the portal's starter code (no AI)
// sub_0004C3D0 (0x0004C3D0, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0006F990(int);

class Class_0004C3D0
{
public:
    int sub_0004C3D0(int a1);
};

int Class_0004C3D0::sub_0004C3D0(int a1)
{
    return sub_0006F990(*(int*)((a1 << 4) + (int)this + 76));
}
