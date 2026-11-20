// bin: xb
// va: 0x00063880
// what: Sets an on/off flag on the object held in a global pointer.
// tool: Claude Opus 5.5 (symcov hint: TScriptFunction_General::TriggerCamera)
// sub_00063880 (0x00063880, 18 bytes)

class Class_000618F0
{
public:
    bool sub_000618F0(bool a1);
};

extern "C" Class_000618F0 *__cdecl sub_000618E0();

// Passes the flag to the global object's setter.
void __cdecl sub_00063880(bool value)
{
    sub_000618E0()->sub_000618F0(value);
}
