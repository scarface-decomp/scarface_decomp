// bin: proto
// va: 0x000F2040
// what: 
// tool: the portal's starter code (no AI)

// sub_000F2040 (Proto 0x000F2040, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001050F0(int);
};

extern "C" Object DAT_0045BAD8;
extern "C" bool DAT_0045BADC;
extern "C" char sub_002F17C0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_000F2040(void)
{
    if (!(1 & DAT_0045BADC)) {
        *(int*)&DAT_0045BADC |= 1;
        DAT_0045BAD8.sub_001050F0(0);
        sub_002C8EB3((int)sub_002F17C0);
    }
}
