// bin: xb
// va: 0x001BD6D0
// what: 
// tool: the portal's starter code (no AI)

// sub_001BD6D0 (0x001BD6D0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0048C23C;
extern "C" bool __cdecl sub_00099BC0(int);

void __cdecl sub_001BD6D0(int a1, int a2, int a3)
{
    int t1;

    t1 = DAT_0048C23C;
    *(unsigned char*)(t1 + 90) = (unsigned char)(*(bool*)(t1 + 90) ^ ((unsigned char)(((unsigned char)(((unsigned char)(sub_00099BC0(*(int*)(a3 + 4)) << 1)) ^ *(bool*)(t1 + 90))) & 2)));
    *(int*)(t1 + 80) = -1;
}
