// bin: xb
// va: 0x001BD740
// what: 
// tool: the portal's starter code (no AI)

// sub_001BD740 (0x001BD740, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00199CE0(int);
extern "C" int __cdecl sub_002FC43E(int);

int __cdecl sub_001BD740(int a1, int a2, int a3)
{
    if (a2 == 2) {
        return sub_00199CE0(sub_002FC43E(*(int*)(a3 + 4)));
    }
    return sub_00199CE0(0);
}
