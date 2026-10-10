#pragma once
#include "afxdialogex.h"
#include "resource.h"		// メイン シンボル


// CDialogError ダイアログ

class CDialogError : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogError)

public:
	CDialogError(CWnd* pParent = nullptr);   // 標準コンストラクター
	virtual ~CDialogError();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_TEST_ERROR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOriginal();
	afx_msg void OnBnClickedCancelOriginal();
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	virtual BOOL OnDestroy();

	int show();
	//bool show(CWnd *pParent);

private:
	ULONG_PTR m_gdiplusToken = 0;
};
