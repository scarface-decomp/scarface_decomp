// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PS2 SLUS_211.11, engine/AirplaneObject.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 64 functions matched (4.69%). NOT COMPLETE YET.
// The 61 still to do are listed in their place in Original_Binary_Order_PS2.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Metrowerks CodeWarrior for PS2 3.0.1 (decomp.me: mwcps2-3.0.1b103-040528, -O3 -lang c++ -str readonly).
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AirplaneObject::vfunc_44 (0x003BB860, 8 B)
// By: RRutherfordd (Founder) | Flags: -O3 -lang c++ -str readonly
// ============================================================================
// Stores its argument as a float at +0xD0 of its object.
class Object
{
public:
    void Set(float value);
    char m_pad00[0xD0];
    float m_FieldD0; // +0xD0
};

void Object::Set(float value)
{
    m_FieldD0 = value;
}

// ============================================================================
// [VERIFIED] AirplaneObject::vfunc_45 (0x003BB870, 8 B)
// By: RRutherfordd (Founder) | Flags: -O3 -lang c++ -str readonly
// ============================================================================
// Returns the float at +0xD0 of its object.
class Object
{
public:
    float Get();
    char m_pad00[0xD0];
    float m_FieldD0; // +0xD0
};

float Object::Get()
{
    return m_FieldD0;
}

// ============================================================================
// [VERIFIED] AirplaneObject::vfunc_74 (0x003BCEC0, 8 B)
// By: RRutherfordd (Founder) | Flags: -O3 -lang c++ -str readonly
// ============================================================================
// Returns 0.
int Zero()
{
    return 0;
}

