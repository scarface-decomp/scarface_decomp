// bin: xb
// va: 0x002BF9C0
// what: Says whether one wide-character string starts with another.
// tool: Claude (from SPEC-016)

class XboxSaveDrive
{
public:
    bool sub_002BF9C0(const unsigned short* text, const unsigned short* prefix);
};

bool XboxSaveDrive::sub_002BF9C0(const unsigned short* text, const unsigned short* prefix)
{
    while (*prefix != 0)
    {
        if (*text == 0 || *text != *prefix)
        {
            return false;
        }
        prefix++;
        text++;
    }
    return true;
}
