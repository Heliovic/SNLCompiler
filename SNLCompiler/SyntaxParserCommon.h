#pragma once

enum LogType
{
	LERROR,
	LINFO,
	LDEBUG
};

// ��������
enum NodeType
{
	Program,		// Program ��־�飬����������飬�൱�ڿ�ʼ��
	ProgramHead,		// Program Head ��־�飬���� program bubble
	ProgramName,
	ProgramBody,
	StmList,
	Stm,
	StmMore,
	DeclarePart,
	TypeDec,		// Type Declare ��־�飬��������
	//EMPTY,
	TypeDecList,
	TypeId,
	TypeDef,
	TypeDecMore,
	TypeDeclaration,
	BaseType,
	StructureType,
	ArrayType,
	RecType,
	FieldDecList,
	IdList,
	FieldDecMore,
	IdMore,
	VarDec,		// Var Declare ��־�飬��������
	VarDeclaration,
	VarDecList,
	VarIdList,
	VarIdMore,
	VarDecMore,
	ProcDec,
	ProcDeclaration,
	ProcDecMore,
	ParamList,
	ParamDecList,
	Param,
	ParamMore,
	FormList,
	FidMore,
	ProcDecPart,
	ProcBody,
	AssCall,
	AssignmentRest,
	ConditionalStm,
	LoopStm,
	InputStm,
	OutputStm,
	ReturnStm,
	CallStmRest,
	ActParamList,
	ActParamMore,
	Exp,
	OtherTerm,
	Term,
	OtherFactor,
	Factor,
	Variable,
	VariMore,
	FieldVar,
	FieldVarMore,
	RelExp,
	OtherRelE,
	CmpOp,
	AddOp,
	MultOp,
	Terminal	// �ռ���
};

struct ParseLog
{
	ParseLog(int li, LogType t, CString lg) : line(li), type(t), log(lg) {}
	int line;
	LogType type;
	CString log;
};
