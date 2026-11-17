// bin: xb
// va: 0x000BC400
// tool: the portal's starter code (no AI)
// sub_000BC400 (0x000BC400, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00486C44;
extern "C" void __cdecl sub_00027600(int);

void __cdecl sub_000BC400(void)
{
    int r_esi, t1, t2;

    r_esi = DAT_00486C44;
    t1 = DAT_00486C44;
    if (DAT_00486C44) {
        *(int*)(t1 + 4) = *(int*)t1;
        t2 = *(int*)r_esi;
        if (*(int*)r_esi) {
            sub_00027600(t2);
        }
        sub_00027600(r_esi);
    }
    DAT_00486C44 = 0;
}
