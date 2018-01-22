// PreWorkDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "OpenCV.h"
#include "PreWork.h"
#include "PreWorkDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

Pre_OpenCV Pre_Exp;
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CPreWorkDlg 对话框



CPreWorkDlg::CPreWorkDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PREWORK_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CPreWorkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MIN, m_min);
	DDX_Control(pDX, IDC_CLOSE, m_close);
	DDX_Control(pDX, IDC_CutVideo, m_transform);
}

BEGIN_MESSAGE_MAP(CPreWorkDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CPreWorkDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CutVideo, &CPreWorkDlg::OnBnClickedCutvideo)
	ON_EN_CHANGE(IDC_OpenFile, &CPreWorkDlg::OnEnChangeOpenfile)
	ON_BN_CLICKED(IDC_CUTMAT, &CPreWorkDlg::OnBnClickedCutmat)
	ON_EN_CHANGE(IDC_ROW, &CPreWorkDlg::OnEnChangeRow)
	ON_EN_CHANGE(IDC_COLUMN, &CPreWorkDlg::OnEnChangeColumn)
	ON_WM_CTLCOLOR()
	ON_WM_NCHITTEST()
	ON_BN_CLICKED(IDCANCEL, &CPreWorkDlg::OnBnClickedCancel)
	ON_STN_CLICKED(IDC_CLOSE, &CPreWorkDlg::OnStnClickedClose)
	ON_STN_CLICKED(IDC_MIN, &CPreWorkDlg::OnStnClickedMin)
	ON_EN_CHANGE(IDC_OpenFile2, &CPreWorkDlg::OnEnChangeOpenfile2)
END_MESSAGE_MAP()


// CPreWorkDlg 消息处理程序

BOOL CPreWorkDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。
	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	newFont_1.CreatePointFont(160,"微软雅黑");
	newFont_2.CreatePointFont(100, "微软雅黑");
	m_min.SetFont(&newFont_1);
	m_close.SetFont(&newFont_2);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CPreWorkDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CPreWorkDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//CDialogEx::OnPaint();
		CRect   rect;
		CPaintDC   dc(this);
		GetClientRect(rect);
		dc.FillSolidRect(rect, RGB(217, 226, 241));
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CPreWorkDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPreWorkDlg::OnBnClickedButton1()
{
	BOOL isOpen = TRUE;     //是否打开(否则为保存)  
	CString defaultDir = "";   //默认打开的文件路径
	CString m_filename;
	CString filter = "文件 (*.avi; *.mp4; *.mov)|*.avi;*.mov;*.mp4||";   //文件过虑的类型
	CFileDialog dlg(isOpen, defaultDir, m_filename, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);    //用于打开指定avi文件
	if (dlg.DoModal() == IDOK){
		m_filename = dlg.GetPathName();
	}
	SetDlgItemText(IDC_OpenFile,m_filename);
}

void CPreWorkDlg::OnBnClickedCutvideo()
{
	CvCapture* pCapture = NULL;
	CString   strPath;
	CString outfilename;
	int nFrmNum = 0;
	CString m_filename_edit;
	if (nFrmNum == 0) {  //第一次保存时选择要保存到的文件夹{
		BROWSEINFO bi = { 0 };
		char pszDisplayName[MAX_PATH] = "\0";
		bi.hwndOwner = NULL;
		bi.pszDisplayName = pszDisplayName;
		bi.lpszTitle = "请选择目录:";
		bi.ulFlags = BIF_RETURNONLYFSDIRS;
		LPITEMIDLIST lpIL = SHBrowseForFolder(&bi);
		if (lpIL) {
			SHGetPathFromIDList(lpIL, bi.pszDisplayName);
		}
		else {
			strPath = "";
		}
		strPath = bi.pszDisplayName;
		SetDlgItemText(IDC_OpenFile2, strPath);
	}
	GetDlgItem(IDC_OpenFile)->GetWindowText(m_filename_edit);
	pCapture = cvCaptureFromAVI(m_filename_edit);     //  用来指定视频文件  pCapture为 CvCapture* pCapture;
	if (pCapture == NULL)
		MessageBox("AVI视频打开失败或格式不对", "错误提示", IDOK);
	for (; ; ){
		IplImage* frame = NULL;
		frame = cvQueryFrame(pCapture);   //  cvQueryFrame( pCapture ) 用来提取指定视频中的每一帧
		if (!frame)           //视频的尾部 则退出
			break;
		cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 1);      //创建存储每一帧的内存缓存, 为后面保存图片之用
		outfilename.Format("%s//%d.jpg", strPath, nFrmNum);  //因为提取的视频很多帧, 实现动态保存名字,好自动保存每一帧.
		if (!cvSaveImage(outfilename, frame)){        //cvSaveImage(outfilename,frame)    //把帧图像frame保存为用户名outfilename
			MessageBox("文件无法保存到相应路径", "保存错误", IDOK);
			break;
		}
		nFrmNum = nFrmNum + 1;
	}
	cvReleaseCapture(&pCapture);
}


void CPreWorkDlg::OnEnChangeOpenfile()
{
}


void CPreWorkDlg::OnBnClickedCutmat()
{
	//与接收需处理行列分割情况
	CString m_rowstring, m_columnstring;
	GetDlgItem(IDC_ROW)->GetWindowText(m_rowstring);
	GetDlgItem(IDC_ROW)->GetWindowText(m_columnstring);
	int m_row = atoi(m_rowstring);
	int m_column = atoi(m_columnstring);
	int k = m_row*m_column;
	int o = 1;

	CvCapture* pCapture = NULL;
	CString   strPath;
	CString outfilename;
	CString infilename;
	CString m_filename_edit;
	CString m_outfile_start;
	CString create_file;
	GetDlgItem(IDC_OpenFile)->GetWindowText(m_filename_edit);
	GetDlgItem(IDC_OpenFile2)->GetWindowText(m_outfile_start);
	pCapture = cvCaptureFromAVI(m_filename_edit);     //  用来指定视频文件  pCapture为 CvCapture* pCapture;
	int video_width = (int)cvGetCaptureProperty(pCapture, CV_CAP_PROP_FRAME_WIDTH);
	int video_height = (int)cvGetCaptureProperty(pCapture, CV_CAP_PROP_FRAME_HEIGHT);
	int numFrames = (int)cvGetCaptureProperty(pCapture, CV_CAP_PROP_FRAME_COUNT);
	int block_width = video_width / m_column;
	int block_height = video_height / m_row;
	int Num = 0;
	cvReleaseCapture(&pCapture);

	int p, q;
	IplImage* frame = NULL;
	//frame = cvLoadImage("D:/Out/1/0.jpg", -1);
	cvCreateImage(cvSize(block_width, block_height), IPL_DEPTH_8U, 1);
	if (Num == 0)  //选择要保存到的文件夹
	{
		BROWSEINFO bi = { 0 };
		char pszDisplayName[MAX_PATH] = "\0";
		bi.hwndOwner = NULL;
		bi.pszDisplayName = pszDisplayName;
		bi.lpszTitle = "请选择目录:";
		bi.ulFlags = BIF_RETURNONLYFSDIRS;
		LPITEMIDLIST lpIL = SHBrowseForFolder(&bi);
		if (lpIL)
		{
			SHGetPathFromIDList(lpIL, bi.pszDisplayName);
		}
		else
		{
			strPath = "";
		}
		strPath = bi.pszDisplayName;
	}
	int rect_1;
	int rect_2;
	int rect_3;
	int rect_4;
	int a = 0;
	while (o <= k) {
		create_file.Format("%s/%d", strPath, o);
		CreateDirectory(create_file, 0);
		o++;
	}
	while (a < numFrames) {
		infilename.Format("%s/%d.jpg", m_outfile_start, a);
		p = q = 0; o = 1;
		k = m_row*m_column;
		while (o <=k ) {
			if (q == m_column) {
				q = 0;
				p++;
			}
			rect_1 = block_width*q;
			rect_2 = block_height*p;
			rect_3 = block_width;
			rect_4 = block_height;
			frame = cvLoadImage(infilename, -1);
			cv::Mat m = cv::cvarrToMat(frame);
			cv::Rect rect(rect_1, rect_2, rect_3, rect_4);
			cv::Mat image_frame = cv::Mat(m, rect);
			cv::Mat image_copy = image_frame.clone();
			frame = &IplImage(image_copy);
			outfilename.Format("%s/%d//%d_%d_%d.jpg", strPath, o, a, p + 1, q + 1); //实现动态保存名字
			if (!cvSaveImage(outfilename, frame)) {        //把帧图像frame保存为用户名outfilename
				MessageBox("文件无法保存到相应路径", "保存错误", IDOK);
			}
			q++;
			o++;
		}
		a++;
	}
}

void CPreWorkDlg::OnEnChangeRow()
{
}


void CPreWorkDlg::OnEnChangeColumn()
{
}

HBRUSH CPreWorkDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (nCtlColor == CTLCOLOR_BTN)          //更改按钮颜色  
	{
		//pDC->SetBkMode(TRANSPARENT);  
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->SetBkColor(RGB(1, 121, 255));
		HBRUSH b = CreateSolidBrush(RGB(121, 121, 255));
		return b;
	}
	else if (nCtlColor == CTLCOLOR_SCROLLBAR)  //  
	{
		//pDC->SetBkMode(TRANSPARENT);  
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->SetBkColor(RGB(233, 233, 220));
		HBRUSH b = CreateSolidBrush(RGB(233, 233, 220));
		return b;
	}
	else if (nCtlColor == CTLCOLOR_EDIT)   //更改编辑框  
	{
		//pDC->SetBkMode(TRANSPARENT);  
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->SetBkColor(RGB(246, 246, 246));
		HBRUSH b = CreateSolidBrush(RGB(246, 246, 246));
		return b;
	}
	else if (nCtlColor == CTLCOLOR_STATIC)  //更改静态文本  
	{
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->SetBkColor(RGB(217, 226, 241));
		HBRUSH b = CreateSolidBrush(RGB(217, 226, 241));
		return b;
	}
	else if (nCtlColor == CTLCOLOR_DLG)   //更改对话框背景色  
	{
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->SetBkColor(RGB(166, 254, 1));
		HBRUSH b = CreateSolidBrush(RGB(213, 226, 240));
		return b;
	}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔  
	return hbr;
}


LRESULT CPreWorkDlg::OnNcHitTest(CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	LRESULT ret = CDialogEx::OnNcHitTest(point);
	return (ret == HTCLIENT) ? HTCAPTION : ret;
}


void CPreWorkDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CPreWorkDlg::OnStnClickedClose()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CPreWorkDlg::OnStnClickedMin()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::ShowWindow(SW_FORCEMINIMIZE);
}


void CPreWorkDlg::OnEnChangeOpenfile2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
}
