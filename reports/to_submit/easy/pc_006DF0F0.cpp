// bin: pc
// va: 0x006DF0F0
// tool: the portal's starter code (no AI)
// sub_006DF0F0 (0x006DF0F0, 78 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F094;
extern "C" int DAT_0072F098;
extern "C" int DAT_0085CDB8;
extern "C" int DAT_0085CDBC;
extern "C" char DAT_0085CDC4[];

void __cdecl sub_006DF0F0(int a1)
{
    int r_eax;

    ((void (__stdcall*)(int))DAT_0072F094)((int)DAT_0085CDC4);
    r_eax = a1;
    if (!DAT_0085CDBC) {
        DAT_0085CDBC = a1;
        *(int*)(r_eax + 4) = 0;
    } else {
        *(int*)DAT_0085CDB8 = r_eax;
        *(int*)(r_eax + 4) = DAT_0085CDB8;
    }
    DAT_0085CDB8 = r_eax;
    *(int*)r_eax = 0;
    ((void (__stdcall*)(int))DAT_0072F098)((int)DAT_0085CDC4);
}
