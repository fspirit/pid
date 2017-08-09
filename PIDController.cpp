//
// Created by Stanislav Olekhnovich on 08/08/2017.
//

#include <ctime>
#include <cmath>
#include <iostream>

#include "PIDController.h"

double PIDController::CalculateSteeringAngle(ControlData controlData)
{

    double currentTimestamp = clock();
    double dt = (currentTimestamp - previousTimestamp) / CLOCKS_PER_SEC;
    previousTimestamp = currentTimestamp;

    std::cout << "dt = " << dt<< std::endl;

//    TotalCte_ += cte;

    double cte = controlData.CTE;
    cteSum += cte;
    std::cout << -tauP * cte << " " << - tauD * (cte - previousCTE) << " " << - tauI * cteSum << std::endl;
    double steer = - tauP * cte - tauD * (cte - previousCTE) - tauI * cteSum;
    previousCTE = cte;

    return steer;

//    std::cout << "CTE = " << controlData.CTE << " Angle = " << controlData.SteeringAngle << std::endl;
//
//    double pError = - tauP * controlData.CTE;
//
//    std::cout << "pError = " << pError << std::endl;
//
//    double dError = - tauD * (controlData.CTE - previousCTE);
//    previousCTE = controlData.CTE;
//
//    std::cout << "dError = " << dError << std::endl;
//
//    cteSum += controlData.CTE;
//    double iError = - tauI * cteSum;
//
//    std::cout << "iError = " << iError << std::endl;
//
//    double result = pError + dError + iError;
//
//    if (result > 1.0) result = 1.0;
//    if (result < -1.0) result = -1.0;
//
//    std::cout << "steering = " << result << std::endl;

//    return result;
}
