// bin: xb
// va: 0x0006F050
// tool: the portal's starter code (no AI)
// sub_0006F050 (0x0006F050, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000745F0(int);
};

extern "C" char DAT_003A24DC[];
extern "C" char DAT_003A2694[];
extern "C" int DAT_004795AC;
extern "C" int __cdecl sub_000758D0(void);
extern "C" int __cdecl sub_000758E0(void);

int __cdecl sub_0006F050(float a1)
{
    int r_esi;

    r_esi = ((Object*)DAT_004795AC)->sub_000745F0(24);
    if (r_esi) {
        *(int*)r_esi = (int)DAT_003A24DC;
        *(int*)(r_esi + 4) = 0;
        *(int*)(r_esi + 8) = sub_000758D0();
        *(int*)(r_esi + 12) = sub_000758E0();
        *(int*)r_esi = (int)DAT_003A2694;
    }
    *(float*)(r_esi + 16) = a1;
    return r_esi;
}
