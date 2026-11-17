// bin: xb
// va: 0x0015C550
// tool: the portal's starter code (no AI)
// sub_0015C550 (0x0015C550, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0014FF60(int, int);
};

extern "C" char sub_0015C520[];
extern "C" int __cdecl sub_00099C30(int, int, int, int);

int __cdecl sub_0015C550(int a1, int a2, int a3)
{
    int r_eax;

    r_eax = a3;
    r_eax = *(int*)(r_eax + 8);
    if (*(unsigned char*)r_eax) {
        r_eax = sub_00099C30(15, r_eax, 0, 0);
        r_eax = ((Object*)a1)->sub_0014FF60((int)sub_0015C520, r_eax);
    }
    return r_eax;
}
