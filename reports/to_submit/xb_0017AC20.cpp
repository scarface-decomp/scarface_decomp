// bin: xb
// va: 0x0017AC20
// what: If an object is given, sets its on/off flag through its own function; always returns false.
// tool: Claude Opus 5.5 (symcov hint: CustomFaceExist(RString))
// sub_0017AC20 (0x0017AC20, 16 bytes)

class Class_00177A70
{
public:
    void sub_00177A70();
};

// Calls the object's method when the pointer is set, then reports false.
bool __cdecl sub_0017AC20(Class_00177A70 *object)
{
    if (object)
    {
        object->sub_00177A70();
    }
    return false;
}
