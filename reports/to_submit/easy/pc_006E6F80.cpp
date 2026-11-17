// bin: pc
// va: 0x006E6F80
// tool: the portal's starter code (no AI)
// sub_006E6F80 (0x006E6F80, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_006DCC70(int);

class Class_006E6F80
{
public:
    void sub_006E6F80(int a1, int a2);
    void sub_006E6D90(int, int);
};

void Class_006E6F80::sub_006E6F80(int a1, int a2)
{
    int r_eax;

    r_eax = a1;
    if (*(unsigned char*)r_eax == 92) {
        r_eax += 1;
    }
    r_eax = sub_006DCC70(r_eax);
    sub_006E6D90(r_eax, a2);
}
