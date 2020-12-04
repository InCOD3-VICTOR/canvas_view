#pragma once

typedef unsigned long DWORD;

enum ToolTypes
{
    UNKNOW = -1,
    RECTANGLE,//����
    ELLIPSE, //��Բ
    LINE, //ֱ��
    ARROW, //��ͷ
    POLYGON,
    TEXT, //�ı�
    TRIANGLE, //������
    DAIMOND, //����
    IMAGE, //ͼƬ
    PENCILE, //�ʼ�
    ERASER,//��Ƥ
    NORMAL, //��ѡ ��ʱ����¼�������
    SELECT, //ѡ�񹤾�
    CANVAS,//����ģʽ�»����굱��Ǧ�ʣ�ͬʱ�ص��ʼ���Ϣ
};

enum PenState  //���16��
{
    PEN_STATE_UP = 0,  //���ڱ�־�Ǵ�����ֹ������λ��PEN_SCROLL
    PEN_STATE_DOWN, 
    PEN_STATE_HOVER,
    PEN_STATE_SCRLL,    //��������
    PEN_STATE_EREASE,

};

struct InnerPenInfo
{
    PenState  state;
    int          x;
    int          y;
    DWORD       ts;
    InnerPenInfo()
    {
        state = PEN_STATE_HOVER;
        x = 0;
        y = 0;
        ts = 0;

    }
};
enum ChangeType
{  
    ADD_TYPE,    //���
    MODEFY_TYPE, //�޸�
    DELETE_TYPE,  //ɾ��
};

enum ToolsStats{

    TOOLS_NORMAL,   //��̬
    TOOLS_HOVER,    //ѡ�п��Խ����ƶ� ������������¼�
    TOOLS_EDITABLE, //�ɱ༭��״̬  
    TOOLS_SELECTED, //�����������¼�
    TOOLS_DELETE    //ɾ��״̬
};


struct ImageInfo
{
    int type; //0 ���Ҫ�ص� 1 ��Ӳ���Ҫ�ص� 
    char *uuid;
    int  x;
    int  y;
    int  width;
    int  height;
    char *url;
    char *localpath;
    ImageInfo()
    {
        x = 0;
        y = 0;
        width = 100;
        height = 100;
        url = nullptr;
        localpath = nullptr;

    }
};