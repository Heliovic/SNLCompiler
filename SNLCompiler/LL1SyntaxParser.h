#pragma once

#include <vector>
#include <map>
#include <set>
#include "SyntaxParserCommon.h"
#include "LexicalAnalyzer.h"

#define STR_EPS CString(_T("<EPSILON>"))
#define EPS_ITEM SyntaxItem(LexType::EPSILON)
#define PRODUCTION_FILENAME _T("../TestCase/SNL_Core/syntax_list.txt")

using namespace std;

class LL1TreeNode
{
public:
	LL1TreeNode()
	{
		//mSemName = _T("");
		mLine = -1;
		mNodeType = NodeType::Terminal;
		mChilds = vector<LL1TreeNode*>();
	}
	vector<LL1TreeNode*> mChilds;
	int mLine;
	NodeType mNodeType;
	Token mToken;
};

struct SyntaxItem
{
	SyntaxItem() 
	{
		nodeType = NodeType::Terminal;
		token = LexType::LEXERR;
	}
	SyntaxItem(NodeType n)
	{
		nodeType = n;
		token = LexType::LEXERR;
	}
	SyntaxItem(LexType t)
	{
		nodeType = NodeType::Terminal;
		token = t;
	}
	SyntaxItem(NodeType n, LexType t): nodeType(n), token(t){}
	bool operator < (const SyntaxItem& item) const
	{
		// ɢ�к���
		return nodeType * 100000 + token < item.nodeType * 100000 + item.token;
	}
	NodeType nodeType;
	LexType token;	// ��nodeTypeΪTerminal���ռ�����ʱ������Ч�����򣬸���ӦΪLEXERR
	void SetNodeType(NodeType n) { nodeType = n; token = LexType::LEXERR; }
	void SetLexType(LexType t) { nodeType = Terminal; token = t; }
};

struct Production
{
	SyntaxItem mLeft;
	int no;
	vector<SyntaxItem> mRights;
};

class LL1SyntaxParser
{
public:
	LL1SyntaxParser();
	LL1SyntaxParser(vector<Token> tokens);
	~LL1SyntaxParser();

	void NextToken();
	Token GetCurToken();

	void InitMap();
	CString GetSyntaxTreeStr(CString lftstr, CString append, LL1TreeNode* r);
	void ReleaseTree(LL1TreeNode* r);
	void ReadProuctions();
	vector<CString> SplitString(CString str, CString pattern);		// ��ȡ����ʽ�ļ�ʱ���ڷִ�

	set<SyntaxItem> GetSyntaxListFirst(vector<SyntaxItem> items);
	void GetFirstSet();
	void GetFollowSet();
	void GetPredictSet();

	void Parse();	// LL1 ��������

	int mTokenPtr;
	int mCurLine;
	LL1TreeNode* mSyntaxTree;

	LexicalAnalyzer mLexicalAnalyzer;
	vector<Token> mTokenList;

	vector<ParseLog> mParseLog;
	map<NodeType, CString> mNodeType2Str;
	map<CString, NodeType> mStr2NodeType;

	set<SyntaxItem> mNonTerminals;		// ���ռ���
	set<SyntaxItem> mTerminals;			// �ռ���
	SyntaxItem mBeginSyntax;

	vector<Production> mProductions;							// ����ʽ
	map<int, vector<SyntaxItem>> mId2Rights;					// ���ݲ���ʽ id ��Ż�ȡ����ʽ�Ҳ�
	map<NodeType, map<LexType, vector<SyntaxItem>>> mLL1Map;	// LL1 ״̬ת����

	map<SyntaxItem, set<SyntaxItem>> mFirstSet;		// First ��
	map<SyntaxItem, set<SyntaxItem>> mFollowSet;	// Follow ��
	map<int, set<SyntaxItem>> mPredictSet;			// Predict ��
};

