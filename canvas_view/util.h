#pragma once

std::string GenUUID();

long MapFun_Point2Line(POINT pt1, POINT pt2, POINT pnt, POINT &sp, double *hdist);

bool MapFun_Point2Rect(RECT rect, POINT pt, int ignore);

//�õ�ͼ����ָ����Χ�ڵ�ʵ�ʴ�С
bool GetImageSize(wstring filepath, int &width, int &height);

bool GetTextRectSize(RECT &rect, std::wstring text, HFONT hFontSrc, HDC hDC, DWORD color, int size=-1);




/**	@fn	UnicodeToAnsi
*	@brief	UnicodeתAnsi
*	@param strSrc Unicode�����ʽ��Դ�ַ���
*	@return	 ת����Ansi�ַ���
*/
std::string UnicodeToAnsi(const WCHAR* strSrc);

/**	@fn	AnsiToUnicode
*	@brief	AnsiתUnicode
*	@param strSrc Ansi�����ʽ��Դ�ַ���
*	@return	 ת����Unicode�ַ���
*/
std::wstring AnsiToUnicode(const char* strSrc);

/**	@fn	UnicodeToUTF8
*	@brief	UnicodeתUTF8
*	@param strSrc Unicode�����ʽ��Դ�ַ���
*	@return	 ת����UTF8�ַ���
*/
std::string UnicodeToUTF8(const WCHAR* strSrc);

/**	@fn	UTF8ToUnicode
*	@brief	UTF8תUnicode
*	@param strSrc UTF8�����ʽ��Դ�ַ���
*	@return	 ת����Unicode�ַ���
*/
std::wstring UTF8ToUnicode(const char* strSrc);

/**@fn	UTF8ToAnsi
*	@brief 	UTF8תAnsi
*	@param strSrc UTF8�����ʽ��Դ�ַ���
*	@return	 ת����UTF8�ַ���
*/
std::string UTF8ToAnsi(const char* strSrc);


/**@fn	AnsiToUTF8
*	@brief 	AnsiתUTF8
*	@param strSrc Ansi�����ʽ��Դ�ַ���
*	@return	 ת����UTF8�ַ���
*/
std::string AnsiToUTF8(const char* strSrc);


std::vector<std::string> Split(std::string src, const char* str);
std::vector<std::wstring> Splitw(std::wstring src, std::wstring str);

//
DWORD StrColorToDword(std::string color );

void MeasureStringExtended(RECT &rect, std::wstring text, HFONT hFontSrc, HDC hDC,
    DWORD color, int size, int desWidth);

