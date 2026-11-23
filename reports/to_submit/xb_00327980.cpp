// bin: xb
// va: 0x00327980
// what: 
// tool: the portal's starter code (no AI)

// sub_00327980 (0x00327980, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0020C490();
};

extern "C" char DAT_003CBB4C[];
extern "C" int DAT_00490440;

void __cdecl sub_00327980(void)
{
    DAT_00490440 = (int)DAT_003CBB4C;
    ((Object*)(int)&DAT_00490440)->sub_0020C490();
}
