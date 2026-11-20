// bin: xb
// va: 0x00025400
// what: Runs a destructor on every element of an array, last to first (compiler helper "vector destructor iterator").
// tool: Claude Opus 5.5
// verify: python portal/verify.py reports/to_submit/xb_00025400.cpp --va 0x00025400 --bin xb --match '??_I' --flags "/O2 /Ot /Oy /G6 /Gd /GR /Zp4"

// ??_I (`vector destructor iterator') has no source of its own: cl writes it into a file that
// destroys an array of a class with a destructor. With /EHsc cl uses the exception-aware
// iterator instead, so the game's copy came from a file built without /EHsc (see the verify line).
// The array below is the declaration that needs it; which class it was is not known.
class Class_00025400
{
public:
    ~Class_00025400();

    int m_Field00;
};

Class_00025400 g_00025400[4];
