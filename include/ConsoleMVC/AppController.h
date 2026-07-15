#pragma once

#include "ConsoleMVC/ConsoleView.h"
#include "ConsoleMVC/SampleController.h"
#include "ConsoleMVC/MonitoringController.h"

namespace cmvc {

class AppController {
public:
    // Runs the main menu loop until the user chooses to exit.
    void Run();

private:
    ConsoleView m_view;
    SampleController m_sampleController;
    MonitoringController m_monitoringController;
};

}
