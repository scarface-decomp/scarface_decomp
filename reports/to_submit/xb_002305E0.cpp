// bin: xb
// va: 0x002305E0
// what: 
// tool: the portal's starter code (no AI)

// sub_002305E0 (0x002305E0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00491EF8;
extern "C" bool __cdecl sub_00099BC0(int);

void __cdecl sub_002305E0(int a1, int a2, int a3)
{
    *(unsigned char*)(DAT_00491EF8 + 958) = sub_00099BC0(*(int*)(a3 + 4));
}
