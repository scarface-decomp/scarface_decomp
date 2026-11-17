// bin: pc
// va: 0x006F39E0
// tool: the portal's starter code (no AI)
// sub_006F39E0 (0x006F39E0, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0072F990;
extern "C" float DAT_0072F994;
extern "C" float DAT_0074660C;
extern "C" float DAT_00763FFC;
extern "C" float DAT_00764004;
extern "C" float DAT_00764008;

float __cdecl sub_006F39E0(bool a1)
{
    if (a1 & 16) {
        return DAT_0074660C;
    }
    if (a1 & 8) {
        return DAT_0072F990;
    }
    if (a1 & 4) {
        return DAT_00764004;
    }
    if (a1 & 2) {
        return DAT_00764008;
    }
    if (a1 & 1) {
        return DAT_00763FFC;
    }
    return DAT_0072F994;
}
