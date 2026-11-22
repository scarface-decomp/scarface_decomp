// bin: proto
// va: 0x0010CC10
// what: 
// tool: the portal's starter code (no AI)

// sub_0010CC10 (Proto 0x0010CC10, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FF300();
};

extern "C" Object DAT_0045C0D8;
extern "C" int DAT_0045C0F4;
extern "C" bool DAT_0045C0F8;
extern "C" char sub_002F2800[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_0010CC10(void)
{
    if (!(1 & DAT_0045C0F8)) {
        *(int*)&DAT_0045C0F8 = *(int*)&DAT_0045C0F8 | 1;
        DAT_0045C0D8.sub_001FF300();
        DAT_0045C0F4 = 32;
        sub_002C8EB3((int)sub_002F2800);
    }
}
