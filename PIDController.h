//
// Created by Stanislav Olekhnovich on 08/08/2017.
//

#ifndef PID_PIDCONTROLLER_H
#define PID_PIDCONTROLLER_H



#include "ControlData.h"


class PIDController
{
public:
    PIDController(double tauP, double tauD, double tauI) :
            tauP(tauP), tauD(tauD), tauI(tauI), previousCTE(.0),
            cteSum(.0), previousTimestamp(.0) {}

    double CalculateSteeringAngle(ControlData controlData);
private:
    double tauP;
    double tauD;
    double tauI;
    double previousTimestamp;
    double previousCTE;
    double cteSum;
};


#endif //PID_PIDCONTROLLER_H
