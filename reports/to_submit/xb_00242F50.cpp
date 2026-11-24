// bin: xb
// va: 0x00242F50
// what: Passes this object to sub_00284950 on the given target object.
// tool: Gemini 4 Neon

struct Target_00242F50
{
    void sub_00284950(void* arg);
};

class Class_00242F50
{
public:
    void sub_00242F50(Target_00242F50* target);
};

void Class_00242F50::sub_00242F50(Target_00242F50* target)
{
    target->sub_00284950(this);
}
