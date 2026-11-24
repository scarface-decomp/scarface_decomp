// bin: proto
// va: 0x000F8B90
// what: 
// tool: the portal's starter code (no AI)

// sub_000F8B90 (Proto 0x000F8B90, 79 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000F8510();
};

extern "C" Object DAT_0045BB90;
extern "C" unsigned char DAT_0045BC74;
extern "C" char sub_002F17F0[];
extern "C" int __cdecl sub_00028CF0(int, int);
extern "C" void __cdecl sub_002C8EB3(int);

class Class_000F8B90
{
public:
    void sub_000F8B90(int a1);
    char m_pad00[0x58];
    int m_Field58; // +0x58
    int m_Field5C; // +0x5C
};

void Class_000F8B90::sub_000F8B90(int a1)
{
    if (!(DAT_0045BC74 & 1)) {
        *(int*)&DAT_0045BC74 = *(int*)&DAT_0045BC74 | 1;
        DAT_0045BB90.sub_000F8510();
        sub_002C8EB3((int)sub_002F17F0);
    }
    m_Field58 = sub_00028CF0(a1, 0);
    m_Field5C = 1;
}
