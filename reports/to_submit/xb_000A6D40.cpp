// bin: xb
// va: 0x000A6D40
// what: Builds an object of thirty values, all set to zero.
// tool: Claude Opus 5.5 (symcov hint: EARS::SaveGame::MemcardHandler::PlatformMessages::PlatformMessages)
// sub_000A6D40 (0x000A6D40, 96 bytes)

class Class_000A6D40
{
public:
    Class_000A6D40 *sub_000A6D40();

    int m_Field00[30]; // +0x00
};

// Clears every value and returns the object.
Class_000A6D40 *Class_000A6D40::sub_000A6D40()
{
    for (int i = 0; i < 30; i++)
    {
        m_Field00[i] = 0;
    }
    return this;
}
