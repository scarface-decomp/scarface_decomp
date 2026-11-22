// bin: proto
// va: 0x001189A0
// what: 
// tool: the portal's starter code (no AI)

// sub_001189A0 (Proto 0x001189A0, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0014A570(int, int);
    int sub_0014A630(int, int);
};

extern "C" int DAT_0045C278;

void __cdecl sub_001189A0(int a1, float a2)
{
    ((Object*)a1)->sub_0014A570(2, DAT_0045C278);
    *(float*)(((Object*)a1)->sub_0014A630(2, 1) + 88) = a2;
}
