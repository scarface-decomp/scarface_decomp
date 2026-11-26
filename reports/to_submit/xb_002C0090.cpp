// bin: xb
// va: 0x002C0090
// what: Creates the Xbox save drive: remembers the allocator, allocates the object from it and constructs it with the drive's name.
// tool: Claude (from SPEC-016)

extern "C" void* DAT_0045894C;      // the allocator the save drive was made with
void* __cdecl sub_00244450(void* allocator, unsigned int size);     // AllocateFromHeap

class XboxSaveDrive
{
public:
    XboxSaveDrive* sub_002BFB50(const char* name, void* allocator);    // the constructor
    char m_Data[0x92C];
};

// What `new (allocator) XboxSaveDrive(name, allocator)` compiles to, with the constructor called by its address name.
void __cdecl sub_002C0090(XboxSaveDrive** result, const char* name, void* allocator)
{
    DAT_0045894C = allocator;
    XboxSaveDrive* memory = (XboxSaveDrive*)sub_00244450(allocator, sizeof(XboxSaveDrive));
    *result = memory ? memory->sub_002BFB50(name, allocator) : 0;
}
