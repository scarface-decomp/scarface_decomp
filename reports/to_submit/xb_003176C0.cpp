// bin: xb
// va: 0x003176C0
// what: Start-up code (a static initializer): stores the name key of "green" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003176C0 (0x003176C0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B2CA4[];
extern "C" int DAT_0048A168;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_003176C0(void)
{
    DAT_0048A168 = sub_00244040((int)DAT_003B2CA4, 0);
}
