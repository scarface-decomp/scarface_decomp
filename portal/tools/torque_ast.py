"""TorqueScript syntax tree for Scarface's scripts, shaped like the Torque compiler's own nodes
(astNodes.cc), so that compiling it reproduces the game's bytecode exactly."""
from __future__ import annotations

from dataclasses import dataclass, field
from typing import List, Optional

UINT, FLT, STR, NONE = "uint", "flt", "str", "none"


class Node:
    pass


# ----------------------------------------------------------------------------- expressions
@dataclass
class IntConst(Node):
    value: int


@dataclass
class FloatConst(Node):
    raw: bytes            # the 4 bytes in the float table (single precision)
    text: str = ""        # how it is written in the script; parsed as a double, then stored as f32


@dataclass
class StrConst(Node):
    value: str
    tag: bool = False


@dataclass
class Ident(Node):        # a bare word used as a value (Torque's ConstantNode)
    name: str


@dataclass
class Var(Node):
    name: str
    local: bool
    index: Optional[Node] = None


@dataclass
class Assign(Node):
    var: Var
    expr: Node


@dataclass
class AssignOp(Node):
    var: Var
    op: str               # + - * / % & ^ | << >>
    expr: Node


@dataclass
class FloatBinary(Node):
    op: str               # + - * /
    left: Node
    right: Node


@dataclass
class IntBinary(Node):
    op: str               # == != < > <= >= % & | ^ << >> && ||
    left: Node
    right: Node


@dataclass
class StrEq(Node):
    left: Node
    right: Node
    eq: bool = True


@dataclass
class StrCat(Node):
    left: Node
    right: Node
    char: Optional[str] = None     # None: @, " ": SPC, "\t": TAB, "\n": NL


@dataclass
class CommaCat(Node):
    left: Node
    right: Node


@dataclass
class IntUnary(Node):
    op: str               # ! ~
    expr: Node


@dataclass
class FloatUnary(Node):   # unary minus
    expr: Node


@dataclass
class Conditional(Node):
    test: Node
    true: Node
    false: Node


@dataclass
class Call(Node):
    name: str
    ns: Optional[str]
    args: List[Node]
    call_type: int        # 0 function, 1 method (args[0] is the object), 2 Parent::


@dataclass
class SlotAccess(Node):
    obj: Node
    slot: str
    index: Optional[Node] = None


@dataclass
class SlotAssign(Node):
    obj: Optional[Node]   # None inside an object declaration
    slot: str
    index: Optional[Node]
    value: Node


@dataclass
class SlotAssignOp(Node):
    obj: Node
    slot: str
    index: Optional[Node]
    op: str
    value: Node


@dataclass
class ObjectDecl(Node):
    class_expr: Node
    name_expr: Node
    parent: Optional[str]
    datablock: bool
    args: List[Node] = field(default_factory=list)
    slots: List[SlotAssign] = field(default_factory=list)
    subs: List["ObjectDecl"] = field(default_factory=list)


# ----------------------------------------------------------------------------- statements
@dataclass
class ExprStmt:
    expr: Node


@dataclass
class Return:
    expr: Optional[Node] = None


@dataclass
class If:
    test: Node
    then: list
    else_: Optional[list] = None


@dataclass
class Loop:
    init: Optional[Node]
    test: Node
    body: list
    end: Optional[Node]
    is_do: bool = False


@dataclass
class Break:
    pass


@dataclass
class Continue:
    pass


@dataclass
class FuncDecl:
    name: str
    ns: Optional[str]
    package: Optional[str]
    args: List[str]
    body: Optional[list]          # None: declared without statements (has-body flag 0)


# ----------------------------------------------------------------------------- types
def pref(n: Node) -> str:
    """Torque's getPreferredType()."""
    if isinstance(n, IntConst):
        return UINT
    if isinstance(n, FloatConst):
        return FLT
    if isinstance(n, (StrConst, Ident, StrCat, CommaCat, Call, SlotAssign)):
        return STR
    if isinstance(n, (Var, SlotAccess)):
        return NONE
    if isinstance(n, Assign):
        return pref(n.expr)
    if isinstance(n, (AssignOp, SlotAssignOp)):
        return assign_op_type(n.op)
    if isinstance(n, FloatBinary) or isinstance(n, FloatUnary):
        return FLT
    if isinstance(n, (IntBinary, StrEq, IntUnary, ObjectDecl)):
        return UINT
    if isinstance(n, Conditional):
        return pref(n.true)
    raise TypeError(type(n).__name__)


def assign_op_type(op: str) -> str:
    return FLT if op in ("+", "-", "*", "/") else UINT
