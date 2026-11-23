// bin: xb
// va: 0x001FEC40
// what: 
// tool: the portal's starter code (no AI)

// sub_001FEC40 (0x001FEC40, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001FFF10();
};

int __cdecl sub_001FEC40(int a1)
{
    return *(int*)(((Object*)a1)->sub_001FFF10() + 16);
}
