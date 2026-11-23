// bin: proto
// va: 0x000F8B40
// what: 
// tool: the portal's starter code (no AI)

// sub_000F8B40 (Proto 0x000F8B40, 77 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00027270(int);
    void sub_000F8510();
};

extern "C" Object DAT_0045BB90;
extern "C" bool DAT_0045BC74;
extern "C" char sub_002F17F0[];
extern "C" void __cdecl sub_002C8EB3(int);

class Class_000F8B40
{
public:
    void sub_000F8B40(int a1);
    char m_pad00[0x54];
    int m_Field54; // +0x54
};

void Class_000F8B40::sub_000F8B40(int a1)
{
    if (!(1 & DAT_0045BC74)) {
        *(int*)&DAT_0045BC74 = *(int*)&DAT_0045BC74 | 1;
        DAT_0045BB90.sub_000F8510();
        sub_002C8EB3((int)sub_002F17F0);
    }
    m_Field54 = DAT_0045BB90.sub_00027270(a1);
}
