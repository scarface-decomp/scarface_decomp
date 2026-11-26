// bin: xb
// va: 0x002BF730
// what: Gives the size a save takes on the memory unit: its data, a 4-byte header and one 20-byte signature for each block.
// tool: Claude (from SPEC-016)

const unsigned int BLOCK_DATA = 0x2000 - 20;     // a block less its signature

unsigned int __cdecl sub_002BF730(unsigned int size)
{
    return size + 4 + 20 * ((size + 4 + BLOCK_DATA - 1) / BLOCK_DATA);
}
