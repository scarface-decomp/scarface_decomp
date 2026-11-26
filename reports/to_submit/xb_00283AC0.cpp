// bin: xb
// va: 0x00283AC0
// what: Passes a pointer on to another function, or returns zero straight away when the pointer is null.
// tool: Claude (from SPEC-018)

int __cdecl sub_002A97B0(const void* text);

int __cdecl sub_00283AC0(const void* text)
{
    if (text == 0)
    {
        return 0;
    }
    return sub_002A97B0(text);
}
