//
// Created by Stanislav Olekhnovich on 08/08/2017.
//

#include "PIDController.h"

double PIDController::CalculateSteeringAngle(ControlData controlData)
{
    double cte = controlData.CTE;
    cteSum += cte;
    double steer = - tauP * cte - tauD * (cte - previousCTE) - tauI * cteSum;
    previousCTE = cte;

    return steer;
}
