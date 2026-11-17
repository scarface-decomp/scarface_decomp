// bin: xb
// va: 0x00215660
// tool: the portal's starter code (no AI)
// sub_00215660 (0x00215660, 91 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00098BB0(int);
};

extern "C" Object DAT_00490BC8;
extern "C" int DAT_00490BCC;

void __cdecl sub_00215660(void)
{
    int r_edi, r_esi, t4;

    r_edi = *(short*)(DAT_00490BC8.sub_00098BB0(DAT_00490BCC) + 56);
    r_esi = 0;
    if (r_edi > 0) {
        do {
            t4 = *(int*)(*(int*)(DAT_00490BC8.sub_00098BB0(DAT_00490BCC) + 48) + (((short)((unsigned short)r_esi)) * 4));
            r_esi += 1;
            *(bool*)(t4 + 238) = false;
            *(bool*)(t4 + 239) = false;
            *(bool*)(t4 + 237) = false;
            *(bool*)(t4 + 236) = false;
        } while (r_esi < r_edi);
    }
}
