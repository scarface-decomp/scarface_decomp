// bin: xb
// va: 0x0031E540
// what: Start-up code (a static initializer): stores the name key of "GameBoatSet" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E540 (0x0031E540, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D0398[];
extern "C" int DAT_00490BCC;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031E540(void)
{
    DAT_00490BCC = sub_00244040((int)DAT_003D0398, 0);
}
