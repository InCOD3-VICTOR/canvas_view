#pragma once
#include "jsoncpp/json.h"
#include "tools_types.h"

class MainCanvas;

class ToolBase
{
public:
    ToolBase();
    virtual ~ToolBase();

    void SetToolsType(ToolTypes type);

    ToolTypes GetToolsType();

    std::string GetControlUuid();

    void SetControlUuid(std::string uuid);
    
public:
    //��Ԫ����Ϣת����json��
    virtual Json::Value Marshal();

    virtual bool UnMarshal(Json::Value &tool);

    //����Ԫ���ƶ���ƫ����
    virtual void SetToolsOffset(int offsetx, int offsety){}
    
    //����Ԫ�صĲ���ֵ(��Թ���������ֵ)
    virtual void SetOffsetY(int basey) = 0;

    //����Ԫ�ص����ű���
    virtual void SetToolsScale(float scale) = 0;

    //���ݵ����Ԫ���Ƿ�ѡ��
    //-1 δѡ��
    // 0    1    2
    // 3    4    5
    // 6    7    8
    virtual int ToolHitTest(POINT pt) = 0;
    
    //����Ԫ�ص�ѡ��״̬(����ѡ��״̬)
    virtual void SetToolsState(ToolsStats status) = 0;
    
    //�õ�Ԫ���Ƿ��ѡ��
    virtual ToolsStats GetToolsState(){ return tools_status_; }

    //���û���/�������ɫ
    virtual void SetPenColor(DWORD pen_color);
    
    //���û���/����Ĵ�С
    virtual void SetPenSize(int pen_size);

    RECT DisplayToWorld(RECT rt);
    RECT WorldToDisplay(RECT rt);

    RECT GetDisplay();

    virtual void SetPosition(RECT rt) {};

protected:

    // Ԫ�ص�uuid
    std::string control_uuid_;

    //Ԫ�ص����ű�
    float scale_;
 
    //��Ļӳ���������Сֵ
    int  base_y_;

    int offset_y_;

    int left_;
    int top_;
    int right_;
    int bottom_;

    //��������
    RECT world_rect_;

    //��ɫ
    DWORD pen_color_;

    //���ʵĴ�С����������Ĵ�С
    int pen_size_;

    //Ԫ�ص�״̬
    ToolsStats tools_status_;

    //Ԫ�ص�����
    ToolTypes type_;
    
};