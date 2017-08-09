#include <uWS/uWS.h>
#include "json.hpp"

#include "WebSocketMessageHandler.h"

using std::string;
using std::cout;
using std::endl;
using std::cerr;

// 0.06, 0.000125, 0.6
const double TauP = 0.09;
const double TauD = 3.5;
const double TauI = 0.001;

int main(int argc, char * argv[])
{
    uWS::Hub h;

    PIDController pidController(TauP, TauD, TauI);

    WebSocketMessageHandler handler(pidController);

    h.onMessage([&handler](uWS::WebSocket<uWS::SERVER> ws,
                           char * data,
                           size_t length,
                           uWS::OpCode opCode)
                {
                    if (length == 0)
                        return;

                    string message (data, length);
                    handler.HandleMessage(message, ws);
                });

    h.onConnection([&h](uWS::WebSocket<uWS::SERVER> ws, uWS::HttpRequest req)
                   {
                       cout << "Connected" << endl;
                   });

    h.onDisconnection([&h](uWS::WebSocket<uWS::SERVER> ws, int code, char * message, size_t length)
                      {
                          ws.close();
                          cout << "Disconnected" << endl;
                      });

    const int port = 4567;
    if (h.listen(port))
        cout << "Listening to port " << port << endl;
    else
        cerr << "Failed to listen to port" << endl;

    h.run();
}