// bin: xb
// va: 0x001C72A0
// what: 
// tool: the portal's starter code (no AI)

// sub_001C72A0 (0x001C72A0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0002B350(int, int);
};

extern "C" int DAT_0048E698;
extern "C" int __cdecl sub_002FC43E(int);

int __stdcall sub_001C72A0(int a1)
{
    return sub_002FC43E(((Object*)a1)->sub_0002B350(DAT_0048E698, 0));
}
