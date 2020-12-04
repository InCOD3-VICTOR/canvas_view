#pragma once
#include "canvas_view.h"
#include <windows.h>
class MainCanvas;

class CanvasViewImpl:
    public CanvasView
{
public:
    CanvasViewImpl(void* hwnd, Delegate* delegate = nullptr);
    ~CanvasViewImpl();

public:
    //��������
    bool CreateCanvas(int width = 0, int height = 0) override;
    
    //�������λ�ô�С
    bool SetCanvasViewPos(int x, int y, int width, int height) override;

    //�������û�����С
    void ResetCanvas(int width, int height) override;

    void SetPenColor(DWORD color)  override;

    void SetPenSize(int pen_size) override;

    long GetCanvasViewHwnd() override;

public:

    void SelectTools(ToolTypes tool_type) override;

    //��������ƫ����
    void SetOffset(int offsety, bool scroll = true) override;

    void AddImage(char *url, char *filepath, char *info) override;

    void PageTo(int page) override;

    void Hide() override;
    void Show() override;

    void UnMarshal(std::string grapics_data) override;
    std::string Marshal() override;

    void ChangeControls(ChangeType type,std::string change_infos) override;
    void SetEditable(bool enable) override;
private:
    
    void Init();
    HWND hwnd_;
    Delegate* delegate_;
    MainCanvas* main_canvas_;

};