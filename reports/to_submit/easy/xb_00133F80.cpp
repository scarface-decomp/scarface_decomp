// bin: xb
// va: 0x00133F80
// tool: the portal's starter code (no AI)
// sub_00133F80 (0x00133F80, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00166F70(int, int);
    int sub_00167030(int, int);
};

extern "C" int DAT_0048A0A4;

void __cdecl sub_00133F80(int a1, float a2)
{
    ((Object*)a1)->sub_00166F70(2, DAT_0048A0A4);
    *(float*)(((Object*)a1)->sub_00167030(2, 1) + 88) = a2;
}
