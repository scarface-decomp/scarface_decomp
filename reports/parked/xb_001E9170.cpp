// parked: 39/39 bytes (verify.py --match sub_001E9170, VERIFIED with 2 relocations unchecked); tried an explicit dtor call plus sub_00027600 through a local (16 bytes off: the global is not loaded into ecx first) and through the global (reloads it after the call, 40 bytes); only `delete` gives retail's code; stuck at agent.py check: `delete` emits ??_GClass_001E8B80 next to the target, and the destructor (0x001E8B80) and operator delete (0x00027600) are not in reports/names.json, so both calls stay unchecked.
// bin: xb
// va: 0x001E9170
// what: Destroys the object held in a global pointer, if there is one, and clears the pointer.
// tool: Claude Opus 5.5 (symcov hint: cHelpText::EndScene)
// sub_001E9170 (0x001E9170, 39 bytes)
// sub_001E8B80 is the object's destructor and sub_00027600 the memory release that
// `delete` calls; both are written by address until they have checked names.

class Class_001E8B80
{
public:
    ~Class_001E8B80();
};

extern "C" Class_001E8B80 *DAT_0048F740;
extern "C" void __cdecl sub_00027600(void *memory);

// Tears down and frees the global object, then forgets it.
void __cdecl sub_001E9170()
{
    if (DAT_0048F740)
    {
        delete DAT_0048F740;
        DAT_0048F740 = 0;
    }
}
