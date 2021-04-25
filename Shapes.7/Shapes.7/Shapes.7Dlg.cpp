
// Shapes.7Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Shapes.7.h"
#include "Shapes.7Dlg.h"
#include "afxdialogex.h"
#include "pShapes.h" // from lab 11

#include <sstream> // for ostringstream
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CShapes7Dlg dialog



CShapes7Dlg::CShapes7Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHAPES7_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShapes7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CShapes7Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CShapes7Dlg::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CShapes7Dlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CShapes7Dlg message handlers

BOOL CShapes7Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	  // options for combo box
	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
	pCombo->InsertString(0, _T("Square"));
	pCombo->InsertString(1, _T("Cube"));
	pCombo->InsertString(2, _T("Rectangle"));
	pCombo->InsertString(3, _T("Box"));
	pCombo->InsertString(4, _T("Triangle"));
	pCombo->InsertString(5, _T("Prism"));
	pCombo->InsertString(6, _T("Circle"));
	pCombo->InsertString(7, _T("Cylinder"));
	pCombo->SetCurSel(-1); // or -1 for unselected

	CEdit* pEdit1 = (CEdit*)GetDlgItem(IDC_EDIT1);
	CEdit* pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
	CEdit* pEdit3 = (CEdit*)GetDlgItem(IDC_EDIT3);
	CEdit* pEdit4 = (CEdit*)GetDlgItem(IDC_EDIT4);
	CEdit* pEdit5sh = (CEdit*)GetDlgItem(IDC_OUTPUT5);
	CEdit* pEdit6sh = (CEdit*)GetDlgItem(IDC_OUTPUT6);
	CEdit* pEdit7sh = (CEdit*)GetDlgItem(IDC_OUTPUT7);
	CEdit* pEdit9sh = (CEdit*)GetDlgItem(IDC_RESULT9);

	// hide all input/output edit control when the app start
	pEdit1->ShowWindow(SW_HIDE);
	pEdit2->ShowWindow(SW_HIDE);
	pEdit3->ShowWindow(SW_HIDE);
	pEdit4->ShowWindow(SW_HIDE);
	pEdit5sh->ShowWindow(SW_HIDE);
	pEdit6sh->ShowWindow(SW_HIDE);
	pEdit7sh->ShowWindow(SW_HIDE);
	pEdit9sh->ShowWindow(SW_HIDE);

	// Picture control setup
	CStatic* pPicture = (CStatic*)GetDlgItem(IDC_STATIC);
	pPicture->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
	HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	pPicture->SetBitmap(hb);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShapes7Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CShapes7Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShapes7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CShapes7Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CEdit* pEdit4 = (CEdit*)GetDlgItem(IDC_EDIT4);
	CEdit* pEdit9sh = (CEdit*)GetDlgItem(IDC_RESULT9);
	CEdit* pEdit9 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_RESULT9));

	// show the output window when click calc
	pEdit9sh->ShowWindow(SW_SHOW);
	pEdit9->SetWindowText(CString(_T("Result:")));
	pEdit4->ShowWindow(SW_SHOW);

	// know which specific function should be called from combo box
	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int n = pCombo->GetCurSel(); // 0 for first item...

	// call the specific function when click calc
	if (n == 0) // Square
		calcSquare();
	if (n == 1) // Cube
		calcCube();
	if (n == 2) // Rectangle
		calcRectangle();
	if (n == 3) // Box
		calcBox();
	if (n == 4) // Triangle
		calcTriangle();
	if (n == 5) // Prism
		calcPrism();
	if (n == 6) // Circle
		calcCircle();
	if (n == 7) // Cylinder
		calcCylinder();
}


void CShapes7Dlg::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int n = pCombo->GetCurSel(); // 0 for first item...

	// for the output of labels
	CEdit* pEdit5 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_OUTPUT5));
	CEdit* pEdit6 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_OUTPUT6));
	CEdit* pEdit7 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_OUTPUT7));

	// labels
	string side = "Side:";
	string length = "Length:";
	string width = "Width:";
	string height = "Height:";
	string radius = "Radius:";

	CEdit* pEdit1 = (CEdit*)GetDlgItem(IDC_EDIT1);
	CEdit* pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
	CEdit* pEdit3 = (CEdit*)GetDlgItem(IDC_EDIT3);
	CEdit* pEdit4 = (CEdit*)GetDlgItem(IDC_EDIT4);
	CEdit* pEdit5sh = (CEdit*)GetDlgItem(IDC_OUTPUT5);
	CEdit* pEdit6sh = (CEdit*)GetDlgItem(IDC_OUTPUT6);
	CEdit* pEdit7sh = (CEdit*)GetDlgItem(IDC_OUTPUT7);

	if (n == 0) // Square
	{
		// show the input window
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_HIDE);
		pEdit3->ShowWindow(SW_HIDE);

		// show the label
		pEdit5sh->ShowWindow(SW_SHOW);
		pEdit6sh->ShowWindow(SW_HIDE);
		pEdit7sh->ShowWindow(SW_HIDE);
		pEdit5->SetWindowText(CString(side.c_str()));
	}

	if (n == 1) // Cube
	{
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_HIDE);
		pEdit3->ShowWindow(SW_HIDE);

		pEdit5sh->ShowWindow(SW_SHOW);
		pEdit6sh->ShowWindow(SW_HIDE);
		pEdit7sh->ShowWindow(SW_HIDE);
		pEdit5->SetWindowText(CString(side.c_str()));
	}

	if (n == 2) // Rectangle
	{
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_SHOW);
		pEdit3->ShowWindow(SW_HIDE);

		pEdit5sh->ShowWindow(SW_SHOW);
		pEdit6sh->ShowWindow(SW_SHOW);
		pEdit7sh->ShowWindow(SW_HIDE);
		pEdit5->SetWindowText(CString(length.c_str()));
		pEdit6->SetWindowText(CString(width.c_str()));
	}

	if (n == 3) // Box
	{
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_SHOW);
		pEdit3->ShowWindow(SW_SHOW);

		pEdit5sh->ShowWindow(SW_SHOW);
		pEdit6sh->ShowWindow(SW_SHOW);
		pEdit7sh->ShowWindow(SW_SHOW);
		pEdit5->SetWindowText(CString(length.c_str()));
		pEdit6->SetWindowText(CString(width.c_str()));
		pEdit7->SetWindowText(CString(height.c_str()));
	}

	if (n == 4) // Triangle
	{
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_HIDE);
		pEdit3->ShowWindow(SW_HIDE);

		pEdit5sh->ShowWindow(SW_SHOW);
		pEdit6sh->ShowWindow(SW_HIDE);
		pEdit7sh->ShowWindow(SW_HIDE);
		pEdit5->SetWindowText(CString(side.c_str()));
	}

	if (n == 5) // Prism
	{
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_SHOW);
		pEdit3->ShowWindow(SW_HIDE);

		pEdit5sh->ShowWindow(SW_SHOW);
		pEdit6sh->ShowWindow(SW_SHOW);
		pEdit7sh->ShowWindow(SW_HIDE);
		pEdit5->SetWindowText(CString(side.c_str()));
		pEdit6->SetWindowText(CString(height.c_str()));
	}

	if (n == 6) // Circle
	{
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_HIDE);
		pEdit3->ShowWindow(SW_HIDE);

		pEdit5sh->ShowWindow(SW_SHOW);
		pEdit6sh->ShowWindow(SW_HIDE);
		pEdit7sh->ShowWindow(SW_HIDE);
		pEdit5->SetWindowText(CString(radius.c_str()));
	}

	if (n == 7) // Cylinder
	{
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_SHOW);
		pEdit3->ShowWindow(SW_HIDE);

		pEdit5sh->ShowWindow(SW_SHOW);
		pEdit6sh->ShowWindow(SW_SHOW);
		pEdit7sh->ShowWindow(SW_HIDE);
		pEdit5->SetWindowText(CString(radius.c_str()));
		pEdit6->SetWindowText(CString(height.c_str()));
	}
}

void CShapes7Dlg::calcSquare()
{
	vector<string> tokens;
	CEdit* pEdit1 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));
	CEdit* pEdit4 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT4));
	CString mEdit1;
	pEdit1->GetWindowText(mEdit1);
	string s = CStringA(mEdit1);
	tokens.push_back("Square");
	tokens.push_back(s);
	stringstream sout;
	Square sq(tokens);
	sout << &sq;
	pEdit4->SetWindowText(CString(sout.str().c_str()));
}

void CShapes7Dlg::calcCube()
{
	vector<string> tokens;
	CEdit* pEdit1 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));
	CEdit* pEdit4 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT4));
	CString mEdit1;
	pEdit1->GetWindowText(mEdit1);
	string s = CStringA(mEdit1);
	tokens.push_back("Cube");
	tokens.push_back(s);
	stringstream sout;
	Cube cube(tokens);
	sout << &cube;
	pEdit4->SetWindowText(CString(sout.str().c_str()));
}

void CShapes7Dlg::calcRectangle()
{
	vector<string> tokens;
	CEdit* pEdit1 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));
	CEdit* pEdit2 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT2));
	CEdit* pEdit4 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT4));
	CString mEdit1, mEdit2;
	pEdit1->GetWindowText(mEdit1);
	pEdit2->GetWindowText(mEdit2);
	string l = CStringA(mEdit1);
	string w = CStringA(mEdit2);
	tokens.push_back("Rectangle");
	tokens.push_back(l);
	tokens.push_back(w);
	stringstream sout;
	comsc::Rectangle rec(tokens);
	sout << &rec;
	pEdit4->SetWindowText(CString(sout.str().c_str()));
}

void CShapes7Dlg::calcBox()
{
	vector<string> tokens;
	CEdit* pEdit1 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));
	CEdit* pEdit2 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT2));
	CEdit* pEdit3 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT3));
	CEdit* pEdit4 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT4));
	CString mEdit1, mEdit2, mEdit3;
	pEdit1->GetWindowText(mEdit1);
	pEdit2->GetWindowText(mEdit2);
	pEdit3->GetWindowText(mEdit3);
	string l = CStringA(mEdit1);
	string w = CStringA(mEdit2);
	string h = CStringA(mEdit3);
	tokens.push_back("Box");
	tokens.push_back(l);
	tokens.push_back(w);
	tokens.push_back(h);
	stringstream sout;
	Box box(tokens);
	sout << &box;
	pEdit4->SetWindowText(CString(sout.str().c_str()));
}

void CShapes7Dlg::calcTriangle()
{
	vector<string> tokens;
	CEdit* pEdit1 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));
	CEdit* pEdit4 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT4));
	CString mEdit1;
	pEdit1->GetWindowText(mEdit1);

	string s = CStringA(mEdit1);
	tokens.push_back("Triangle");
	tokens.push_back(s);
	stringstream sout;
	Triangle tri(tokens);
	sout << &tri;
	pEdit4->SetWindowText(CString(sout.str().c_str()));
}

void CShapes7Dlg::calcPrism()
{
	vector<string> tokens;
	CEdit* pEdit1 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));
	CEdit* pEdit2 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT2));
	CEdit* pEdit4 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT4));
	CString mEdit1, mEdit2;
	pEdit1->GetWindowText(mEdit1);
	pEdit2->GetWindowText(mEdit2);
	string s = CStringA(mEdit1);
	string h = CStringA(mEdit2);
	tokens.push_back("Prism");
	tokens.push_back(s);
	tokens.push_back(h);
	stringstream sout;
	Prism pri(tokens);
	sout << &pri;
	pEdit4->SetWindowText(CString(sout.str().c_str()));
}

void CShapes7Dlg::calcCircle()
{
	vector<string> tokens;
	CEdit* pEdit1 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));
	CEdit* pEdit4 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT4));
	CString mEdit1;
	pEdit1->GetWindowText(mEdit1);
	string r = CStringA(mEdit1);
	tokens.push_back("Circle");
	tokens.push_back(r);
	stringstream sout;
	Circle cir(tokens);
	sout << &cir;
	pEdit4->SetWindowText(CString(sout.str().c_str()));
}

void CShapes7Dlg::calcCylinder()
{
	vector<string> tokens;
	CEdit* pEdit1 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));
	CEdit* pEdit2 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT2));
	CEdit* pEdit4 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT4));
	CString mEdit1, mEdit2;
	pEdit1->GetWindowText(mEdit1);
	pEdit2->GetWindowText(mEdit2);
	string r = CStringA(mEdit1);
	string h = CStringA(mEdit2);
	tokens.push_back("Prism");
	tokens.push_back(r);
	tokens.push_back(h);
	stringstream sout;
	Cylinder cyl(tokens);
	sout << &cyl;
	pEdit4->SetWindowText(CString(sout.str().c_str()));
}
