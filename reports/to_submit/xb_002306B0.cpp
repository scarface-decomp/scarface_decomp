// bin: xb
// va: 0x002306B0
// what: 
// tool: the portal's starter code (no AI)

// sub_002306B0 (0x002306B0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_00099BC0(int);
extern "C" void __cdecl sub_001EA940(int);

void __cdecl sub_002306B0(int a1, int a2, int a3)
{
    if (sub_00099BC0(*(int*)(a3 + 4))) {
        sub_001EA940(5);
        return;
    }
    sub_001EA940(0);
}
