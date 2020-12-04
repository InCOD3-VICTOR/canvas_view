#pragma once
#include "tools_types.h"

#if defined(_MSC_VER)
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif
#include <string>

class EXPORT CanvasView
{
public:
    //�ص��������Ľӿ�
    class Delegate
    {
    public:
        //�ؼ��ĸ��� ��� ɾ�� �ƶ��Ȳ���
        virtual void OnControlChange(ChangeType type,const char *context) {};

        virtual void OnAddImage(const char*url, const char *context) {};

        //������ӵıʼ����ݸ�������������
        virtual void SendPenPath(InnerPenInfo &penInfo) {};

        //����Լ������¼��Ļش�
        virtual void OnMouseKeyMessage(unsigned int uMsg, unsigned int wParam,long lParam) {};

        virtual void OnMouseWheelMessage(unsigned int uMsg, unsigned int wParam, long lParam) {};

        virtual ~Delegate(){}

    };

    //�����������õĽӿ���
public: 
    virtual ~CanvasView(){}

    virtual void SetPenColor(DWORD color) = 0;

    virtual void SetPenSize( int pen_size ) = 0;

    //����ѡ��Ĺ���
    virtual void SelectTools(ToolTypes tool_type) = 0;

    //��������
    virtual bool CreateCanvas(int width, int height) = 0;

    //��������ӳ�䷶Χ 
    virtual void ResetCanvas(int width, int height) = 0;

    //���û����λ��
    virtual bool SetCanvasViewPos(int x, int y, int width, int height) = 0;

    virtual long GetCanvasViewHwnd() = 0;
    
    virtual void PageTo(int page) = 0;

    //��������ƫ����  scroll  true ����������� false ��ҳ�����
    virtual void SetOffset(int offsety, bool scroll=true) = 0;

    virtual void AddImage(char *url, char *filepath,char *info) = 0;

    virtual void Hide() = 0;
    virtual void Show() = 0;

    virtual void UnMarshal(std::string grapics_data) = 0;
    virtual std::string Marshal() = 0;

    virtual void ChangeControls(ChangeType type, std::string change_infos) = 0;

    virtual void SetEditable(bool enable) = 0;

};

EXPORT CanvasView* CreateCanvasView(void* hwnd = nullptr, CanvasView::Delegate* delegate = nullptr);
EXPORT void DestroyCanvasView(CanvasView* screen_shot);



