// bin: proto
// va: 0x00109BC0
// tool: the portal's starter code (no AI)
// sub_00109BC0 (0x00109BC0, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00109980();
};

extern "C" Object DAT_0045BFF0;
extern "C" bool DAT_0045C000;
extern "C" char sub_002F27C0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_00109BC0(void)
{
    if (!(1 & DAT_0045C000)) {
        *(int*)&DAT_0045C000 = *(int*)&DAT_0045C000 | 1;
        DAT_0045BFF0.sub_00109980();
        sub_002C8EB3((int)sub_002F27C0);
    }
}
