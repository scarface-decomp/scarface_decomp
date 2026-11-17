// bin: xb
// va: 0x000803D0
// tool: the portal's starter code (no AI)
// sub_000803D0 (0x000803D0, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_00080040(int, int, int, int, int, int);
};

extern "C" int DAT_00481110;

bool __cdecl sub_000803D0(int a1, int a2, int a3, int a4, int a5, int a6)
{
    if (DAT_00481110) {
        return ((Object*)DAT_00481110)->sub_00080040(a1, a2, a4, a5, a3, a6);
    }
    return false;
}
