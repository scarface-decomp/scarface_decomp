// bin: xb
// va: 0x00222BA0
// what: 
// tool: the portal's starter code (no AI)

// sub_00222BA0 (0x00222BA0, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00099BC0(int);
extern "C" void __cdecl sub_00221650(int);

void __cdecl sub_00222BA0(int a1, int a2, int a3)
{
    sub_00221650(sub_00099BC0(*(int*)(a3 + 4)));
}
