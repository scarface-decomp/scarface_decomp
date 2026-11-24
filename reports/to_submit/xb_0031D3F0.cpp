// bin: xb
// va: 0x0031D3F0
// what: Start-up code (a static initializer): stores the name key of "VibeTemplateGroup" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031D3F0 (0x0031D3F0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003CB604[];
extern "C" int DAT_004903AC;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031D3F0(void)
{
    DAT_004903AC = sub_00244040((int)DAT_003CB604, 0);
}
