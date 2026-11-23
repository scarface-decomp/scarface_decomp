// bin: xb
// va: 0x001C32E0
// what: 
// tool: the portal's starter code (no AI)

// sub_001C32E0 (0x001C32E0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001C3620(int, int, int, int);
};

void __cdecl sub_001C32E0(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_001C3620(*(int*)(a3 + 8), *(int*)(a3 + 12), *(int*)(a3 + 16), *(int*)(a3 + 20));
}
