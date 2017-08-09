//
// Created by Stanislav Olekhnovich on 08/08/2017.
//

#ifndef PID_CONTROLDATA_H
#define PID_CONTROLDATA_H

struct ControlData
{
    ControlData(double CTE, double Speed, double SteeringAngle) : CTE(CTE), Speed(Speed),
                                                                  SteeringAngle(SteeringAngle) {}

    double CTE;
    double Speed;
    double SteeringAngle;
};

#endif //PID_CONTROLDATA_H
