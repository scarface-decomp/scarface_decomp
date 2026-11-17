// bin: xb
// va: 0x001C7240
// tool: the portal's starter code (no AI)
// sub_001C7240 (0x001C7240, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0002B350(int, int);
};

extern "C" int DAT_0048E690;
extern "C" int __cdecl sub_002FC43E(int);

int __stdcall sub_001C7240(int a1)
{
    return sub_002FC43E(((Object*)a1)->sub_0002B350(DAT_0048E690, 0));
}
