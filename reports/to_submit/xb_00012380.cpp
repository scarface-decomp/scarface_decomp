// bin: xb
// va: 0x00012380
// what: Runs a constructor on every element of an array, first to last (compiler helper "vector constructor iterator").
// tool: Claude Opus 5.5
// verify: python portal/verify.py reports/to_submit/xb_00012380.cpp --va 0x00012380 --bin xb --match '??_H'

// ??_H (`vector constructor iterator') has no source of its own: cl writes it into any file that
// builds an array of a class with a constructor and no destructor. The array below is that
// declaration; which class and array the game's copy came from is not known.
class Class_00012380
{
public:
    Class_00012380();

    int m_Field00;
};

Class_00012380 g_00012380[4];
