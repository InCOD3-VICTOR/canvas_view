#pragma once
#include <map>
#include <list>
#include "tools_types.h"
#include <tools/pencile_tool.h>
#include <tools/pen_icon_tool.h>
#include <tools/image_tool.h>

using namespace DuiLib;


//typedef map<std::string, CControlUI*> ControlListType;

//typedef std::map<int, std::map<int, CControlUI*>> ControlListType;

//typedef std::map<int, std::list<CControlUI*>> ControlListType;

typedef std::list<CControlUI*> ControlListType;
typedef std::map<int, Json::Value> PageListType;


class ToolsManager
{
public:
    ToolsManager();
    ~ToolsManager();

    void Add(CControlUI* control, bool is_new = true);
    void Remove(CControlUI* control);
    CControlUI* Get(std::string uuid);
    std::string GetUUID(CControlUI* control);
    ControlListType current_page_controls_list_;
 
public: //��Ļ��ӳ��

    int   offset_y_;  //����ƫ����
    float scale_;     //���ű���
    int page_id_;

    /* ��������ƫ����*/
    bool SetOffsetY(int offset,bool scroll);
    void SetScale(double scale);
    void PageTo(int page);
    int GetOffset();

    /*ָ���ռ����ӳ��
      flag  true   ����������ӳ�����Ļ���� 
            false  ����Ļ����ӳ�����������
    */
    void ResizeAllElemsInCanvas(CControlUI *pControl, bool flag);

    /*   �����пؼ�ӳ����Ļ������*/
    bool ResizeAllElemsInCanvas();
public:
    //ɾ�����ʵ�����
    void OnDeletePen(std::vector<std::string> &vtUuid, CControlUI *pControl);
    CImageToolUI *AddImage(CContainerUI *pContainer, char *url,char *filepath, char *Info);

public:

    ToolsStats GetControlUISatus(CControlUI *pControl);
    //ͨ������ȡԪ��
    CControlUI* GetControlUI(POINT pt);

    void EnableMouseAll();
    void DisableMouseAll();
    
    //ʶ��õ�������
    std::vector<CControlUI*> selected_controls_list_;
    vector<CControlUI*> Search(RECT selct_rc);
    //����ʶ�𵽵�Ԫ�ص��ƶ�
    bool SetSelectedToolsOffset(int offset_x, int offset_y, RECT border);
    //��ӿؼ����ؼ�ѡ���б�
    void AddToSelectedList(CControlUI* control);
    //�Ƴ��ؼ���ѡ���б���
    void RemoveFromSelectedList(CControlUI* control);
    //�Ƴ����пؼ���ѡ���б���
    void ClearSelectedList();
    //��ȡѡ���б��пؼ�����
    int GetSelectedListCount();
    //ѡ�����������пؼ�
    void SelectControlsInRect(RECT rect);
    //�ؼ��Ƿ�ѡ��
    bool IsControlSelected(CControlUI* control);
    //��������ѡ�пؼ�״̬
    void UpdateSelectedListStatus();
    //���µ����ؼ�״̬��������UI�ı�
    bool SetControlUIStatus(CControlUI *pControl, ToolsStats status);
    //��ȡѡ�е�ͼ��
    std::vector<CControlUI*> GetSelectedControlsList();
    //��ȡ����ѡ�пؼ�����߿�
    RECT GetSelectedControlsBorder();



    //���л�״̬�ı��С����
    Json::Value MarshalModifiedControls();
    //�����л�״̬�ı��С���ߣ����������ı�״̬
    bool UnMarshalModifiedControls(Json::Value controls);

    //���л���ɾ����С����
    Json::Value MarshalDeletedControls();
    //�����л���ɾ����С����
    bool UnMarshalDeletedControls(Json::Value controls);


    //���л����е�С���ߣ����������ֳ�
    Json::Value MarshalAllTools();
    //�����л�����С���ߣ������ָ��ֳ�
    bool UnMarshalAllTools(Json::Value& root);

    void OnControlChanged();

    std::list<CControlUI*> GetCurrentPageControls();

    Json::Value GetPageGraphics( int page_id);

    PageListType page_list_;
    

};