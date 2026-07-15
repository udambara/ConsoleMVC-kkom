#pragma once

#include "ConsoleMVC/ConsoleView.h"
#include "DataPersistence/SampleRepository.h"
#include "DataPersistence/OrderRepository.h"

namespace cmvc {

class SampleController {
public:
    // Runs the sample management submenu loop until the user chooses to go back.
    void Run();

private:
    dp::SampleRepository m_sampleRepo;
    dp::OrderRepository m_orderRepo;
    ConsoleView m_view;

    void HandleRegister();
    void HandleList();
    void HandleSearch();
    void HandleGenerateDummyData();
};

}
