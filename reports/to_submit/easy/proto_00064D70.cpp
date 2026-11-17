// bin: proto
// va: 0x00064D70
// tool: the portal's starter code (no AI)
// sub_00064D70 (0x00064D70, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00069F60(int);
};

extern "C" char DAT_003819DC[];
extern "C" char DAT_00381B90[];
extern "C" int DAT_0044E08C;
extern "C" int __cdecl sub_0006B230(void);
extern "C" int __cdecl sub_0006B240(void);

int __cdecl sub_00064D70(float a1)
{
    int r_esi;

    r_esi = ((Object*)DAT_0044E08C)->sub_00069F60(24);
    if (r_esi) {
        *(int*)r_esi = (int)DAT_003819DC;
        *(int*)(r_esi + 4) = 0;
        *(int*)(r_esi + 8) = sub_0006B230();
        *(int*)(r_esi + 12) = sub_0006B240();
        *(int*)r_esi = (int)DAT_00381B90;
    }
    *(float*)(r_esi + 16) = a1;
    return r_esi;
}
