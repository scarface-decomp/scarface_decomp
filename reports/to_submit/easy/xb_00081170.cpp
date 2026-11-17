// bin: xb
// va: 0x00081170
// tool: the portal's starter code (no AI)
// sub_00081170 (0x00081170, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_00080CB0(int, int, int);
};

extern "C" int DAT_00481110;

bool __cdecl sub_00081170(int a1, int a2, int a3)
{
    if (DAT_00481110) {
        return ((Object*)DAT_00481110)->sub_00080CB0(a1, a2, a3);
    }
    return false;
}
