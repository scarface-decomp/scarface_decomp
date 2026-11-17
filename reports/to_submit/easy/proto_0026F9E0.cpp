// bin: proto
// va: 0x0026F9E0
// tool: the portal's starter code (no AI)
// sub_0026F9E0 (0x0026F9E0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0020DEA0(int);

class Class_0026F9E0
{
public:
    void sub_0026F9E0(int a1, int a2);
    void sub_0026F7F0(int, int);
};

void Class_0026F9E0::sub_0026F9E0(int a1, int a2)
{
    int r_eax;

    r_eax = a1;
    if (*(unsigned char*)r_eax == 92) {
        r_eax += 1;
    }
    r_eax = sub_0020DEA0(r_eax);
    sub_0026F7F0(r_eax, a2);
}
