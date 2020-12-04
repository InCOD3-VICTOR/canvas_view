#pragma once

// Transform from world to display coordinates.
class CoordinateSystem
{
public:
    CoordinateSystem();
    //ĿǰΪ�ȱ����ţ�ֻ�������
    void Rescale();
    double GetSacle();

    void SetWorldSize(double x, double y);
    void SetDisplaySize(double x, double y);

    void ComputeWorldToDisplay(double x, double y, double display[2]);
    void ComputeDisplayToWorld(double x, double y, double world[2]);


    void GetWorldSize(double world_size[2]);
    void GetDisplaySize(double display_size[2]);

    void SetOffset(double offset );
    double GetOffset();

private:
    double world_[2];
    double display_[2];
    double scale_;
    double offset_y_;

};