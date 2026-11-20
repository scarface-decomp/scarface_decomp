// bin: xb
// va: 0x0017AC30
// what: If an object is given, clears its on/off flag through its own function; always returns false.
// tool: Claude Opus 5.5 (symcov hint: CustomFaceExist(RString))
// sub_0017AC30 (0x0017AC30, 16 bytes)

class Class_00177B10
{
public:
    void sub_00177B10();
};

// Calls the object's method when the pointer is set, then reports false.
bool __cdecl sub_0017AC30(Class_00177B10 *object)
{
    if (object)
    {
        object->sub_00177B10();
    }
    return false;
}
